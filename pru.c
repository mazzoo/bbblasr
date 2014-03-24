
#include "bbblasr_libc.h"
#include "pru.h"
#include "bbblasr_pru0_bin.h"
#include "bbblasr_pru1_bin.h"


void init_pru_clocks(void)
{
  RM_PER_RSTCTRL            &= ~0x00000002;
  PM_PER_PWRSTCTRL          |=  0xee0000eb;
  CM_PER_PRU_ICSS_CLKSTCTRL  =  0;
  CM_PER_PRU_ICSS_CLKCTRL    =  2;
}

void load_pru(int pru_nr)
{
  const unsigned int * PRUcode;
  volatile u32 * PRUiram;
  int copylen;

  if (pru_nr == 0)
  {
    PRUcode =          PRU0_code;
    PRUiram = (vu32 *) PRU0_IRAM;
    copylen = sizeof(PRU0_code);
  }

  if (pru_nr == 1)
  {
    PRUcode =          PRU1_code;
    PRUiram = (vu32 *) PRU1_IRAM;
    copylen = sizeof(PRU0_code);
  }

  bbb_puts("copying 0x");
  puthex32(copylen);
  bbb_puts(" bytes to PRU");
  bbb_putc('0' + pru_nr);
  bbb_puts("\n\r");
  bbb_memcpy32(PRUiram, PRUcode, copylen/4);
}

void start_pru(int pru_nr)
{
  if (pru_nr == 0)
  {
    PRU0_CONTROL = 0x0000800a;
  }
  if (pru_nr == 1)
  {
    PRU1_CONTROL = 0x0000800a;
  }
}

void init_pru(void)
{
  init_pru_clocks();

  load_pru(0);
  load_pru(1);
}


void pru_test(void)
{
  bbb_puts("pru_test()\n\r");

  int i;
  bbb_puts("PRU_DATA_RAM0:\n\r");
  for ( i = 0; i < 8 * 1024 / 4; i++)
  {
    if (! (i%8))bbb_puts("\n\r");
    puthex32(*(PRU_DATA_RAM0+i));
    bbb_putc(' ');
  }
  bbb_puts("\n\r");

  bbb_puts("PRU_DATA_RAM1:\n\r");
  for ( i = 0; i < 8 * 1024 / 4; i++)
  {
    if (! (i%8))bbb_puts("\n\r");
    puthex32(*(PRU_DATA_RAM1+i));
    bbb_putc(' ');
  }
  bbb_puts("\n\r");

  bbb_puts("PRU_SHRD_RAM2:\n\r");
  for ( i = 0; i < 12 * 1024 / 4; i++)
  {
    if (! (i%8))bbb_puts("\n\r");
    puthex32(*(PRU_SHRD_RAM2+i));
    bbb_putc(' ');
  }
  bbb_puts("\n\r");

  bbb_puts("spraying RAM0\n\r");
  for ( i = 0; i < 8 * 1024 / 4; i++)
  {
    *(PRU_DATA_RAM0+i) = i;
  }
  bbb_puts("spraying RAM1\n\r");
  for ( i = 0; i < 8 * 1024 / 4; i++)
  {
    *(PRU_DATA_RAM1+i) = i+1;
  }
  bbb_puts("spraying RAM2\n\r");
  for ( i = 0; i < 12 * 1024 / 4; i++)
  {
    *(PRU_SHRD_RAM2+i) = i+2;
  }
}
