#ifndef _LED_H_
#define _LED_H_

#include "config.h"
#include "types.h"

#define GPIO0_BASE 0x44E07000
#define GPIO1_BASE 0x4804C000
#define GPIO2_BASE 0x481AC000
#define GPIO3_BASE 0x481AE000

#define GPIO_IRQSTATUS0      0x02c
#define GPIO_IRQSTATUS1      0x030
#define GPIO_IRQSTATUS_SET_0 0x034
#define GPIO_IRQSTATUS_SET_1 0x038
#define GPIO_OE              0x134
#define GPIO_DATAIN          0x138
#define GPIO_DATAOUT         0x13c
#define GPIO_RISINGDETECT    0x148
#define GPIO_FALLINGDETECT   0x14c
#define GPIO_CLEARDATAOUT    0x190
#define GPIO_SETDATAOUT      0x194


#define LED0                      GPIO1_BASE+GPIO_DATAOUT
#define LED1                      GPIO1_BASE+GPIO_DATAOUT
#define LED2                      GPIO1_BASE+GPIO_DATAOUT
#define LED3                      GPIO1_BASE+GPIO_DATAOUT

#define LED0_SET                  GPIO1_BASE+GPIO_SETDATAOUT
#define LED1_SET                  GPIO1_BASE+GPIO_SETDATAOUT
#define LED2_SET                  GPIO1_BASE+GPIO_SETDATAOUT
#define LED3_SET                  GPIO1_BASE+GPIO_SETDATAOUT

#define LED0_CLR                  GPIO1_BASE+GPIO_CLEARDATAOUT
#define LED1_CLR                  GPIO1_BASE+GPIO_CLEARDATAOUT
#define LED2_CLR                  GPIO1_BASE+GPIO_CLEARDATAOUT
#define LED3_CLR                  GPIO1_BASE+GPIO_CLEARDATAOUT

#define LED0_BIT 0x00200000
#define LED1_BIT 0x00400000
#define LED2_BIT 0x00800000
#define LED3_BIT 0x01000000

#define BUTTON_S2_BIT             0x00000100 /* GPIO 2 8 */
#define BUTTON_S2                 ( * (vu32 *)(GPIO2_BASE+GPIO_DATAIN)) /* GPIO 2 8 */
#define BUTTON_S2_IRQ0            ( * (vu32 *)(GPIO2_BASE+GPIO_IRQSTATUS0))
#define BUTTON_S2_IRQ1            ( * (vu32 *)(GPIO2_BASE+GPIO_IRQSTATUS1))
#define BUTTON_S2_IRQSTATUS_SET_0 ( * (vu32 *)(GPIO2_BASE+GPIO_IRQSTATUS_SET_0))
#define BUTTON_S2_IRQSTATUS_SET_1 ( * (vu32 *)(GPIO2_BASE+GPIO_IRQSTATUS_SET_1))
#define BUTTON_S2_RISINGDETECT    ( * (vu32 *)(GPIO2_BASE+GPIO_RISINGDETECT))
#define BUTTON_S2_FALLINGDETECT   ( * (vu32 *)(GPIO2_BASE+GPIO_FALLINGDETECT))

#endif /* _LED_H_ */

