#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int 	main()
{

}

/* ; _ft_list_push_front:
; 		; rdi = prior node* p
;     	; rsi = value
;     	push 			rbp
; 		mov 			rbp, rsp
; 		push 			r15

; 		mov 			r15, rdi                    ; p

; 		mov 			rdi, rsi                    ; value
; 		mov 			rsi, qword [r15 + 8]     ; p->next
; 		call 			_new_node                   ; rax = new_node(...)

; 		mov 			qword [r15 + 8], rax     ; p->next = rax

; 		pop 			r15
; 		pop 			rbp
; 		ret


_ft_list_push_front:
		;push				rdi
		mov					r15, rdi
		mov					rdi, rsi
		call				_ft_new_list
		mov					rdi, r15
		mov					rax, rdi
		ret

		; ===========================================================
		; push				rdi
		; xor					rax, rax
		; mov				r15, rdi ; rdi = *begin_list , rsi = void *data
		; ; push			rdi
		; mov				rdi, rsi
		; cmp				rdi, 0
		; je				_ft_new_list
		;cmp					rdi, 0
		;je					_ft_new_list
		; push				rdi
		; mov					rdi, 16
		; call				_malloc
		; pop					rdi
		; cmp					rdi, 0
		; je					_ft_new_list



; _ft_new_list:
; 		mov					qword [rax], rsi
; 		mov					qword[rax + 8], 0
; 		ret
;     	; rdi = value
;     	; rsi = next ptr
; 		; push 			rbp
; 		; mov 			rbp, rsp

; 		push			rdi

; 		;mov 			r15, rdi ; value
; 		;mov 			r14, rsi ; next

; 		mov 			rdi, 16
; 		call 			_malloc
; 		; rax = address of new node

; 		; Populate node
; 		;pop				rdi
; 		mov 			qword [rax], rsi
; 		mov 			qword [rax + 8],  0

; 		; pop 			r14
; 		; pop 			r15
; 		; pop 			rbp
; 		ret */