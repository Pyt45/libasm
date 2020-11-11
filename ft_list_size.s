		global			ft_list_size
		section			.text

ft_list_size:
		xor				rcx, rcx
		cmp				rdi, byte 0
		je				end
		inc				rcx

next:
		mov				rdi, [rdi + 8]
		cmp				rdi, byte 0
		je				end
		inc				rcx
		jmp				next

end:
		mov				rax, rcx
		ret