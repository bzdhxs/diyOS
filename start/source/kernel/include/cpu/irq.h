#ifndef IRQ_H
#define IRQ_H
#include "comm/types.h"


/**
 * 中断发生时相应的栈结构，暂时为无特权级发生的情况
 */
typedef struct _exception_frame_t{
    // 结合压栈的过程，以及pusha指令的实际压入过程
    uint32_t gs,fs,es,ds;
    
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;

    uint32_t eip,cs,eflags;

}exception_frame_t;

void irq_init(void);



#endif //IRQ_H