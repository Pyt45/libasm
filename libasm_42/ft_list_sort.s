        global              ft_list_sort
        secion              .text

ft_list_sort:                   ; rdi = *begin_list rsi = int (*cmp)(d1, d2)
        push        r12         ; head
        push        rbx         ; next
        cmp         rdi, 0
        je          restore
        mov         r12, [rdi]  ; head = *begin
        cmp         rsi, 0      ; cmp = 0
        je          restore
        jmp         comp_label

increment:
        mov         rcx, [rdi]
        mov         rbx, [rcx + 8]
        mov         [rdi], rbx ; *begin = (*begin)->next

comp_label:
        cmp         qword[rdi], 0 ; *begin == NULL
        je          restore
        mov         rcx, [rdi]
        mov         rbx, [rcx + 8] ; current = *begin->next

comp_this:
        cmp         rbx, 0 ; !current
        je          increment

comp:
        push        rdi
        push        rsi
		;mov		rax, rsi
        mov         rcx, [rdi] 
        mov         rdi, [rcx]	; rdi = *begin->data
        mov         rsi, [rbx]  ; rsi = current->data
		call		rax			; (*cmp)(*begin->data, current->data)
		pop			rsi
		pop			rdi
		cmp			rax, 0
		jg			swap		; (*cmp)(*begin->data, current->data) > 0

swap:
		mov			

restore:
        pop         rbx
        pop         r12
        ret
