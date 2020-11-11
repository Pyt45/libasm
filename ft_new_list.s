        global          ft_new_list
        section         .text
        extern          malloc

ft_new_list:
        xor             rax, rax
        push            rdi
        mov             rdi, 16
        call            malloc
        pop             rdi
        mov             qword [rax], rdi
        mov             qword[rax + 8], 0
        ret