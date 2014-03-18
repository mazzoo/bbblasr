#ifndef _UART_H_
#define _UART_H_

#include "config.h"
#include "types.h"

#ifndef UART
#  error "please define a default UART in config.h ... e.g. #define UART UART0"
#endif

/*
 *   baud  oversampling  divisor  %error
 * 115200            16       26    0.16
 */

#define UART0 0x44E09000
#define UART1 0x48022000
#define UART2 0x48024000
#define UART3 0x481A6000
#define UART4 0x481A8000
#define UART5 0x481AA000

#define UART_THR         0x00
#define UART_RHR         0x00
#define UART_RXFIFO_LVL  0x64
#define UART_TXFIFO_LVL  0x68

#define UART_TXD     (UART+UART_THR)
#define UART_RXD    (vu16 *) (UART+UART_RHR)
#define UART_TXFIFO  (UART+UART_TXFIFO_LVL)
#define UART_RXFIFO (vu16 *) (UART+UART_RXFIFO_LVL)

#define UART_IER    (vu32 *) (UART+0x04)
#define UART_IIR    (vu32 *) (UART+0x08)
#define UART_TLR    (vu32 *) (UART+0x1c)
#define UART_ISR2   (vu32 *) (UART+0x70)

#endif /* _UART_H_ */

