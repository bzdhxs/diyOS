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

/**
 * 内核入口
 */
void kernel_init (boot_info_t * boot_info){
    cpu_init();

    log_init();
    irq_init();
    time_init();
}

static task_t first_task;
static uint32_t init_task_stack[1024];
static task_t init_task;

void init_task_entry(void) {
    
    int count = 0;
    for(;;){
        log_printf("int task: %d",count++);
        task_switch_from_to(&init_task,&first_task);
    }    

}

void init_main(void) {

    log_printf("kernel is running....");
    log_printf("version: %s %s",OS_VERSION,"diyx86os");
    log_printf("%d %d %x %c",123456,-123,0x12345,'a');

    task_init(&init_task, (uint32_t)init_task_entry,(uint32_t)&init_task_stack[1024]);
    task_init(&first_task, 0,0);
    write_tr(first_task.tss_sel); // 初始化任务寄存器 task register

    int count = 0;
    for(;;){
        log_printf("int main: %d",count++);
        task_switch_from_to(&first_task,&init_task);
    }
}