#include "cpu/cpu.h"
#include "os_cfg.h"
#include "comm/cpu_instr.h"
// GDT表第0个表项系统保留不使用
static segment_desc_t gdt_table[GDT_TABLE_SIZE];

//  设置GDT表函数
void segment_desc_set (int selector, uint32_t base, uint32_t limit,uint16_t attr){

    segment_desc_t * desc = gdt_table + selector / sizeof(segment_desc_t);

	// 如果界限比较长，将长度单位换成4KB
    // 方法为将 attr中的 G = 1
	if (limit > 0xfffff) {
		attr |= SEG_G;
		limit /= 0x1000;
	}
    desc->limit15_0 = limit & 0xffff;
    desc->base15_0 = base & 0xffff;
    desc->base23_16 = (base >> 16) & 0xff;
    desc->attr = attr | (((limit >> 16) & 0xf) << 8);
    desc->base31_24 = (base >> 24) & 0xff;

}

void init_gdt(void){
    for(int i = 0;i < GDT_TABLE_SIZE;i++){
        segment_desc_set(i*sizeof(segment_desc_t),0,0,0);
    }

// 设置GDT表中的CS段
// 只能用非一致代码段，以便通过调用门更改当前任务的CPL执行关键的资源访问操作
    segment_desc_set(KERNEL_SELECTOR_CS, 0x00000000, 0xFFFFFFFF,
                     SEG_P_PRESENT | SEG_DPL0 | SEG_S_NORMAL | SEG_TYPE_CODE
                     | SEG_TYPE_RW | SEG_D);

// 设置GDT表中的DS段
    segment_desc_set(KERNEL_SELECTOR_DS, 0x00000000, 0xFFFFFFFF,
                     SEG_P_PRESENT | SEG_DPL0 | SEG_S_NORMAL | SEG_TYPE_DATA
                     | SEG_TYPE_RW | SEG_D);

    lgdt((uint32_t)gdt_table,sizeof(gdt_table));
}

/**
 * 设置门描述符
 */
void gate_desc_set(gate_desc_t * desc, uint16_t selector, uint32_t offset, uint16_t attr) {
	desc->offset15_0 = offset & 0xffff;
	desc->selector = selector;
	desc->attr = attr;
	desc->offset31_16 = (offset >> 16) & 0xffff;
}




void cpu_init (void){
    // 初始化GDT表
    init_gdt();
}