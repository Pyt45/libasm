        global			_ft_list_remove_if
        section			.text
    	extern			_free

_ft_list_remove_if:
		push			r12 ; r12 = current = *begin ; r9 = last
		push			rbx ; rbx = tmp = current
		mov				r12, [rdi]
		cmp				rdi, 0
		je				end
		xor				rbx, rbx
		xor				r9, r9
		cmp				rdx, 0
		je				end
		jmp				big_loop

free_elt:
		mov				rbx, [rdi] ; tmp = current
		mov				rcx, [rdi]
		mov				r8, [rcx + 8]
		mov				[rdi], r8 ; current = current->next
		push			rdi
		push			rsi
		push			rdx
		mov				rdi, rbx
		call			_free
		pop				rdx
		pop				rsi
		pop				rdi
		jmp				big_loop


give_it_add:
		mov				rcx, [rdi] ; rcx = current
		mov				rax, [rcx + 8] ; rax = current->next
		mov				r12, rax ; *begin = current->next
		jmp				free_elt

remove_elt:
		mov				rcx, r12 	; rcx = *begin
		mov				r8, [rdi] 	; r8 = current
		sub				r8, rcx
		cmp				r8, 0 		; current == *begin
		je				give_it_add
		mov				rcx, [rdi] ; rcx = current
		mov				rax, [rcx + 8] ; rax = current->next
		mov				[r9 + 8], rax ; last->next = current->next
		jmp				free_elt

big_loop:
		cmp				qword [rdi], 0 ; !(current)
		je				end
		mov				rcx, [rdi]
		push			rdi
		push			rsi
		push			rdx
		mov				rdi, [rcx] ; rdi = current->dara
		call			rdx ; cmp(current->data, rsi = data_ref)
		mov				rax, rdx
		pop				rdx
		pop				rsi
		pop				rdi
		cmp				rax, 0
		jne				increment
		jmp				remove_elt

increment:
		mov				r9, [rdi] ; last = current
		mov				r8, [rdi]
		mov				rcx, [r8 + 8]
		mov				[rdi], rcx ; current = current->next
		jmp				big_loop

end:
		mov				[rdi], r12
		pop				rbx
		pop				r12
		ret