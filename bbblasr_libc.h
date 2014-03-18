#ifndef _BBBLASR_LIBC_H_
#define _BBBLASR_LIBC_H_

#include "config.h"
#include "types.h"

/* === global variables === */

extern volatile u8 g_uart_rx;
extern volatile u8 g_uart_rx_valid;

/* /// global variables /// */

inline void w32(u32 a, u32 v);
inline u32 r32(u32 a);

void enable_irqs(void);
void enable_fiqs(void);
void disable_irqs(void);
void disable_fiqs(void);

char bbb_getc(void);
void bbb_putc(char c);
void bbb_puts(char * s);

void delay_us(unsigned int x);
void delay_ms(unsigned int x);
void delay_s(unsigned int x);
void sleep(unsigned int x);

void puthex8(u8 c);
void puthex16(u16 c);
void puthex32(u32 c);

void led_set(unsigned char led);
void led_clr(unsigned char led);
void led_toggle(unsigned char led);

void bbb_memcpy32(vu32 * d, const u32 * s, int n);

#endif /* _BBBLASR_LIBC_H_ */
