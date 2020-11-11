        global      ft_strcpy
        section     .text

ft_strcpy:
		xor			rcx, rcx
		jmp			_ft_strcpy_loop

increment:
		inc			rcx

_ft_strcpy_loop:
		mov			dl, [rsi + rcx]
		mov			[rdi + rcx], dl
		cmp			byte [rsi + rcx], 0
		jne			increment

return:
		mov			rax, rdi
		ret