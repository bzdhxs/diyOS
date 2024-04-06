/*
*    与x86的体系结构相关的接口及参数
*/
#ifndef CPU_H
#define CPU_H
#include "comm/types.h"

// GDT宏定义
#define SEG_G				(1 << 15)		// 设置段界限的单位，1-4KB，0-字节
#define SEG_D				(1 << 14)		// 控制是否是32位、16位的代码或数据段
#define SEG_P_PRESENT	    (1 << 7)		// 段是否存在

#define SEG_DPL0			(0 << 5)		// 特权级0，最高特权级
#define SEG_DPL3			(3 << 5)		// 特权级3，最低权限

#define SEG_S_SYSTEM		(0 << 4)		// 是否是系统段，如调用门或者中断
#define SEG_S_NORMAL		(1 << 4)		// 普通的代码段或数据段

#define SEG_TYPE_CODE		(1 << 3)		// 指定其为代码段
#define SEG_TYPE_DATA		(0 << 3)		// 数据段

#define SEG_TYPE_RW			(1 << 1)		// 是否可写可读，不设置为只读

// IDT宏定义
#define GATE_TYPE_IDT		(0xE << 8)		// 中断32位门描述符
#define GATE_P_PRESENT		(1 << 15)		// 是否存在
#define GATE_DPL0			(0 << 13)		// 特权级0，最高特权级
#define GATE_DPL3			(3 << 13)		// 特权级3，最低权限

#pragma pack(1)

//  GDT段描述符
// 参考 INTEL325384 -- 3-10 Vol. 3A  --   Figure 3-8.  Segment Descripto
typedef struct _segment_desc_t{
    uint16_t limit15_0;
    uint16_t base15_0;
    uint8_t base23_16;
    uint16_t attr;
    uint8_t base31_24;
}segment_desc_t;

/*
 * 调用门描述符
 */

typedef struct _gate_desc_t {
	uint16_t offset15_0;
	uint16_t selector;
	uint16_t attr;
	uint16_t offset31_16;
}gate_desc_t;


/**
 * tss描述符
 */
typedef struct _tss_t {
    uint32_t pre_link;  //  Contains the segment selector for the TSS of the previous task
    uint32_t esp0, ss0, esp1, ss1, esp2, ss2; // Privilege level-0, -1, and -2 stack pointer fields
    uint32_t cr3; //  Contains the base physical address of the page directory to be used by the task
    uint32_t eip, eflags, eax, ecx, edx, ebx, esp, ebp, esi, edi;  //  General-purpose register fields
    uint32_t es, cs, ss, ds, fs, gs; //  Segment selector fields 
    uint32_t ldt;
    uint32_t iomap; //  I/O Map Base Address
}tss_t;

#pragma pack()

void cpu_init (void);
void segment_desc_set(int selector, uint32_t base, uint32_t limit, uint16_t attr);
void gate_desc_set(gate_desc_t * desc, uint16_t selector, uint32_t offset, uint16_t attr);


#endif