
#include "bbblasr_libc.h"
#include "types.h"
#include "uart.h"
#include "led.h"

/* === global variables === */

volatile u8 g_uart_rx       = 0x20;
volatile u8 g_uart_rx_valid =    0;

/* /// global variables /// */

void w32(u32 a, u32 v)
{
  * (vu32 *) a = v;
}

u32 r32(u32 a)
{
  return * (vu32 *) a;
}

void enable_irqs(void)
{
  asm volatile(
      "push {r0}\n\t"
      "mrs r0, cpsr\n\t"
      "bic r0, r0, #0x80\n\t"
      "msr cpsr_c, r0\n\t"
      "pop {r0}\n\t"
  );
}

void enable_fiqs(void)
{
  asm volatile(
      "push {r0}\n\t"
      "mrs r0, cpsr\n\t"
      "bic r0, r0, #0x40\n\t"
      "msr cpsr_c, r0\n\t"
      "pop {r0}\n\t"
  );
}

void disable_irqs(void)
{
  asm volatile(
      "push {r0}\n\t"
      "mrs r0, cpsr\n\t"
      "orr r0, r0, #0x80\n\t"
      "msr cpsr_c, r0\n\t"
      "pop {r0}\n\t"
  );
}

void disable_fiqs(void)
{
  asm volatile(
      "push {r0}\n\t"
      "mrs r0, cpsr\n\t"
      "orr r0, r0, #0x40\n\t"
      "msr cpsr_c, r0\n\t"
      "pop {r0}\n\t"
  );
}

void delay_us(u32 x)
{
  int t;
  while(x--)
  {
    // FIXME really calibrate
    t = 134;
    while(t--)
    {
      asm ("nop");
    }
  }
}

void delay_ms(u32 x)
{
  delay_us(1000*x);
}

void delay_s(u32 x)
{
  delay_s(1000*x);
}

void sleep(u32 x)
{
  delay_s(x);
}

char bbb_getc(void)
{
  while ( ! g_uart_rx_valid )
  {
    asm volatile( "wfi"); /* wait for interrupt */
                          /* and let isr_uart() fill in g_uart_rx */
  }
  g_uart_rx_valid--;
  return g_uart_rx;
}

void bbb_putc(char c)
{
  while (r32(UART_TXFIFO));
  w32(UART_TXD, c);
}

void bbb_puts(char * s)
{
  while (*s) bbb_putc(*(s++));
}

void putnibble(u8 c)
{
  if (c < 10) bbb_putc('0' + c);
  else        bbb_putc('a' + c - 10);
}

void puthex8(u8 c)
{
  putnibble( c >>   4 );
  putnibble( c & 0x0f );
}

void puthex16(u16 c)
{
  puthex8( c >>   8 );
  puthex8( c & 0xff );
}

void puthex32(u32 c)
{
  puthex16( c >>    16 );
  puthex16( c & 0xffff );
}

void led_set(unsigned char led)
{
  switch (led)
  {
    case 0:
      w32( LED0_SET, LED0_BIT);
      break;
    case 1:
      w32( LED1_SET, LED1_BIT);
      break;
    case 2:
      w32( LED2_SET, LED2_BIT);
      break;
    case 3:
      w32( LED3_SET, LED3_BIT);
      break;
  }
}

void led_clr(unsigned char led)
{
  switch (led)
  {
    case 0:
      w32( LED0_CLR, LED0_BIT);
      break;
    case 1:
      w32( LED1_CLR, LED1_BIT);
      break;
    case 2:
      w32( LED2_CLR, LED2_BIT);
      break;
    case 3:
      w32( LED3_CLR, LED3_BIT);
      break;
  }
}

void led_toggle(unsigned char led)
{
  switch (led)
  {
    case 0:
      r32(LED0) & LED0_BIT ? led_clr(0) : led_set(0);
      break;
    case 1:
      r32(LED1) & LED1_BIT ? led_clr(1) : led_set(1);
      break;
    case 2:
      r32(LED2) & LED2_BIT ? led_clr(2) : led_set(2);
      break;
    case 3:
      r32(LED3) & LED3_BIT ? led_clr(3) : led_set(3);
      break;
  }
}

void bbb_memcpy32(vu32 * d, const u32 * s, int n)
{
  /* FIXME there are faster ways... */
  while (n--)
  {
    d[n] = s[n];
  }
}
