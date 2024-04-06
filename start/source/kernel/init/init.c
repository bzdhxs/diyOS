/**
 * 内核初始化以及测试代码
 */
#include "comm/boot_info.h"
#include "init.h"
#include "cpu/cpu.h"
#include "cpu/irq.h"
#include "dev/time.h"
#include "tools/log.h"
#include "os_cfg.h"
#include "tools/klib.h"

/**
 * 内核入口
 */
void kernel_init (boot_info_t * boot_info){
    cpu_init();

    log_init();
    irq_init();
    time_init();
}

void init_task_entry(void) {
    
    int count = 0;
    for(;;){
        log_printf("int main: %d",count++);
    }    

}

void init_main(void) {
    log_printf("kernel is running....");
    log_printf("version: %s %s",OS_VERSION,"diyx86os");
    log_printf("%d %d %x %c",123456,-123,0x12345,'a');


    int count = 0;
    for(;;){
        log_printf("int main: %d",count++);
    }
}