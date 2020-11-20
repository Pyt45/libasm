		section				.text
		global				ft_isspace

ft_isspace:
		; rdi = int c
		cmp					rdi, 32
		je					set_rax
		cmp					rdi, 9
		je					set_rax
		cmp					rdi, 10
		je					set_rax
		cmp					rdi, 11
		je					set_rax
		cmp					rdi, 12
		je					set_rax
		cmp					rdi, 13
		je					set_rax 
		xor					rax, rax
		ret

set_rax:
		mov					rax, 1
		re
