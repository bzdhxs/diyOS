/**
 * 内核初始化以及测试代码
 */
#include "comm/boot_info.h"
#include "init.h"
#include "cpu/cpu.h"
#include "cpu/irq.h"


/**
 * 内核入口
 */
void kernel_init (boot_info_t * boot_info){
    cpu_init();
    irq_init();
}

void init_main(void) {

    int a = 3 / 0;
    for(;;){}
}