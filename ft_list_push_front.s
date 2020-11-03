		global			ft_list_push_front
		section			.text

ft_list_push_front:
		xor				rax, rax
		cmp				rdi, byte 0
		je				end

next:
		mov				rdi, [rdi + 8]
		mov				rax, rdi
		mov				[rdi], rsi
		ret

end:
		ret