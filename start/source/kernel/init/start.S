#include "os_cfg.h"

    .text
    .extern kernel_init
    .global _start 
    .extern init_main

    # void start (boot_info_t * boot_info)
_start:

    # 取出boot_info到 eax中

    # push %ebp
    # mov %esp, %ebp
    # mov 0x8(%ebp),%eax

    # 第一种方法
    # push %ebp
    # mov %esp, %ebp
    # mov 0x8(%ebp), %eax
    # push %eax

    # 第二种方法
    # mov 4(%esp), %eax
    # push %eax

    # 第三种方法
    push 4(%esp)

    # kernel_init(boot_info)
    call kernel_init


    jmp $KERNEL_SELECTOR_CS, $gdt_reload

gdt_reload:
# 数据段选择子的加载
    mov $KERNEL_SELECTOR_DS, %ax
	mov %ax, %ds
	mov %ax, %ss
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs


    mov $(stack+KERNEL_STACK_SIZE) ,%esp  // BTD
    jmp init_main


    .bss
.comm stack,KERNEL_STACK_SIZE  // BTD


.macro exception_handler name num with_err_code

    .text
    .extern do_handler_\name
    .global exception_handler_\name

exception_handler_\name:

# 压入0表示没有错误码
    .if \with_err_code == 0
        push $0
    .endif

    # 压栈
    push $\num
    pusha
    push %ds
    push %es
    push %fs
    push %gs
    push %esp
    call do_handler_\name

    # 出栈
    add $(1*4),%esp
    pop %gs
    pop %fs
    pop %es
    pop %ds
    popa
# 指向EIP
    add $(2*4),%esp

    iret

.endm

exception_handler unknown,-1,0
exception_handler divider,0,0



    
