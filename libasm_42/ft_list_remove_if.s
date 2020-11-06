            global          _ft_list_remove_if
            section         .text
            extern          _free

_ft_list_remove_if:
            ; rdi = *begin , rsi = *data_ref , rdx = int (*cmp())
            push			r12
			push			r9
			push			rbx
			cmp				rdi, 0 ; !begin
			je				end
			mov				r12, [rdi] ; head = *begin
			cmp				rdx, 0 ; !cmp
			je				return
			mov				r9, 0 ; tmp = NULL
			mov				rbx, 0 ; last = NULL
			jmp				big_loop

increment_main:
			mov				rbx, [rdi]  ; last = *begin
			mov				rcx, [rbx + 8]
			mov				[rdi], rcx ; *begin = (*begin)->next

big_loop:
			cmp				qword[rdi], 0 ; !(*begin)
			je				return
			mov				rax, rdx
			push			rdi
			push			rsi
			mov				rcx, [rdi]
			mov				rdi, [rcx] ; rdi = *begin->data
			call			rax
			pop				rsi ; rsi = data_ref
			pop				rdi
			cmp				rax, 0 ; cmp(*begin->data, data_ref)
			je				remove_from_list
			jmp				increment_main

remove_from_list:
			xor				


return:
			mov				[rdi], r12

end:
			pop				rbx
			pop				r9
			pop				r12
			ret