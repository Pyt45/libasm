        section			.text
		global			ft_atoi_base
        extern          ft_strlen
		extern			printf
		extern			dprintf


ft_atoi_base:
		; rdi = str , rsi = base
		; pushing register
        push            rbx ; base_len
        push            r12 ; index
        push            r13 ; i
        push            r14 ; num
        push            r15 ; sign

        ;xor             r14, r14 ; num = 0
		push			rdi
		push			rsi
		mov				rdi, rsi
		call			ft_strlen
		mov				rbx, rax ; rbx = strlen(base)
		xor				r14, r14 ; r14 = 0
		pop				rsi
		pop				rdi
		cmp				rax, 0
		je				exit
		;pop				rsi
		mov				rcx, -1
		jmp				ft_atoi_base_do
		; push			rdi
		; push			rsi

find_char_base:
		mov				rcx, -1

find_loop:
		inc				rcx
		mov				al, byte [rdi + rcx]
		sub				al,  sil
		cmp				al, byte 0
		je				find_index
		cmp				[rdi + rcx], byte 0
		jne				find_loop

find_exit:
		mov				rax, -1
		ret

find_index:
		mov				rax, rcx
		ret	

ft_atoi_base_do:
		;push			rdi
		;push			rsi
		inc				rcx
		;cmp				byte [rsi + rcx], 0
		;mov				r12, rsi
		;je				exit_loop
		;je				exit
		push			rdi
		push			rsi
		push			rdx
		push			rcx
		; mov				rdi, fmt
		; mov				rsi,  qword [rsi + rcx]
		; call			printf
		;jmp				exit
		; pop				rcx
		; pop				rsi
		;jmp				exit_loop
		;mov				rsi, r8
		mov				rdi, rsi
		mov				sil, byte [rsi + rcx]
		call			find_char_base
		mov				r8, rax
		cmp				rax, 0
		jge				do_opr

		; mov				rdi, fmt
		; mov				rsi,  r8
		; call			printf
		pop				rcx
		pop				rdx
		pop				rsi
		pop				rdi
		; jmp				exit
		; =============== printf     ===============
		; push			rdi
		; push			rsi
		; push			rdx
		; push			rcx

		; mov				rdi, fmt
		; mov				rsi,  rax
		; call			printf
		; =============== end printf ===============
		;mov				r8, rax
		;cmp				rax, 0
		;jge				do_opr
		;===============
		; pop				rcx
		; pop				rdx
		; pop				rsi
		; pop				rdi
		;===============
		;mov				rsi, r12
		;mov				r8, rax
		;cmp				rax, 0
		;jge				do_opr
		;jl				increment
		cmp				byte [rsi + rcx], 0
		jne				ft_atoi_base_do
		;jmp				exit

        ;push            rdi
        ;push            rsi
        ;mov             rdi, rsi ; rdi = base
        ;call            check_base ; check_base(rdi)
        ;pop             rsi
        ;pop             rdi
        ;cmp             rax, 0
        ;je              exit

do_opr:
		; =============== printf     ===============
		push			rdi
		push			rsi
		push			rdx
		push			rcx

		; mov				rax, rbx
		; mul				r14
		;add				r14, r8

		mov				rdi, 1
		mov				rsi,  fmt
		mov				rdx, rbx
		call			dprintf
		; =============== end printf ===============
		pop				rcx
		pop				rdx
		pop				rsi
		pop				rdi
		jmp				exit
		;inc				rcx
		jmp				ft_atoi_base_do

; increment:
; 		;pop				rcx
; 		inc				rcx
; 		; pop				rsi
; 		; pop				rdi
; 		jmp				ft_atoi_base_do

;exit_loop:
		; pop				rsi
		; pop				rdi
		;mov				rax, r14
		;ret
		;jmp				exit


; check_base:
;         ; rdi = base
;         call            ft_strlen
;         cmp             rax, 0
;         je              exit_loop

; check_base_loop:
;         mov             rcx, 0
;         push            rax
;         cmp             rcx, rax
;         jge             return
;         cmp             byte [rdi + rcx], 43
;         je              exit_loop
;         cmp             byte [rdi + rcx], 45
;         je              exit_loop
;         cmp             byte [rdi + rcx], 32
;         jle             exit_loop
;         cmp             byte [rdi + rcx], 126
;         jg              exit_loop
;         push            rdi
;         push            rsi
;         push            rcx
;         mov             sil, byte [rdi + rcx]
;         mov             rdi, rcx
;         add             rdi, 1
;         call            _find_char_base
;         pop             rcx
;         pop             rsi
;         pop             rdi
;         cmp             rax, 0
;         jge             exit_loop
;         inc             rcx
;         jmp             check_base_loop

; return:
;         pop             rax
;         mov             rax, rax
;         ret

; exit_loop:
;         mov             rax, 0
;         ret


exit:
		; pop				rcx
		; pop				rdx
		; pop				rsi
		; pop				rdi

        mov             rax, rbx
        pop            	r15 ; sign            
        pop            	r14 ; num
        pop            	r13 ; i
        pop            	r12 ; index
        pop            	rbx ; base_len
        ret

section			.rodata
		fmt:			db '|%d|', 10
