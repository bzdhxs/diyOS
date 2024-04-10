/**
 * 内核初始化以及测试代码
 */
#include "comm/boot_info.h"
#include "init.h"
#include "cpu/cpu.h"
#include "cpu/irq.h"
#include "comm/cpu_instr.h"
#include "dev/time.h"
#include "tools/log.h"
#include "os_cfg.h"
#include "tools/klib.h"
#include "core/task.h" 
#include "tools/list.h"

/**
 * 内核入口
 */
void kernel_init (boot_info_t * boot_info){
    cpu_init();
    log_init();
    irq_init();
    time_init();

    task_manager_init();

}

static uint32_t init_task_stack[1024];
static task_t init_task;

void init_task_entry(void) {
    
    int count = 0;
    for(;;){
        log_printf("int task: %d",count++);
        sys_sleep(5000);
    }    

}

void init_main(void) {

    log_printf("kernel is running....");
    log_printf("version: %s %s",OS_VERSION,"diyx86os");
    log_printf("%d %d %x %c",123456,-123,0x12345,'a');

    task_init(&init_task,"init task",(uint32_t)init_task_entry,(uint32_t)&init_task_stack[1024]);
    task_first_init();

    irq_enable_global();
    int count = 0; 
    for(;;){
        log_printf("first main: %d",count++);
        sys_sleep(1000);

    }

}