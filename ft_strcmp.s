        global          ft_strcmp
        section         .text

ft_strcmp:
        mov             rcx, -1
        jmp             next

next:
        inc             rcx
        mov             dl, byte[rdi + rcx]
        mov             dh, byte[rsi + rcx]
        cmp             dl, 0
        je              ft_strcmp_end
        cmp             dl, dh
        je              next
        jl              ft_strcmp_l
        jg              ft_strcmp_g

ft_strcmp_end:
        cmp             dh, 0
        jne             ft_strcmp_l
        xor             rax, rax
        ret

ft_strcmp_l:
        mov             rax, -1
        ret
ft_strcmp_g:
        mov             rax, 1
        ret