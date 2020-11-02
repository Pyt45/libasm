        global          ft_strdup
        section         .text
        extern          malloc
        extern          ft_strcpy
        extern          ft_strlen

ft_strdup:
         call            ft_strlen
         push            rdi
         mov             rdi, rax
         add             rdi, 1
         call            malloc
         pop             rsi
         mov             rdi, rax
         call            ft_strcpy
         ret