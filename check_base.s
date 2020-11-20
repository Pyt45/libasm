		section				.text
		global				check_base
		;extern				find_char_base
		extern				ft_strlen
		extern				dprintf

check_base:
		;rdi = base
		call				ft_strlen
		mov					rdx, rax
		sub					rax, 1
		cmp					rax, 0
		je					exit
		mov					rcx, 0
		jmp					next

increment:
		inc					rcx

next:
		cmp					byte [rdi + rcx], 0
		je					exit_ret
		cmp					byte [rdi + rcx], 43
		je					exit
		cmp					byte [rdi + rcx], 45
		je					exit
		cmp					byte [rdi + rcx], 0
		jl					exit
		cmp					byte [rdi + rcx], 126
		jg					exit
		push				rdi
		push				rcx
		mov					sil, byte [rdi + rcx]
		add					rdi, rcx
		inc					rdi
		call				find_char_base
		pop					rcx
		pop					rdi
		cmp					rax,  0
		jge					exit
		jmp					increment

exit_ret:
		mov					rax, rdx
		ret

exit:
		mov					rax, 0
		ret



find_char_base:
		;rdi = base , rsi = char c
        mov					rcx, -1

find_loop:
        inc					rcx
        mov					al, byte [rdi + rcx]
        sub					al,  sil
        cmp					al, byte 0
        je					find_index
        cmp					[rdi + rcx], byte 0
        jne					find_loop

find_exit:
		mov		        	rax, -1
		ret

find_index:
        mov					rax, rcx
        ret
