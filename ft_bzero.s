        global          ft_bzero
        section         .text

ft_bzero:
        dec				rsi
		cmp				rsi, 0
		jl				exit
		mov				byte [rdi + rsi], 0
		jmp				ft_bzero

exit:
        ret