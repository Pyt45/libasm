		section			.text
		global			write_to_file
		extern			dprintf
		extern			printf
		extern			exit

write_to_file:
		;rdi = char *str , rsi = int val,	rdx = int end
		push			rdi
		push			rsi
		push			rdx

		;========== sys_open  =================
		mov				rax, 2
		mov				rdi, filename
		mov				rsi, 1
		;mov				rdx, 0644o
		syscall

		mov				r8, rax
		pop				rdx
		pop				rsi
		pop				rdi
		
		;========== print str =================
		push			rdi
		push			rsi
		push			rdx

		mov				rcx, rdi
		mov				rdi, r8
		mov				rsi, fmts
		mov				rdx, rcx
		call			dprintf

		pop				rdx
		pop				rsi
		pop				rdi
		mov				r8, 3
		;========== print val =================
		push			rdi
		push			rsi
		push			rdx

		mov				rcx, rsi
		mov				rdi, r8
		mov				rsi, fmtd
		mov				rdx, rcx
		call			dprintf

		pop				rdx
		pop				rsi
		pop				rdi
		;mov				r8, 3
		;========== print end =================
		push			rdi
		push			rsi
		push			rdx

		mov				rcx, rsi
		mov				rdi, r8
		mov				rsi, line
		call			dprintf

		pop				rdx
		pop				rsi
		pop				rdi
		;mov				r8, 3
		;========== sys_close =================
		push			rdi
		push			rsi
		push			rdx

		mov				rax, r8
		mov				rdi, r8
		syscall

		pop				rdx
		pop				rsi
		pop				rdi

		section			.data
		filename:		db 'debug.txt', 0

		section			.rodata
		fmts:			db '%s'
		fmtd:			db '%d'
		line:			db 10, '------------', 10, 0
