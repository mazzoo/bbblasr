#include "bbblasr_libc.h"
#include "led.h"
#include "pru.h"
#include "intc.h"
#include "uart.h"

char * banner =
"\
\n\r\
       _     _     _     _\n\r\
      | |__ | |__ | |__ | | __ _ ___ _ __\n\r\
      | '_ \\| '_ \\| '_ \\| |/ _` / __| '__|\n\r\
      | |_) | |_) | |_) | | (_| \\__ \\ |\n\r\
      |_.__/|_.__/|_.__/|_|\\__,_|___/_|\n\r\
\n\r\
  beagle bone black logic analyzer for sigrok\n\r\
\n\r\
\n\r\
"
;

char * help =
"\
  \n\r\
  possible keys:\n\r\
  \n\r\
  1 - toggle LED 1\n\r\
  2 - toggle LED 2\n\r\
  3 - toggle LED 3\n\r\
  4 - toggle LED 4\n\r\
  n - restart PRU0\n\r\
  m - restart PRU1\n\r\
  q - restart ARM application\n\r\
  i - init both PRUs simultaneously\n\r\
  p - memtest on PRU code and data RAM\n\r\
  x - enter ARM undef mode\n\r\
  d - enter ARM data abort mode\n\r\
  t - show temperature\n\r\
  . - reset the ARM (actually only jumps to reset vector in ROM, registers are not reset!)\n\r\
  \n\r\
  h - print this help\n\r\
  \n\r\
"
;

void init_exception_handlers(void)
{
  asm volatile(
      /* set our exception vectors */
      "ldr r0, =0x80000000\n\t"
      "mcr p15, 0, r0, c12, c0, 0\n\t"
  );
}

void init_gpio(void)
{
  *(vu32 *)(GPIO1_BASE+GPIO_OE) &= ~(LED0_BIT | LED1_BIT | LED2_BIT | LED3_BIT);
}

void init_leds(void)
{
  led_set(0);
  led_set(1);
  led_set(2);
  led_set(3);
}


void init_irqs(void)
{
  enable_irqs();
  enable_fiqs();

  /* BBB pushputton S2 */
  * INTC_MIR_CLEAR1 = 0x01; /* GPIO2 interrupt 32 */

  /* PRU0 & PRU1 interrupts */
  * INTC_MIR_CLEAR0 = 0x3 << 26;

  /* global enable PRU interrupts */
  PRU_INTC_GER    =     1;

#if 1 // FIXME why the fuck we need this?
  int i;
  for (i=0x000; i<0x400;i++)
  {
    PRU_INTC_HIER   = i;
    PRU_INTC_HIEISR = i;
    PRU_INTC_EISR   = i;
  }
#else
  u8 v[] = { 0,1,2,3,  4,5,6,7,8,9, 18,19,20,21,22,23,0};
  u8 * vp = v;
  while (*vp)
  {
    PRU_INTC_HIER   = *vp;
    PRU_INTC_HIEISR = *vp;
    PRU_INTC_EISR   = *vp;
    vp++;
  }
#endif

  /* 1:1 mapping */
  PRU_INTC_HMR1   = 0x0b0a0908;

  PRU_INTC_CMR4   = 0x03020100;
  PRU_INTC_CMR5   = 0x07060504;
}

void init_uart(void)
{
  * UART_IER = 0x01;
  * INTC_MIR_CLEAR2 = 0x1 << 8; /* UART0 interrupts, 72 */
}

void init_buttons(void)
{
  BUTTON_S2_IRQSTATUS_SET_0 |= BUTTON_S2_BIT;
  BUTTON_S2_RISINGDETECT    |= BUTTON_S2_BIT;
  BUTTON_S2_FALLINGDETECT   |= BUTTON_S2_BIT;
}

void init(void)
{
  init_gpio();
  init_leds();
  init_exception_handlers();
  init_pru();
  init_irqs();
  init_uart();
  init_buttons();
}

void bandgap(void)
{
  BANDGAP_CTRL = 0x00; /* reset digital output */
  BANDGAP_CTRL = 0x08; /* reset digital output */

  BANDGAP_CTRL = 0x18; /* start conversion */

  delay_ms(1);

  u32 val;

  while ( (val = BANDGAP_CTRL) & 0x02 );

  BANDGAP_CTRL = 0x08; /* reset digital output */

  val >>= 8;
  bbb_puts("temperature: ");
  putdec8(val);
  bbb_puts(" degree Celsius\r\n");
}

