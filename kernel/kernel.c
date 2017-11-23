/**
 * @file 		kernel.c
 * @brief 		Entry point of kernel.
 *
 * @author 		Steven Liatti
 * @author 		Raed Abdennadher
 * @bug 		No known bugs.
 * @date 		November 3, 2017
 * @version		1.0
 */

#include "multiboot.h"
#include "gdt.h"
#include "screen.h"
#include "pic.h"
#include "timer.h"
#include "idt.h"
#include "x86.h"
#include "keyboard.h"
#include "test.h"

/**
 * @brief entry point of kernel. Mode test available
 * 
 * @param boot_info structure with informations about boot process
 */
void kernel_entry(multiboot_info_t* boot_info) {
	init_scr();
	pic_init();	
	gdt_init();
	idt_init();
	timer_init(75);
	sti();

	#ifdef TEST_SCREEN
	test_screen();
	#elif TEST_TIMER
	test_timer();
	#else

	printf("Screen has been initialized.\n");
	printf("PIC has been initialized.\n");	
	printf("GDT has been initialized.\n");
	printf("IDT has been initialized.\n");
	printf("Timer has been initialized.\n");
	printf("Memory upper : %d\n", boot_info->mem_upper);
	
	while (1) {
		uchar c = getc();
		if (c == 'Q') {
			printf("\nShutdown");
			halt();
		}
		else {
			printf("%c", c);
		}
	}

	#endif
}
