/**
 * 自己动手写操作系统
 * 16位引导代码
 * 二级引导，负责进行硬件检测，进入保护模式，然后加载内核，并跳转至内核运行
 */


// 16位代码，必须加上放在开头，以便有些io指令生成为32位
__asm__(".code16gcc");

#include "loader.h"

boot_info_t boot_info;			// 启动参数信息  用来存放检测出的内存信息

static void show_msg(const char *msg){
    char c;

    while((c = *msg++) != '\0'){
        //使用内联汇编显示字符串
        __asm__  __volatile__ (
            "mov $0xe,%%ah\n\t"
            "mov %[ch],%%al\n\t"
            "int $0x10"::[ch]"r"(c)
        );
    }
}

// 参考：https://wiki.osdev.org/Memory_Map_(x86)
// 1MB以下比较标准, 在1M以上会有差别
// 检测：https://wiki.osdev.org/Detecting_Memory_(x86)#BIOS_Function:_INT_0x15.2C_AH_.3D_0xC7

static void detect_memory(void){


    uint32_t contID = 0;
    SMAP_entry_t smap_entry;
    int signature, bytes;

    show_msg("try to detect memory:");

    boot_info.ram_region_count = 0;
    for(int i = 0;i < BOOT_RAM_REGION_MAX;i++){
        
        SMAP_entry_t *entry = &smap_entry;

      __asm__ __volatile__("int  $0x15"
			: "=a"(signature), "=c"(bytes), "=b"(contID)
			: "a"(0xE820), "b"(contID), "c"(24), "d"(0x534D4150), "D"(entry));

        if(signature != 0x534D4150){
            show_msg("failed\n\t");
            return;
        }
        
        // todo: 20字节
		if (bytes > 20 && (entry->ACPI & 0x0001) == 0){
			continue;
		}


        if (entry->Type == 1){
            boot_info.ram_region_cfg[boot_info.ram_region_count].start = entry->BaseL;
            boot_info.ram_region_cfg[boot_info.ram_region_count].size = entry->LengthL;
            boot_info.ram_region_count++;
        }

        // EBX=0表明读取完毕
        if (contID == 0){
            break;
        }

        show_msg("ok.\r\n");

    }
}

// GDT表。临时用
uint16_t gdt_table[][4] = {
    {0,0,0,0},
    {0xffff,0X0000,0X9a00,0X00cf},
    {0xffff,0X0000,0X9200,0X00cf},
};


// 进入保护模式
static void enter_protect_mode(void){
    // 关中断
    cli();
    // 开启A20地址线，使得可访问1M以上空间
    // 使用的是Fast A20 Gate方式，见https://wiki.osdev.org/A20#Fast_A20_Gate
    uint8_t v = inb(0x92);
    outb(0x92,v | 0x2);

    lgdt((uint32_t)gdt_table,sizeof(gdt_table));

//  开启cr0 
    uint32_t cr0 = read_cr0();
    
    write_cr0(cr0 | (1<<0));


// far_jump 跳转到 start.S 的 protect_mode_entry
    far_jump(8,(uint32_t)protect_mode_entry);

}


void loader_entry(void){
    show_msg(".......loading........\n\r");
    detect_memory();
    enter_protect_mode();
    for(;;){}
}