int main(void)
{
  while (1)
  {
    init();
    bbb_puts(banner);
    bbb_puts("please choose  [1234nmqipxdt.h]  h for help\r\n");

    char ch;
    int cmd_q = 0;
    while (!cmd_q)
    {
      ch = bbb_getc();
      switch (ch)
      {
        case 'h':
          bbb_puts(help);
          break;
        case 'q':
          cmd_q = 1;
          break;
        case 'b':
          if ( BUTTON_S2 & BUTTON_S2_BIT )
          {
            bbb_puts("S2 is up\r\n");
          }else{
            bbb_puts("S2 is down\r\n");
          }
          break;
        case '1':
          led_toggle(0);
          break;
        case '2':
          led_toggle(1);
          break;
        case '3':
          led_toggle(2);
          break;
        case '4':
          led_toggle(3);
          break;
        case 'p':
          pru_test();
          break;
        case 'i':
          init_pru();
          break;
        case 'n':
          start_pru(0);
          break;
        case 'm':
          start_pru(1);
          break;
        case 't':
          bandgap();
          break;
        case 'x':
          asm volatile (".align 5\n\t");
          asm volatile (".word 0xa000f7f0\n\t"); // enter undef mode (undefined instruction)
          break;
        case 'd':
          bbb_putc(*(char *)0); // data abort
          break;
        case '.':
          // FIXME this is not a reset
          asm volatile ("b 0x00020000\n\t"); // jump to ROM reset vector
          break;
        default:
          bbb_puts("unknown command >");
          bbb_putc(ch);
          bbb_puts("<\r\n");
          break;
      }
    }
  }
  return 0;
}

int isr_pru0(void)
{
  bbb_puts("PRU0 interrupt\r\n");
  return IRQ_HANDLED;
}

int isr_pru1(void)
{
  bbb_puts("PRU1 interrupt\r\n");
  return IRQ_HANDLED;
}

int isr_pru(void)
{
  u32 shadow;
  int ret = IRQ_NOT_HANDLED;

  if ( PRU_INTC_GPIR & (1 << 31) ) return ret;

  shadow = PRU_INTC_SECR0;

  if ( shadow & 0x00100000 )
  {
    ret |= isr_pru0();
    PRU_INTC_SECR0 = 0x00100000 ;
  }
  if ( shadow & 0x00200000 )
  {
    ret |= isr_pru1();
    PRU_INTC_SECR0 = 0x00200000 ;
  }
  return ret;
}

int isr_uart(void)
{
  if ( * UART_IIR & 1 ) return IRQ_NOT_HANDLED;

  g_uart_rx = * UART_RXD;
  g_uart_rx_valid++;

  return IRQ_HANDLED;
}

int isr_button_s2(void)
{
  if (! ( BUTTON_S2_IRQ0 & BUTTON_S2_BIT) ) return IRQ_NOT_HANDLED;

  bbb_puts("button S2 went ");
  if ( BUTTON_S2 & BUTTON_S2_BIT )
  {
    bbb_puts("up\r\n");
  }else{
    bbb_puts("down\r\n");
  }
  BUTTON_S2_IRQ0 |= BUTTON_S2_BIT;

  return IRQ_HANDLED;
}

int c_entry(void)
{
  return main();
}

/* ARM interrupt handlers */
void c_undefined_handler(void)
{
  bbb_puts("c_undefined_handler\r\n");
}
void c_SWI_handler(void)
{
  bbb_puts("c_SWI_handler\r\n");
}
void c_prefetch_abort_handler(void)
{
  bbb_puts("c_prefetch_abort_handler\r\n");
}
void c_data_abort_handler(void)
{
  bbb_puts("c_data_abort_handler\r\n");
}
void c_reserved_handler(void)
{
  bbb_puts("c_reserved_handler\r\n");
}
void c_irq_handler(void) //__attribute__ ((interrupt ("IRQ")))
{
  int ret = IRQ_NOT_HANDLED;

  ret |= isr_pru();
  ret |= isr_uart();
  ret |= isr_button_s2();

  if ( ! (ret & IRQ_HANDLED) )
  {
    bbb_puts("spurious interrupt - full engine stop\r\n");
    puthex32(PRU_INTC_SRSR0);
    puthex32(PRU_INTC_SRSR1);
    puthex32(PRU_INTC_SECR0);
    puthex32(PRU_INTC_SECR1);
    while(1); /* die */
  }else{
    /* clear global host interrupt */
    * INTC_CONTROL = 1;
  }
}
void c_fiq_handler(void) //__attribute__ ((interrupt ("FIQ")))
{
  w32( UART_TXD, 'X');
  w32( UART_TXD, 'Y');
  w32( UART_TXD, 'Z');
  bbb_puts("c_fiq_handler\r\n");
  isr_button_s2();
  * INTC_CONTROL = 2;
}
