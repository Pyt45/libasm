        global          _ft_strdup
        section         .text
        extern          _malloc
        extern          _ft_strcpy
        extern          _ft_strlen

_ft_strdup:
        call            _ft_strlen
        mov             r8, rax
        add             r8, 1
        call            _malloc
        jmp             dup

increment:
       inc             rcx

dup:
       xor             rcx, rcx
       mov             dl, byte[rdi + rcx]
       mov             byte[rax + rcx], dl
       cmp             byte[rdi + rcx], 0
       jne             increment

return:
       mov             [rax], qword rdi 
       ret

; _ft_strdup:
;         call            _ft_strlen
;         push            rdi
;         mov             rdi, rax
;         add             rdi, 1
;         call            _malloc
;         pop             rsi
;         mov             rdi, rax
;         call            _ft_strcpy
;         mov             rax, rdi
;         ret