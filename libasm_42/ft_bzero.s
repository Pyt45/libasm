        global      _ft_bzero
        section     .text
_ft_bzero:
loop:
        dec     rsi
        cmp     rsi, 0
        jl      return
        mov     [rdi + rsi], byte 0
        jmp     loop

return:
        ret