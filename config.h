#ifndef _CONFIG_H_
#define _CONFIG_H_

#define UART UART0
#define PRU0_ARM_INTERRUPT 19

#define PRU_VECTOR_VALID      0x20

#define PRU_VECTOR_CHAN_0     0x00
#define PRU_VECTOR_CHAN_1     0x01
#define PRU_VECTOR_CHAN_2     0x02
#define PRU_VECTOR_CHAN_3     0x03
#define PRU_VECTOR_CHAN_4     0x04
#define PRU_VECTOR_CHAN_5     0x05
#define PRU_VECTOR_CHAN_6     0x06
#define PRU_VECTOR_CHAN_7     0x07
#define PRU_VECTOR_CHAN_8     0x08
#define PRU_VECTOR_CHAN_9     0x09
#define PRU_VECTOR_CHAN_A     0x0a
#define PRU_VECTOR_CHAN_B     0x0b
#define PRU_VECTOR_CHAN_C     0x0c
#define PRU_VECTOR_CHAN_D     0x0d
#define PRU_VECTOR_CHAN_E     0x0e
#define PRU_VECTOR_CHAN_F     0x0f

#define PRU_VECTOR            PRU_VECTOR_CHAN_4

#endif // _CONFIG_H_
