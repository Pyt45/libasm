		section			.text
		global			ft_list_sort

ft_list_sort:
		; rdi = begin , rsi = (*cmp)()
		push			r12
		push			rbx
		cmp				rdi, 0 ; !begin
		je				end
		mov				r12, [rdi]
		cmp				rsi, 0 ; !cmp
		je				return
		jmp				cmp_head

loop_1:
		mov				rcx, [rdi]
		mov				rbx, [rcx + 8]
		mov				[rdi], rbx ; (*begin) = (*begin)->next

cmp_head:
		cmp				qword [rdi], 0 ; !(*begin)
		je				return
		mov				rcx, [rdi]
		mov				rbx, [rcx + 8] ; tmp = (*begin)->next

loop_2:
		cmp				rbx, 0 ; !(tmp)
		je				loop_1

; ================================= loop end     ================================= 
; ================================= cmp and loop ================================= 		

cmp_main:
		push			rsi
		push			rdi
		mov				rax, rsi
		mov				rcx, [rdi]
		mov				rdi, [rcx]
		mov				rsi, [rbx]
		call			rax
		pop				rdi
		pop				rsi
		cmp				rax, 0
		jg				swap_data

increment:
		mov				rcx, [rbx + 8]
		mov				rbx, rcx ; tmp = tmp->next
		jmp				loop_2
		
swap_data:
		mov				r8,[rdi]
		mov				rcx, [r8]  ; data_sort = (*begin)->data
		mov				rax, [rbx] ; rax = tmp->data
		mov				[r8], rax; (*begin)->data = tmp->data 
		mov				[rbx], rcx; tmp->data = data_sort
		jmp				increment

return:
		mov				[rdi], r12

end:
		pop				rbx
		pop				r12
		ret