        global          _ft_new_list
        section         .text
        extern          _malloc

_ft_new_list:
        xor             rax, rax
        push            rdi
        mov             rdi, 16
        call            _malloc
        pop             rdi
        mov             qword [rax], rdi
        mov             qword[rax + 8], 0
        ret