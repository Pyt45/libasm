        global      _ft_strlen
        section     .text

_ft_strlen:
        mov         rax, -1
        jmp         ft_strlen_loop

ft_strlen_loop:
        inc         rax
        cmp         byte[rdi + rax], 0
        jne         ft_strlen_loop
        ret