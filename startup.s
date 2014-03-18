.section INTERRUPT_VECTOR, "x"
.text
.code 32
.global _reset
_reset:
    b _reset_handler          /* Reset */
    b _undefined_handler      /* Undefined */
    b _SWI_handler            /* SWI */
    b _prefetch_abort_handler /* Prefetch Abort */
    b _data_abort_handler     /* Data Abort */
    b _reserved_handler       /* reserved */
    b _irq_handler            /* IRQ */
    b _fiq_handler            /* FIQ */


//    /* FIQ handler in place */
//    sub lr, lr, #4
//    stmfd sp!,{r0-r7,lr}
//    bl c_fiq_handler
//    ldmfd sp!,{r0-r7,pc}^

    .string "copyleft"

    .align 4
_reset_handler:
    /* we're in supervisor mode */

    /* enter IRQ mode */
    ;@//mov r0, #(PSR_IRQ_MODE|PSR_FIQ_DIS|PSR_IRQ_DIS)
    mov r0,#0xd2
    msr cpsr_c, r0

    /* set up IRQ stack */
    ldr sp, =top_of_irq_stack

    /* enter FIQ mode */
    mov r0,#0xd1
    msr cpsr_c, r0

    /* set up FIQ stack */
    ldr sp, =top_of_fiq_stack

    /* return to SVC mode */
    ;@//mov r0, #(PSR_SVC_MODE|PSR_FIQ_DIS|PSR_IRQ_DIS)
    mov r0,#0xd3
    msr cpsr_c, r0

    /* set up SVC stack */
    ldr sp, =top_of_stack

    /* call C */
    bl c_entry

    /* die */
    b .

_undefined_handler:
    ldr sp, =top_of_stack
    bl c_undefined_handler
    b .

_SWI_handler:
    ldr sp, =top_of_stack
    bl c_SWI_handler
    b .

_prefetch_abort_handler:
    ldr sp, =top_of_stack
    bl c_prefetch_abort_handler
    b .

_data_abort_handler:
    ldr sp, =top_of_stack
    bl c_data_abort_handler
    b .

_reserved_handler:
    ldr sp, =top_of_stack
    bl c_reserved_handler
    b .

_irq_handler:
    sub lr, lr, #4
    stmfd sp!,{r0-r12,lr}
    bl c_irq_handler
    /* the caret (^) in the next command directs the ARM to
     * restore CPSR from SPSR (like the s suffix in movs/subs) */
    ldmfd sp!,{r0-r12,pc}^

_fiq_handler:
    sub lr, lr, #4
    stmfd sp!,{r0-r7,lr}
    bl c_fiq_handler
    /* the caret (^) in the next command directs the ARM to
     * restore CPSR from SPSR (like the s suffix in movs/subs) */
    ldmfd sp!,{r0-r7,pc}^
