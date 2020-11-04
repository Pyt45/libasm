section     .text
global      _test

_test:
        xor         rax, rax
        xor         rcx, rcx
        mov         al, byte[rdi + rcx]
        cmp        al, 0
        jne         return
        jmp         return_1

return_1:
        mov         rax, 2
        ret


return:
        xor         rax, rax
        ret