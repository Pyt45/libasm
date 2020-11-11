        global          ft_strcmp
        section         .text

ft_strcmp:
        mov             rcx, -1
		xor				rdx, rdx
		xor				rax, rax
        jmp             next

next:
        inc             rcx
        mov             al, byte[rdi + rcx]
        ;mov             dh, byte[rsi + rcx]
        cmp             rax, 0
        je              ft_end
        ;cmp             dl, byte[rsi + rcx]
		mov				dl, byte[rsi + rcx]
		sub				rax, rdx
		cmp				rax, 0
        je              next
        jg              ft_g
        jl              ft_l

ft_end:
        cmp             byte[rsi + rcx], 0
        jne             ft_l
        xor             rax, rax
        ret

ft_l:
        mov             rax, -1
        ret
ft_g:
        mov             rax, 1
        ret