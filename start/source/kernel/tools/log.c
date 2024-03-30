#include "tools/log.h"
#include "comm/cpu_instr.h"


#define COM1_PORT 0x3f8

void log_init(void) {
    
    // 初始化串行接口
    outb(COM1_PORT + 1, 0x00);
    outb(COM1_PORT + 3, 0x80);
    outb(COM1_PORT + 0, 0x3);
    outb(COM1_PORT + 1, 0x00);
    outb(COM1_PORT + 3, 0x03);
    outb(COM1_PORT + 2, 0xc7);
    outb(COM1_PORT + 4, 0x0f);

}

void log_printf(const char * fmt,...) {

    const char * p = fmt;
    while(*p != '\0') {
        while (inb(COM1_PORT + 5) & (1 << 6) == 0);
        outb(COM1_PORT,*p++);
    }

// 变列
    outb(COM1_PORT,'\r');
// 变行    
    outb(COM1_PORT,'\n');

}