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
