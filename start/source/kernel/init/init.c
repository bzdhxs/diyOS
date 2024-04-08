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

void list_test (void) {
    list_t list;

    list_node_t nodes[5];
    list_init(&list);



    for(int i = 0; i < 5; i++) {
        list_node_t * node = nodes + i;
        log_printf("insert first to last: %d,0x%x",i,(uint32_t)node);
        list_insert_first(&list,node);
    }
    log_printf("list: firts=0x%x,last=0x%x,count=%d",
        list_first(&list),list_last(&list),list_count(&list));

    list_init(&list);

    for(int i = 0; i < 5; i++) {
        list_node_t * node = nodes + i;
        log_printf("insert first to last: %d,0x%x",i,(uint32_t)node);
        list_insert_last(&list,node);
    }
    log_printf("list: firts=0x%x,last=0x%x,count=%d",
        list_first(&list),list_last(&list),list_count(&list));
    
    //del first
    for (int i = 0; i < 5; i++) {
        list_node_t * node = list_remove_first(&list);
        log_printf("remove first from list: %d, 0x%x", i, (uint32_t)node);
    }
    log_printf("list: firts=0x%x,last=0x%x,count=%d",
        list_first(&list),list_last(&list),list_count(&list));

    for(int i = 0; i < 5; i++) {
        list_node_t * node = nodes + i;
        log_printf("insert first to last: %d,0x%x",i,(uint32_t)node);
        list_insert_last(&list,node);
    }
    log_printf("list: firts=0x%x,last=0x%x,count=%d",
        list_first(&list),list_last(&list),list_count(&list));
// del 
    for (int i = 0; i < 5; i++) {
        list_node_t * node = nodes + i;
        log_printf("remove first from list: %d, 0x%x", i, (uint32_t)node);
        list_remove(&list, node);
    }
    log_printf("list: first=0x%x, last=0x%x, count=%d", 
        list_first(&list), list_last(&list), list_count(&list));


}


void init_main(void) {

    list_test();
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