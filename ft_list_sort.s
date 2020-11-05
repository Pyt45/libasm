; section     .text
; global      _test

; _test:
;         xor         rax, rax
;         xor         rcx, rcx
;         mov         al, byte[rdi + rcx]
;         cmp        al, 0
;         jne         return
;         jmp         return_1

; return_1:
;         mov         rax, 2
;         ret


; return:
;         xor         rax, rax
;         ret

            section             .text
            global              _ft_list_sort2

_ft_list_sort2:
            ; rdi = *begin_lis , rsi = int (*cmp())
			push				rbx
            push                r12
            cmp                 rdi, 0 ; !begin
            jz                  end
            mov                 r12, [rdi] ; head = *begin_list
            cmp                 rsi, 0		; cmp == NULL
            jz                  return
			jmp					comp_1

increment_loop:
			mov					rcx, [rdi]
			mov					rbx, [rcx + 8]
			mov					[rdi], rbx ; *begin = (*begin)->next

comp_1:
			cmp					QWORD [rdi], 0 ; !(*begin)
			jz					return
			mov					rcx, [rdi]
			mov					rbx, [rcx + 8]; current = (*begin)->next

comp_2:
			cmp					rbx, 0 ; !current
			jz					increment_loop 

; ============================== end =================================
; ============================== start ===============================

compare:
			push				rdi
			push				rsi
			mov					rax, rsi
			mov					rcx, [rdi]
			mov					rdi, [rcx] ; rdi = (*begin)->data
			mov					rsi, [rbx]  ; rsi = current->data
			call				rax
			pop					rsi
			pop					rdi
			cmp					rax, 0 ; cmp > 0
			jg					swap_data

increment_main:
			mov					rcx, [rbx + 8]
			mov					rbx, rcx ; current = curent->next
			jmp					comp_2

swap_data:
			mov					r8, [rdi]
			mov					rcx, [r8] ; rcx = (*begin)->data
			mov					rax, [rbx] ; rax = current->data
			mov					[r8], rax  ; (*begin->data) = current->data
			mov					[rbx], rcx ; current->data = (*begin)->data
			jmp					increment_main

return:
			mov					[rdi], r12 ; *begin_list = head

end:
            pop                 r12
			pop					rbx
            ret