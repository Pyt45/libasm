            global          ft_list_remove_if
            section         .text
            extern          free

ft_list_remove_if:
            ; rdi = **begin , rsi = *data_ref , rdx = int (*cmp())
            push			r12
			push			r9
			push			rbx
			mov				r12, [rdi] ; head = *begin
			cmp				rdi, 0 ; !begin
			je				end
			cmp				rdx, 0 ; !cmp
			je				end
			;mov				r9, 0 ; tmp = NULL
            xor                 r9, r9 ; tmp = NULL
			;mov				rbx, 0 ; last = NULL
            xor                 rbx, rbx ; last = NULL
			jmp				big_loop

increment_main:
			mov				rbx, r12  ; last = *begin
			mov				rcx, [rbx + 8]
			mov				r12, rcx ; *begin = (*begin)->next

big_loop:
			cmp				qword r12, 0 ; !(*begin)
			je				end
			mov				rax, rdx
			push			rdi
			push			rsi
			mov				rcx, r12
			mov				rdi, [rcx] ; rdi = *begin->data
			call			rax
			pop				rsi ; rsi = data_ref
			pop				rdi
			cmp				rax, 0 ; cmp(*begin->data, data_ref)
			je				remove_from_elt
			jmp				increment_main

do_else:
            mov             rcx, [r12 + 8]
            mov             [rbx + 8], rcx
            jmp             free_elt

do_if:
            mov             [rdi], r12
            jmp             free_elt      

remove_from_elt:
			mov             rcx, r12
            sub             rcx, [rdi]
            cmp             rcx, 0
            je              do_if
            jne             do_else

free_elt:
            mov             r9, r12        ; tmp = current
            mov             rcx, r12
            mov             r12, [rcx + 8] ; current = current->next
            push            rdi
            mov             rdi, r9
            call            free
            pop             rdi
            jmp             big_loop

end:
			;mov				[rdi], r12
			pop				rbx
			pop				r9
			pop				r12
			ret