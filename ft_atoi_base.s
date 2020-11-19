        section			.text
		global			_ft_atoi_base
        extern          _ft_strlen

_ft_atoi_base:
		;rdi = str , rsi = base
        push            rbx ; base_len
        push            r12 ; index
        push            r13 ; ptr
        push            r14 ; rsl
        push            r15 ; sign

        xor             r14, r14
        push            rdi
        push            rsi
        mov             rdi, rsi
        call            check_base ; check_base(rdi)
        pop             rsi
        pop             rdi
        pop             r15
        pop             r14
        pop             r13
        pop             r12
        pop             rbx
        cmp             rax, 0
        je              exit

check_base:
        ; rdi = base
        call            _ft_strlen
        cmp             rax, 0
        je              exit_loop

check_base_loop:
        mov             rcx, 0
        push            rax
        cmp             rcx, rax
        jge             return
        cmp             byte [rdi + rcx], 43
        je              exit_loop
        cmp             byte [rdi + rcx], 45
        je              exit_loop
        cmp             byte [rdi + rcx], 32
        jle             exit_loop
        cmp             byte [rdi + rcx], 126
        jg              exit_loop
        push            rdi
        push            rsi
        push            rcx
        mov             rsi, byte [rdi + rcx]
        mov             rdi, rcx
        add             rdi, 1
        call            _find_char_base
        pop             rcx
        pop             rsi
        pop             rdi
        cmp             rax, 0
        jge             exit_loop
        inc             rcx
        jmp             check_base_loop

return:
        pop             rax
        mov             rax, rax
        ret

exit_loop:
        mov             rax, 0
        ret


_find_char_base:
        mov             rcx, 0
        cmp             byte [rdi + rcx], 0
        je              _find_end
        cmp             byte [rdi + rcx], rsi
        je              _find_index
        inc             rcx
        jmp             _find_char_base

_find_index:
        mov             rax, rcx
        ret

_find_end:
        mov             rax, -1
        ret


exit:
        xor             rax, rax
        ret
