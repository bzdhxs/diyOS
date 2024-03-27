 /*
 * 自己动手写操作系统
 *
 * 32位引导代码
 * 二级引导，负责进行硬件检测，进入保护模式，然后加载内核，并跳转至内核运行 
 */



#include "loader.h"
#include "comm/elf.h"
/**
    使用LBA48位模式读取磁盘
	将内核数据存入 从100号磁盘开始 读入到内存0x100000
    参数设置参考手册
*/
static void read_disk(int sector,int sector_count,uint8_t *buf){
    outb(0x1F6, (uint8_t) (0xE0));

	outb(0x1F2, (uint8_t) (sector_count >> 8));
    outb(0x1F3, (uint8_t) (sector >> 24));		// LBA参数的24~31位
    outb(0x1F4, (uint8_t) (0));					// LBA参数的32~39位
    outb(0x1F5, (uint8_t) (0));					// LBA参数的40~47位

    outb(0x1F2, (uint8_t) (sector_count));
	outb(0x1F3, (uint8_t) (sector));			// LBA参数的0~7位
	outb(0x1F4, (uint8_t) (sector >> 8));		// LBA参数的8~15位
	outb(0x1F5, (uint8_t) (sector >> 16));		// LBA参数的16~23位

	outb(0x1F7, (uint8_t) 0x24);  // 发送命令


	// 读取数据
	uint16_t *data_buf = (uint16_t*) buf;
	while (sector_count-- > 0) {
		// 每次扇区读之前都要检查，等待数据就绪 根据手册中的Status register 来判断 取出 DRQ
		while ((inb(0x1F7) & 0x88) != 0x8) {}

		// 读取并将数据写入到缓存中
		for (int i = 0; i < SECTOR_SIZE / 2; i++) {
            // inw指令  0X1F0:位数据寄存器
			*data_buf++ = inw(0x1F0);
		}
	}
}


/**
 * 解析elf文件，提取内容到相应的内存中
 * https://wiki.osdev.org/ELF
 * @param file_buffer
 * @return
 */

// file_buffer = SYS_KERNEL_LOAD_ADDR = 0x100000 

static uint32_t reload_elf_file (uint8_t * file_buffer){
	// 读取的只是ELF文件，不像BIN那样可直接运行，需要从中加载出有效数据和代码
    // 简单判断是否是合法的ELF文件

	Elf32_Ehdr * elf_hdr = (Elf32_Ehdr *)file_buffer;
	
	if((elf_hdr->e_ident[0] != 0x7f) || (elf_hdr->e_ident[1] != 'E' || (elf_hdr->e_ident[2] != 'L') 
	|| (elf_hdr->e_ident[3] != 'F'))){
		return 0;
	}

	// 然后从中加载程序头，将内容拷贝到相应的位置
	for(int i = 0 ;i < elf_hdr->e_phnum;i++){
		Elf32_Phdr * phdr = (Elf32_Phdr *)(file_buffer +elf_hdr->e_phoff) + i;
		
		// 不是可加载的类型 就不往内存里拷贝
		if(phdr->p_type != PT_LOAD){
			continue;
		}

	// ELF文件加载到内存 
		uint8_t *src = file_buffer + phdr->p_offset;
		uint8_t *dest = (uint8_t *) phdr->p_paddr;
		for(int j = 0;j<phdr->p_filesz;j++ ){
			*dest++ = *src++;
		}

		dest = (uint8_t *)phdr->p_paddr + phdr->p_filesz;
		for(int j  = 0;j < phdr->p_memsz - phdr->p_filesz;j++){
			*dest++ = 0;
		}

		return elf_hdr ->e_entry;


	}
}


static void dile(int code){
	for(;;){}
}



void load_kernel(void){
	// 读取的扇区数一定要大一些,保不准kernel.elf大小会变得很大
	// 从100号扇区开始 读500个扇区
    read_disk(100,500,(uint8_t *)SYS_KERNEL_LOAD_ADDR);
     // 解析ELF文件，并通过调用的方式，进入到内核中去执行，同时传递boot参数
	 // 临时将elf文件先读到SYS_KERNEL_LOAD_ADDR处，再进行解析
	uint32_t kernel_entry = reload_elf_file((uint8_t *)SYS_KERNEL_LOAD_ADDR);
	// 死机
	if(!kernel_entry){
		dile(-1);
	}
	// 转换为函数指针，然后跳进内核
	((void (*)(boot_info_t *))kernel_entry)(&boot_info);
    for(;;){}
}