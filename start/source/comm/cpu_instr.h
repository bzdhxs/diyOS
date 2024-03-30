#ifndef CPU_INSTR_H
#define CPU_INSTR_H
#include "types.h"

static inline uint8_t inb(uint16_t port) {
    // inb al,dx  从I/O端口dx 读取一个字节
    uint8_t rv; 
    __asm__ __volatile__("inb %[p],%[v]":[v]"=a"(rv):[p]"d"(port));
    return rv;
}

static inline void outb(uint16_t port,uint8_t data){
    // outb al,dx  向I/O端口al ,写入一个字节(dx) data
    __asm__ __volatile__("outb %[v],%[p]"::[p]"d"(port),[v]"a"(data));
}
static inline uint16_t inw(uint16_t port){
    // in ax dx
    uint16_t rv; 
    __asm__ __volatile__("in %[p],%[v]":[v]"=a"(rv):[p]"d"(port));
    return rv;
}

static inline void cli(void){
    __asm__ __volatile__("cli");    
}

static inline void sti(void){
    __asm__ __volatile__("sti");    
}


static inline void lgdt(uint32_t start,uint32_t size){

    struct {
        uint16_t limit;
        uint16_t start15_0;
        uint16_t start32_16;
    }gdt;
    
    gdt.start32_16 = start >> 16;
    gdt.start15_0 = start & 0xffff;
    gdt.limit = size - 1;

    __asm__ __volatile__("lgdt %[g]"::[g]"m"(gdt));
}


static inline uint32_t read_cr0(void){
    uint32_t cr0;
    __asm__ __volatile__("mov %%cr0, %[v]":[v]"=r"(cr0));
    return cr0;
}


static inline void write_cr0(uint32_t v){

    __asm__ __volatile__("mov %[v],%%cr0"::[v]"r"(v));
}


static inline void far_jump(uint32_t selector,uint32_t offset){
    uint32_t addr[] = {offset,selector};
    __asm__ __volatile__("ljmpl *(%[a])"::[a]"r"(addr));
}



static inline void lidt(uint32_t start,uint32_t size){

    struct {
        uint16_t limit;
        uint16_t start15_0;
        uint16_t start32_16;
    }idt;
    
    idt.start32_16 = start >> 16;
    idt.start15_0 = start & 0xffff;
    idt.limit = size - 1;

    __asm__ __volatile__("lidt %[g]"::[g]"m"(idt));
}

static inline void hlt (void) {
    __asm__ __volatile__("hlt");
}

#endif // CPU_INSTR_H