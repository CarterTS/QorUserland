.section .text
.globl value
value:
    addi a0, zero, 42
    ret

.globl _start
_start:
    call value
    
    addi a7, zero, 60
    ecall