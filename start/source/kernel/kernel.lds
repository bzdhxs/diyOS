/* 参考文档： https://ftp.gnu.org/old-gnu/Manuals/ld-2.9.1/html_chapter/ld_3.html */
/* 链接脚本*/

SECTIONS
{
    . = 0x10000;

	.text : {
		*(.text)
	} 

	.rodata : {
		*(.rodata)
	}
	.data : {
		*(.data)
	}
	.bss : {
		*(.bss)
	}

	PROVIDE(mem_free_start = .);
}
