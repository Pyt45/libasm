        section		        .text
		global		        _ft_atoi_base
        extern                 _ft_strlen
		extern		        _printf
		extern		        _dprintf
		extern				_write_to_file


_ft_atoi_base:
		; rdi = str , rsi = base
		; pushing register
        push				rbx ; base_len
        push				r12 ; index
        push				r13 ; i
        push				r14 ; num
        push				r15 ; sign

        ;xor             r14, r14 ; num = 0
        push				rdi
        push				rsi
        mov					rdi, rsi
        call				_ft_strlen
        mov		        	rbx, rax ; rbx = strlen(base)
        mov					r14, 0 ; r14 = 0
        pop					rsi
        pop					rdi
        cmp					rax, 0
        je					exit
        mov					rcx, 0
        jmp					ft_atoi_base_do
    

find_char_base:
		;rdi = base , rsi = char c
        mov					rcx, -1

find_loop:
        inc					rcx
        mov					al, byte [rdi + rcx]
        sub					al,  sil
        cmp					al, byte 0
        je					find_index
        cmp					[rdi + rcx], byte 0
        jne					find_loop

find_exit:
		mov		        	rax, -1
		ret

find_index:
        mov					rax, rcx
        ret	

ft_atoi_base_do:
        ;rdi = str , rsi = base
		cmp					byte [rdi + rcx], 0
		je					exit
        push				rdi
        push				rsi
        push				rdx
        mov					rdi, rsi
        mov					sil, byte [rdi + rcx]
        call				find_char_base
        cmp					rax, 0
        pop					rdx
        pop					rsi
        pop					rdi
        jge					do_opr

next:
		inc					rcx
		jmp					ft_atoi_base_do
        ; mov		        rdi, fmt
        ; mov			rsi,  r8
        ; call			printf
        ; jmp				it
        ; =============== printf     ======ex=========
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
        ; push		        rdi
        ; push		        rsi
        ; push		        rdx
        ; push		        rcx
        imul				r14, rbx
        add					r14, rax
        jmp		        	next

        ; mov		        rdi, 1
        ; mov		        rsi,  fmt
        ; mov		        rdx, r14
        ; call		        _dprintf
        ; ; =============== end printf ===============
        ; pop		        rcx
        ; pop		        rdx
        ; pop		        rsi
        ; pop		        rdi
        ; jmp		        exit
        ;inc				rcx
		;cmp					byte [rsi + rcx], 0

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

        mov                     rax, r14
        pop            	        r15 ; sign            
        pop            	        r14 ; num
        pop            	        r13 ; i
        pop            	        r12 ; index
        pop            	        rbx ; base_len
        ret

section			.rodata
fmt:			db '|%d|', 10


; _ft_atoi_base:								; rdi = *str, rsi = *base
; 			push	rbx						; save rbx (sign)
; 			push	r12						; save r12 (base_length)
; 			xor		rax, rax				; total = 0
; 			xor		rbx, rbx				; sign = 0
; 			xor		r12, r12				; base_length = 0
; 			jmp		base_check_loop
; base_check_increment:
; 			inc		r12						; base_length++
; base_check_loop:
; 			cmp		BYTE [rsi + r12], 0
; 			jz		base_check_end
; 			mov		r8, r12					; j = base_length
; base_check_dup_inc:
; 			inc		r8						; j++
; base_check_dup_loop:
; 			cmp		BYTE [rsi + r8], 0		; !base[j]
; 			jz		base_check_correct
; 			mov		r9b, [rsi + r8]
; 			cmp		BYTE [rsi + r12], r9b	; base[base_length] == base[j]
; 			je		set_rax
; 			jmp		base_check_dup_inc
; base_check_correct:
; 			cmp		BYTE [rsi + r12], 32	; base[base_length] == ' '
; 			je		set_rax
; 			cmp		BYTE [rsi + r12], 43	; base[base_length] == '+'
; 			je		set_rax
; 			cmp		BYTE [rsi + r12], 45	; base[base_length] == '-'
; 			je		set_rax
; 			cmp		BYTE [rsi + r12], 9		; base[base_length] == '\t'
; 			je		set_rax
; 			cmp		BYTE [rsi + r12], 10	; base[base_length] == '\n'
; 			je		set_rax
; 			cmp		BYTE [rsi + r12], 13	; base[base_length] == '\r'
; 			je		set_rax
; 			cmp		BYTE [rsi + r12], 11	; base[base_length] == '\v'
; 			je		set_rax
; 			cmp		BYTE [rsi + r12], 12	; base[base_length] == '\f'
; 			je		set_rax
; 			jmp		base_check_increment
; base_check_end:
; 			cmp		r12, 1					; base_length <= 1
; 			jle		set_rax
; 			xor		r8, r8					; i = 0
; 			jmp		skip_whitespaces
; skip_whitespaces_inc:
; 			inc		r8						; i++
; skip_whitespaces:
; 			cmp		BYTE [rdi + r8], 32		; str[i] == ' '
; 			je		skip_whitespaces_inc
; 			cmp		BYTE [rdi + r8], 9		; str[i] == '\t'
; 			je		skip_whitespaces_inc
; 			cmp		BYTE [rdi + r8], 10		; str[i] == '\n'
; 			je		skip_whitespaces_inc
; 			cmp		BYTE [rdi + r8], 13		; str[i] == '\r'
; 			je		skip_whitespaces_inc
; 			cmp		BYTE [rdi + r8], 11		; str[i] == '\v'
; 			je		skip_whitespaces_inc
; 			cmp		BYTE [rdi + r8], 12		; str[i] == '\f'
; 			je		skip_whitespaces_inc
; 			jmp		check_sign
; is_negative:
; 			xor		bl, 0x00000001
; is_positive:
; 			inc		r8
; check_sign:
; 			cmp		BYTE [rdi + r8], 45		; str[i] == '-'
; 			je		is_negative
; 			cmp		BYTE [rdi + r8], 43		; str[i] == '+'
; 			je		is_positive
; 			jmp		atoi_loop
; atoi_increment:
; 			inc		r8						; i++
; atoi_loop:
; 			cmp		BYTE [rdi + r8], 0		; str[i] == 0
; 			je		set_rax
; 			xor		r9, r9					; j = 0
; 			jmp		atoi_idx
; atoi_idx_inc:
; 			inc		r9						; j++
; atoi_idx:
; 			mov		r10b, BYTE [rsi + r9]
; 			cmp		r10b, 0					; base[j] == 0
; 			je		set_rax
; 			cmp		BYTE [rdi + r8], r10b	; base[j] == str[i]
; 			jne		atoi_idx_inc
; add_to_total:
; 			mul		r12						; total *= base_length
; 			add		rax, r9					; total += k
; 			jmp		atoi_increment
; set_rax:
; 			mov		rax, rax				; ret = total
; 			cmp		rbx, 0					; sign is negative
; 			jz		return
; 			neg		rax						; ret = -ret
; return:
; 			pop		r12						; restore r12
; 			pop		rbx						; restore rbx
; 			ret
