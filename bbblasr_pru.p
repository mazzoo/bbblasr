.origin 0
.entrypoint START

#include "config.h"
#define AM33XX

#ifndef PRU_NR
#error "ERROR: please define PRU_NR as 0 or 1 when assembling bbblasr_pru.p"
#endif

#define GPIO1             0x4804c000
#define GPIO_CLEARDATAOUT      0x190
#define GPIO_SETDATAOUT        0x194


START:
// clear that bit
    LBCO r0, C4, 4, 4
    CLR r0, r0, 4
    SBCO r0, C4, 4, 4

    MOV r1, 5

BLINK:
    MOV r2, 1<<(21+PRU_NR)
    MOV r3, GPIO1 | GPIO_SETDATAOUT
    SBBO r2, r3, 0, 4

    MOV r0, 0x00400000
DELAY:
    SUB r0, r0, 1
    QBNE DELAY, r0, 0

    MOV r2, 1<<(21+PRU_NR)
    MOV r3, GPIO1 | GPIO_CLEARDATAOUT
    SBBO r2, r3, 0, 4

    MOV r0, 0x00400000
DELAY2:
    SUB r0, r0, 1
    QBNE DELAY2, r0, 0

    SUB r1, r1, 1
    QBNE BLINK, r1, 0

    // raise ARM interrupt
    MOV R31.b0, PRU_VECTOR_VALID + PRU_VECTOR + PRU_NR

    HALT
