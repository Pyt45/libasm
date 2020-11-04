		global			ft_list_push_front
		section			.text
		extern			malloc

ft_list_push_front:
		; rdi = *begin_list , rsi = void *data
		;push			rsp
		push			rsi
		push			rdi
		mov				rdi, 16 ; sizeof(t_list) = 16
		xor				rax, rax
		call			malloc ; molloc(16)
		pop				rdi
		pop				rsi
		cmp				rax, 0
		je				return
		mov				[rax], rsi ; new->data = data
		mov				rcx, [rdi]
		mov				[rax + 8], rcx; new->next = *begin
		mov				[rdi], rax ; *begin = new

return:
		;pop				rsp
		ret
