section .rdata
    kmhToMs dq 0.2777777777777778

section .text
bits 64
default rel
global compute
compute:

    push rbp
    mov rbp, rsp ; stack pointer

    ; param 1 - matrix 
    mov rdi, rcx     
    ; param 2 - output
    mov rsi, rdx  
    ; param 3 - # of rows        
    mov rcx, r8         

    movsd xmm3, [kmhToMs]

.loop_start:
    test rcx, rcx
    jz .done

    movsd xmm0, [rdi]
    mulsd xmm0, xmm3

    movsd xmm1, [rdi + 8]
    mulsd xmm1, xmm3

    movsd xmm2, [rdi + 16]

    ; actual acceleration computation
    subsd xmm1, xmm0
    divsd xmm1, xmm2

    ; converts to nearest int
    cvtsd2si eax, xmm1

    ; stores the result
    mov [rsi], eax

    add rdi, 24    
    add rsi, 4 
    dec rcx
    jmp .loop_start

.done:
    pop rbp
    ret