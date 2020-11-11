		section 		.data
		NEW_LINE 		db 0xa
		INPUT 			db "Hello world!", 10

		section 		.rodata
		fmt:			db '%d', 10, 0
		format: 		db 'Hello %s', 10, 0
		name:   		db 'Ayoub'

		section			.text
		global			main
		extern			printf

main:
		mov				rdi, format
		mov				rsi, name
		push			rax
		;xor				rax, rax
		call			printf

		pop				rax

		xor				rax, rax
		ret