#include "cpu/irq.h"
#include "cpu/cpu.h"
#include "comm/cpu_instr.h"
#include "os_cfg.h"


#define IDE_TABLE_NR  128


void exception_handler_unknown(void);

static void do_default_handler(exception_frame_t * frame,const char * message) {
    for(;;){}
}


void do_handler_unknown(exception_frame_t * frame){

    do_default_handler(frame,"unknown exception");

}


static gate_desc_t idt_table[IDE_TABLE_NR];


void irq_init(void){ 
    for(int i = 0;i < IDE_TABLE_NR; i++){
        gate_desc_set(idt_table + i, KERNEL_SELECTOR_CS, (uint32_t)exception_handler_unknown, 
        GATE_TYPE_IDT | GATE_P_PRESENT | GATE_DPL0);
    }

    lidt((uint32_t)idt_table,sizeof(idt_table));
}

