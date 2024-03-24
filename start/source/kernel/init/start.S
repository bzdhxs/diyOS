
    .text
    .extern kernel_init
    .global _start


    # void start (boot_info_t * boot_info)
_start:

    # 取出boot_info到 eax中
    push %ebp
    mov %esp, %ebp
    mov 0x8(%ebp),%eax



    # kernel_init(boot_info)
    push %eax
    call kernel_init
    jmp .