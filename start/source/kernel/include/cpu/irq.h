#ifndef IRQ_H
#define IRQ_H
#include "comm/types.h"


#define IRQ0_DE 0
/**
 * 中断发生时相应的栈结构，暂时为无特权级发生的情况
 */



typedef struct _exception_frame_t{
    // 结合压栈的过程，以及pusha指令的实际压入过程
    uint32_t gs,fs,es,ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t num,error_code;
    uint32_t eip,cs,eflags;

}exception_frame_t;


typedef void(*irq_handler_t)(void);


void irq_init(void);
int irq_install(int irq_num,irq_handler_t handler);


void exception_handler_divider(void);


#endif //IRQ_H