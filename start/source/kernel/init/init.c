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

/**
 * 内核入口
 */
void kernel_init (boot_info_t * boot_info){
    cpu_init();
    log_init();
    irq_init();
    time_init();
}

void init_main(void) {

    // int a = 3 / 0;
    log_printf("kernel is running....");
    log_printf("version: %s",OS_VERSION);

    irq_enable_global();
    for(;;){}
}