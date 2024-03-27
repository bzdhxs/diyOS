/**
 * 自己动手写操作系统
 * 二级引导，负责进行硬件检测，进入保护模式，然后加载内核，并跳转至内核运行
 *
 */

  	// 16位代码,务必加上
  	.code16
 	.text
	.global _start 
	.extern loader_entry
	
_start:
//;跳转到loader_16 c代码里 完成loader的加载
	jmp  loader_entry

	.code32
	.text
	.global protect_mode_entry
	.extern load_kernel

protect_mode_entry:
	mov $16, %ax
	mov %ax, %ds
	mov %ax, %ss
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	jmp $8, $load_kernel