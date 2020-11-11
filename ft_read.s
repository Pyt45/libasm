		section			.text
		global			ft_read
		extern			error

ft_read:
		mov				rax, 0x02000003
		syscall
		jc				return
		ret

return:
		push			rax
		call			error
		pop				rcx
		mov				[rax], rcx
		mov				rax, -1
		ret