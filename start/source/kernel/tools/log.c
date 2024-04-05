#include "tools/log.h"
#include "comm/cpu_instr.h"
#include "tools/klib.h"
#include "stdarg.h" // 取可变参数的值

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
// 支持可变参数
void log_printf(const char * fmt, ...) {

// 缓冲区
    char str_buf[128];
    kernel_memset(str_buf,'\0',sizeof(str_buf));

    va_list args;
    va_start(args,fmt);

    kernel_vsprintf(str_buf,fmt,args);
    va_end(args);

    const char * p = str_buf;
    while(*p != '\0') {
        while (inb(COM1_PORT + 5) & (1 << 6) == 0);
        outb(COM1_PORT,*p++);
    }

// 变列
    outb(COM1_PORT,'\r');
// 变行    
    outb(COM1_PORT,'\n');
}