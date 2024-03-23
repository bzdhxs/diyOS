#ifndef CPU_INSTR_H
#define CPU_INSTR_H


static inline uint8_t inb(uint16_t port){
    // inb al,dx  从I/O端口dx 读取一个字节
    uint8_t rv; 
    __asm__ __volatile__(
        "inb %[p],%[v]":[v]"=a"(rv):[p]"d"(port)
    );
    return rv;
}

static inline void outb(uint16_t port,uint8_t data){
    // outb al,dx  向I/O端口al ,写入一个字节(dx) data
    __asm__ __volatile__(
        "outb %[v],%[p]"::[p]"d"(port),[v]"a"(data)
    );
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
        uint32_t start15_0;
        uint32_t start32_16;
    }gdt;
    
    gdt.start32_16 = start >> 16;
    gdt.start15_0 = start & 0xffff;
    gdt.limit = size - 1;

    __asm__ __volatile__("lgdt %[g]"::[g]"m"(gdt));
}

#endif // CPU_INSTR_H