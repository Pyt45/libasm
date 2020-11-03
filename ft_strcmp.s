        global          _ft_strcmp
        section         .text

_ft_strcmp:
        mov             rcx, -1
		xor				rdx, rdx
		xor				rax, rax
        jmp             next

next:
        inc             rcx
        mov             al, byte[rdi + rcx]
        ;mov             dh, byte[rsi + rcx]
        cmp             rax, 0
        je              ft_end
        ;cmp             dl, byte[rsi + rcx]
		mov				dl, byte[rsi + rcx]
		sub				rax, rdx
		cmp				rax, 0
        je              next
        jg              ft_g
        jl              ft_l

ft_end:
        cmp             byte[rsi + rcx], 0
        jne             ft_l
        xor             rax, rax
        ret

ft_l:
        mov             rax, -1
        ret
ft_g:
        mov             rax, 1
        ret




; _ft_strcmp:
; 		xor				rcx, rcx
; 		xor				rax, rax
; 		xor				rdx, rdx

; strcmp_do:
; 		mov				dl, BYTE[rsi + rcx]
; 		cmp				BYTE[rdi + rcx], dl
; 		jne				return

; increment:
; 		inc				rcx

; equal_to_z:
; 		cmp				BYTE[rdi + rcx], 0
; 		je				return
; 		cmp				BYTE[rsi + rcx], 0
; 		je				return
; 		jmp				strcmp_do

; return:
; 		mov				al, BYTE[rdi + rcx]
; 		mov				dl, BYTE[rsi + rcx]
; 		sub				rax, rdx
; 		cmp				rax, 0
; 		jg				strcmp_g
; 		jl				strcmp_l
; 		ret

; strcmp_g:
; 		xor				rax, rax
; 		sub				rax, 1
; 		neg				rax
; 		ret

; strcmp_l:
; 		xor				rax, rax
; 		mov				rax, 1
; 		neg				rax
; 		ret		