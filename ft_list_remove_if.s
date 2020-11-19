				global		ft_list_remove_if
				section		.text

				extern		free

%define			NULL		dword 0x0

; void	ft_list_remove_if(
;	t_list **begin_list			-> rdi,
;	void *data_ref				-> rsi,
;	int (*cmp)()				-> rdx
; )

;	t_list *tmp					-> r8
;	*begin_list					-> r9

ft_list_remove_if:
				; if (!begin_list)
				cmp			rdi, 0
				je			end

				; if (!*begin_list)
				cmp			[rdi], NULL
				je			end

				; if (!data_ref)
				cmp			rsi, 0
				je			end

				; if (!cmp)
				cmp			rdx, 0
				je			end

				; if (!free_fct)
				cmp			rcx, 0
				je			end

				; getting *begin_list
				mov			r9, [rdi]

calling:
				push		rdi
				push		rsi
				push		rdx
				push		rcx

				; ; moving in rdi (*begin_list)->data, no need to move data_ref in rsi
				; ; because it's already in there
				mov			rdi, [r9]
				call		rdx

				pop			rcx
				pop			rdx
				pop			rsi
				pop			rdi

				; cmp(...) == 0 then goto delone
				cmp			eax, dword 0
				je			delone

				; else recursive call
				push		rdi
				push		rsi
				push		rdx
				push		rcx

				mov			r9, [rdi]
				add			r9, 8			; <=> &(*begin_list)->next
				mov			rdi, r9

				; recursive call of ft_list_remove_if in the case where we ignore
				; the current element
				call		ft_list_remove_if

				pop			rcx
				pop			rdx
				pop			rsi
				pop			rdi

				jmp			end

delone:
				; preparing tmp, and *begin_list
				mov			r9, [rdi]
				mov			r8, r9

				; (*begin_list)->next and affecting it to *begin_list
				mov			r9, [r9 + 8]
				mov			[rdi], r9

				; preparing the call of free_fct and calling it
				push		rdi
				push		rsi
				push		rdx
				push		rcx
				push		r8

				;mov			rdi, [r8]
				;call		rcx

				; restoring tmp and free-ing it
				pop			r8
				mov			rdi, r8
				call		free

				; restoring all register before doing the recursive call
				pop			rcx
				pop			rdx
				pop			rsi
				pop			rdi

				; preparing and doing the recursive call then restoring registers
				push		rdi
				push		rsi
				push		rdx
				push		rcx

				; recursive call of ft_list_remove_if with the previous registers
				call		ft_list_remove_if

				pop			rcx
				pop			rdx
				pop			rsi
				pop			rdi

end:
				ret

;         global			_ft_list_remove_if
;         section			.text
;     	extern			_free

; _ft_list_remove_if:
; 		push			r12 ; r12 = current = *begin ; r9 = last
; 		push			rbx ; rbx = tmp = current
; 		cmp				rdi, 0 ; !begin
; 		je				end
; 		mov				r12, [rdi] ; r12 = *begin
; 		cmp				rsi, 0
; 		je				end
; 		cmp				rdx, 0
; 		je				end
; 		xor				rbx, rbx ; tmp = rbx = NULL
; 		xor				r9, r9 ; last = r9 = NULL
; 		jmp				big_loop
		

; free_elt:
; 		mov				rbx, [rdi] ; tmp = current
; 		mov				rcx, [rdi]
; 		mov				r8, [rcx + 8]
; 		mov				[rdi], r8 ; current = current->next
; 		push			rdi
; 		push			rsi
; 		push			rdx

; 		mov				rdi, rbx
; 		call			_free

; 		pop				rdx
; 		pop				rsi
; 		pop				rdi
; 		jmp				big_loop


; give_it_add:
; 		mov				rcx, [rdi] ; rcx = current
; 		mov				rax, [rcx + 8] ; rax = current->next
; 		mov				r12, rax ; *begin = current->next
; 		jmp				free_elt

; remove_elt:
; 		mov				rcx, r12 	; rcx = *begin
; 		mov				r8, [rdi] 	; r8 = current
; 		sub				r8, rcx
; 		cmp				r8, 0 		; current == *begin
; 		je				give_it_add
; 		mov				rcx, [rdi] ; rcx = current
; 		mov				rax, [rcx + 8] ; rax = current->next
; 		mov				[r9 + 8], rax ; last->next = current->next
; 		jmp				free_elt

; big_loop:
; 		cmp				qword [rdi], 0 ; !(current) ; current = *begin
; 		je				end
; 		mov				rcx, [rdi] ; rcx = *begin
; 		;mov				r9, rsi
; 		push			rdi
; 		push			rsi
; 		push			rdx
; 		push			r9

; 		mov				rdi, [rcx] ; rdi = current->dara
; 		;mov				rsi, r9
; 		call			rdx ; cmp(current->data, rsi = data_ref)
		
; 		pop				r9
; 		pop				rdx
; 		pop				rsi
; 		pop				rdi
; 		cmp				rax, 0
; 		jne				increment
; 		jmp				remove_elt

; increment:
; 		mov				r9, [rdi] ; last = current
; 		mov				r8, [rdi]
; 		mov				rcx, [r8 + 8]
; 		mov				[rdi], rcx ; current = current->next
; 		jmp				big_loop

; end:
; 		mov				[rdi], r12
; 		pop				rbx
; 		pop				r12
; 		ret