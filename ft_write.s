		section     .text
		global      ft_write
        extern      error

ft_write:
        mov rax,	0x02000004
        syscall
        jc		return       
        ret
return:
		push	rax
		call	error
		pop		rcx
		mov		[rax], rcx
		mov		rax, -1
		ret