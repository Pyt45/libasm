		global			ft_list_push_front
		section			.text
		extern			malloc

ft_list_push_front:
		; rdi = begin , rsi = data
		push			rdi
		push			rsi
		mov				rdi, 16
		call			malloc ; sizeof(t_list) (16)
		cmp				rax, 0
		pop				rsi
		pop				rdi
		je				end
		mov				[rax], rsi ; new->data = data
		mov				rcx, [rdi]
		mov				[rax + 8], rcx ; new->next = *begin
		mov				[rdi], rax ; *begin = new

end:
		ret