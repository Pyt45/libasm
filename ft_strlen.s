        global      _ft_strlen
        section     .text

_ft_strlen:
        mov         rax, -1
        jmp         _ft_strlen_loop

_ft_strlen_loop:
        inc         rax
        cmp         byte[rdi + rax], 0
        jne         _ft_strlen_loop
        ret