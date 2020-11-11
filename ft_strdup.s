		section			.text
		global			ft_strdup
		extern			ft_strlen
		extern			ft_strcpy
		extern			malloc

ft_strdup:
		call			ft_strlen
		push			rdi
		mov				rdi, rax
		add				rdi, 1
		call			malloc
		pop				rsi
		mov				rdi, rax
		call			ft_strcpy
		ret
