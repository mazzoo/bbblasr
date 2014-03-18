MEMORY { .sram : ORIGIN = 0x40200800, LENGTH = (54 * 1024) }
MEMORY { .sdram : ORIGIN = 0x80000000, LENGTH = 0x80000 }
OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_reset)
SECTIONS
{
 .text :
 {
  _reset = .;
  startup.o (INTERRUPT_VECTOR)
  *(.text*)
 } >.sdram

 . = ALIGN(4);
 .rodata : { *(SORT_BY_ALIGNMENT(.rodata*)) } >.sdram

 . = ALIGN(4);
 .data : { *(SORT_BY_ALIGNMENT(.data*)) } >.sdram

 . = ALIGN(4);
 __image_copy_end = .;
 _end = .;

 .bss :
 {
  . = ALIGN(4);
  __bss_start = .;
  *(.bss*)
  . = ALIGN(4);
  __bss_end = .;
 } >.sdram

 . = ALIGN(8);
 . = . + 0x1000; /* 4kB of irq stack memory */
 top_of_irq_stack = .;

 . = ALIGN(8);
 . = . + 0x1000; /* 4kB of fiq stack memory */
 top_of_fiq_stack = .;

 . = ALIGN(8);
 . = . + 0x1000; /* 4kB of stack memory */
 top_of_stack = .;

}
