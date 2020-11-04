#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

typedef struct 		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;


int		ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v'
	|| c == '\n' || c == '\f' || c == '\r');
}

int		find_char_base(char *base, char c)
{
	int		i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int		ft_atoi_base1(char *str, char *base)
{
	int		base_len;
	int		num;
	int		sign;

	num = 0;
	base_len = strlen(base);
	if (base_len < 2)
		return (0);
	sign = (*str == '-') ? 1 : 0;
	str += (str[0] == '+' || str[0] == '-') ? 1 : 0;
	while (ft_isspace(*str))
		str++;
	while (find_char_base(base, *str) < base_len)
		num = (num * base_len) - find_char_base(base, *str++);
	return (sign ? num : -num);
}

t_list		*ft_new_list(void	*data)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}

void		ft_list_push_front1(t_list **begin_list, void *data)
{
	t_list	*list;

	if ((*begin_list) == NULL)
		*begin_list = ft_new_list(data);
	else
	{
		list = ft_new_list(data);
		list->next = *begin_list;
		*begin_list = list;
	}
	
}

void	print_list(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
}

int		ft_list_size1(t_list *begin_list)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = begin_list;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void ft_list_remove_if1(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*current;
	t_list	*last;

	tmp = NULL;
	current = *begin_list;
	last = NULL;
	while (current)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
				if (current == *begin_list)
					*begin_list = current;
				else
					last->next = current->next;
				tmp = current;
				current = current->next;
				free(tmp);
		}
		else
		{
			last = current;
			current = current->next;
		}
	}
}

void	ft_list_sort1(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	t_list	*head;
	void	*data_sort;

	head = *begin_list;
	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if ((*cmp)(head->data, tmp->data) > 0)
			{
				data_sort = head->data;
				head->data = tmp->data;
				tmp->data = data_sort;
			}
			tmp = tmp->next;
		}
		head = head->next;
	}
}

// void ft_bzero(void* addr, long unsigned len);

int			test(char *str);

size_t		ft_strlen(char *str);
char		*ft_strcpy(char *dst, char *src);
int			ft_strcmp(char *s1, char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t nbyte);
ssize_t		ft_read(int fd, void *buf, size_t nbyte);
char		*ft_strdup(char *str);
void		ft_list_push_front(t_list **begin_list, void *data);
int			ft_list_size(t_list *begin_list);
// void 	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
// void		ft_list_sort(t_list **begin_list, int (*cmp)());
// int		ft_atoi_base(char *str, char *base);

/* int		check_base(char c, char *base)
{
	int		i;

	i = 0;
	while(base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		n;
	int		sign;
	int		i;
	int		index;
	int		base_len;

	base_len = 0;
	i = 0;
	index = 0;
	sign = 1;
	while (base[base_len])
		base_len++;
	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	while (str[i])
	{
		index = check_base(str[i], base);
		if (index >= 0)
			n = (n * base_len) + index;
		i++;
	}
	return (n * sign);
} */

int main()
{
	t_list	*list;
	t_list	*list1;

	list = NULL;
	list1 = NULL;
	list1 = ft_new_list(strdup("a"));
	ft_list_push_front1(&list1, strdup("d"));
	ft_list_push_front1(&list1, strdup("c"));
	ft_list_push_front1(&list1, strdup("e"));
	print_list(list1);
	printf("\n=================================\n\n");
	list = ft_new_list(strdup("a"));
	ft_list_push_front(&list, strdup("d"));
	ft_list_push_front(&list, strdup("c"));
	ft_list_push_front(&list, strdup("e"));
	print_list(list); 
	/* ft_list_push_front1(&list, strdup("c"));
	ft_list_push_front1(&list, strdup("b"));
	ft_list_push_front1(&list, strdup("e"))*/;
	/* int lst_len1 = ft_list_size1(list);
	printf("orig == %d\n", lst_len1);
	int lst_len = ft_list_size(list);
	printf("mine == %d\n", lst_len); */
	//}

	// char	*str;
	// char	dest[10];
	// str = malloc(sizeof(char) * 5);
	//printf("%d\n", ft_strlen(NULL));
	// printf("mine == %zu\n", ft_strlen("NULL"));
	// printf("orig == %zu\n", strlen("NULL"));
	// printf("mine == %zu\n", ft_strlen(""));
	// printf("orig == %zu\n", strlen(""));
	// printf("mine == %zu\n", ft_strlen(NULL));
	// printf("orig == %zu\n", strlen(NULL));

	//printf("mine == %s|\n", ft_strcpy(dest, NULL));
	//printf("orig == %s|\n", strcpy(dest, NULL));
	//printf("mine == %s|\n", ft_strcpy(dest, "hello"));
	//printf("orig == %s|\n", strcpy(dest, "hello"));
	//printf("mine == %s|\n", ft_strcpy(NULL, NULL));
	//printf("orig == %s|\n", strcpy(NULL, NULL));
	//printf("mine == %s|\n", ft_strcpy(NULL, "hello"));
	//printf("orig == %s|\n", strcpy(NULL, "hello"));

	// printf("mine == %d\n", ft_strcmp("abe", "abe"));
	// printf("orig == %d\n",    strcmp("abe", "abe"));
	// printf("mine == %d\n", ft_strcmp("ab", "abea"));
	// printf("orig == %d\n",    strcmp("ab", "abea"));
	// printf("mine == %d\n", ft_strcmp("abe", "ab"));
	// printf("orig == %d\n",    strcmp("abe", "ab"));
	// // printf("mine == %d\n", ft_strcmp("abex", NULL));
	// // printf("orig == %d\n",    strcmp("abex", NULL));   // segf
	// // printf("mine == %d\n", ft_strcmp(NULL, "eve"));
	// // printf("orig == %d\n",    strcmp(NULL, "eve"));	 // segf
	// printf("mine == %d\n", ft_strcmp("b", ""));
	// printf("orig == %d\n",    strcmp("b", ""));
	// printf("mine == %d\n", ft_strcmp("", ""));
	// printf("orig == %d\n",    strcmp("", ""));
	// // Emmm intresting
	// printf("|MINE| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("\xff\xff", "\xff"));
    // printf("|ORIG| ==> the return value of    strcmp is |%d|\n",  strcmp("\xff\xff", "\xff"));
	// printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("", "hello"));
	// printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("", "hello"));

	// printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("h", "h"));
	// printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("h", "h"));

	// printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("hello", "helloa"));
	// printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("hello", "helloa"));

	// printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("helloa", "hello"));
	// printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("helloa", "hello"));

	// printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("hella", "hello"));
	// printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("hella", "hello"));
	// printf("%d\n", (int)ft_write(1, "NULL\n", 5));
	// printf("%d\n", (int)write(1, "NULL\n", 5));
	// printf("%d\n", (int)ft_write(1, NULL, 5));
	// printf("%d\n", (int)write(1, NULL, 5));
	// printf("%d\n", (int)ft_write(-1, "NULL\n", 5));
	// printf("%d\n", (int)write(-1, "NULL\n", 5));
	// printf("%d\n", (int)ft_write(42, "NULL\n", 5));
	// printf("%d\n", (int)write(42, "NULL\n", 5));

	// printf("%d | %s\n", (int)ft_read(1, str, 5), str);
	// printf("%d | %s\n", (int)read(1, str, 5), str);
	// printf("%d | %s\n", (int)ft_read(-1, str, 5), str);
	// printf("%d | %s\n", (int)read(-1, str, 5), str);
	// printf("%d | %s\n", (int)ft_read(42, str, 5), str);
	// printf("%d | %s\n", (int)read(42, str, 5), str);
	// printf("%d | %s\n", (int)ft_read(1, NULL, 5), str);
	// printf("%d | %s\n", (int)read(1, NULL, 5), str);

	// printf("mine == |%s|\n", ft_strdup("Hello"));
	// printf("orig == |%s|\n", strdup("Hello"));
	// printf("mine == %s\n", ft_strdup(NULL));
	//printf("orig == %s\n", strdup(NULL));
	// printf("mine == |%s|\n", ft_strdup(""));
	// printf("orig == |%s|\n", strdup(""));
	
	// char        s[5] = "hello";
	// char		s1[5] = "hello";
    // int            bz;
    // ssize_t        n;

    // /* write */
    // int fd1 = open("./test1", O_WRONLY|O_RDWR, S_IRUSR|S_IWUSR);
    // int fd2 = open("./test2", O_WRONLY|O_RDWR, S_IRUSR|S_IWUSR);

    // n = ft_write(fd1, s1, 5);
    // printf("\n|M| ==> the return value of ft_write is |%ld|\n", n);
    // printf("errno = |%d|\n", errno);

    // n =    write(fd2, s, 5);

    // printf("\n|O| ==> the return value of    write is |%ld|\n", n);
    // printf("errno = |%d|\n", errno);
    // close(fd1);
    // close(fd2);

	return (0);
}


// size_t		ft_strlen(char *str);
// char		*ft_strcpy(char *dst, const char *src);
// int			ft_strcmp(const char *s1, const char *s2);
// ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
// ssize_t		ft_read(int fildes, const void *buf, size_t nbyte);
// char		*ft_strdup(const char *src);

// int			main(void)
// {
// 	// int			bz;
// 	// int 		fd1;
// 	// int			fd2;
// 	// ssize_t		n;
// 	// char		s[64] = "Hello, World!";
// 	// char		dest[10];
	
// 	// bz = 12;
// 	// char test[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//     // ft_bzero(test, ZEROED_LEN);
//     // printf("%d\n", test[0]);
//     // printf("%d\n", test[1]);
//     // printf("%d\n", test[2]);
//     // printf("%d\n", test[3]);
//     // printf("%d\n", test[4]);
//     // printf("%d\n", test[5]);
//     // printf("%d\n", test[6]);
//     // printf("%d\n", test[7]);
//     // printf("%d\n", test[8]);
//     // printf("%d\n", test[9]);
// 	/* 
// 	 * write  
// 	 */
//  	// fd1 = open("./test1", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
// 	// fd2 = open("./test2", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
// 	// n = ft_write(fd1, s, bz);
// 	// printf("\n|M| ==> the return value of ft_write is |%ld|\n", n);
// 	// printf("errno = |%d|", errno);
// 	// n =    write(fd2, s, bz);
// 	// printf("\n|O| ==> the return value of    write is |%ld|\n", n);
// 	// printf("errno = |%d|\n", errno);
// 	// close(fd1);
// 	// close(fd2); 
// 	/*
// 	 ** read 
// 	 */
//  	// fd1 = open("test1", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
// 	// fd2 = open("test2", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
// 	// n = ft_read(fd1, s, bz);
// 	// printf("\n|M| ==> the return value of ft_read is |%zd| and s=|%s|\n", n, s);
// 	// printf("errno = |%d|\n", errno);
// 	// n =    read(fd2, s, bz);
// 	// printf("|O| ==> the return value of    read is |%zd| and s=|%s|\n", n, s);
// 	// printf("errno = |%d|\n", errno);
// 	// close(fd1);
// 	// close(fd2); 
// 	/* 
// 	//  * strdup 
// 	//  */
// 	/* printf("|M| ==> string by ft_strdup is |%s|\n", ft_strdup("NULL"));
// 	printf("errno = |%d|\n", errno);
// 	printf("|O| ==> string by    strdup is |%s|\n",  strdup("NULL"));
// 	printf("errno = |%d|\n", errno); */
// 	// /* 
// 	//  * strlen 
// 	//  */
//  	//printf("|M| ==> Return value by ft_strlen = |%zu|\n", ft_strlen(s));
// 	//printf("|O| ==> Return value by    strlen = |%zu|\n", strlen(s)); 
// 	//printf("%zu\n", ft_strlen(NULL));
// 	// printf("mine == %zu\n", ft_strlen("NULL"));
// 	// printf("origin == %zu\n", strlen("NULL"));
// 	// printf("mine == %zu\n", ft_strlen("-1"));
// 	// printf("origin == %zu\n", strlen("-1"));
// 	// /* 
// 	//  * strcpy 
// 	//  */
// 	// printf("|M| ==> the dest1 by ft_strcpy is |%s|\n", ft_strcpy(s, "How are you ?"));
// 	// printf("|O| ==> the dest2 by    strcpy is |%s|\n", strcpy(s, "How are you ?"));
// 	//printf("%s|\n", ft_strcpy(dest, NULL));
// 	//printf("%s|\n", ft_strcpy(dest, "hello"));
// 	//printf("mine = %s|\n", ft_strcpy(dest, "hello"));
// 	//printf("origin = %s|\n", strcpy(dest, "hello"));
// 	//printf("%s|\n", ft_strcpy(dest, NULL));
// 	//printf("%s|\n", ft_strcpy(NULL, "hello"));
// 	// /* 
// 	//  * strcmp 
// 	//  */
// 	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("", "hello"));
// 	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("", "hello"));
// 	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("h", "h"));
// 	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("h", "h"));
// 	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("hello", "helloa"));
// 	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("hello", "helloa"));
// 	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("helloa", "hello"));
// 	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("helloa", "hello"));
// 	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("hella", "hello"));
// 	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("hella", "hello"));
// 	return (0);
// }

/* ft_strdup:
        call            ft_strlen
        mov             r8, rax
        add             r8, 1
        call            malloc
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
       ret */

/* ft_strcmp:
        mov             rcx, -1

ft_strcmp_do:
        ;xor             rax, rax
        inc             rcx
        ;xor             rcx, rcx
        mov             dl, byte[rdi + rcx]
        mov             dh, byte[rsi + rcx]
        cmp             dl, 0
        je              ft_strcmp_end0
        cmp             dl, dh
        je              ft_strcmp_do
        jl              ft_strcmp_l
        jg              ft_strcmp_g

ft_strcmp_end0:
        cmp             dh, 0
        jne             ft_strcmp_l
        xor             rax, rax
        ret

ft_strcmp_l:
        mov             rax, -1
        ret

ft_strcmp_g:
        mov             rax, 1
        ret */


/* algo of ft_list_size
ft_list_size:
		xor				rcx, rcx
		cmp				rdi, byte 0
		je				end ; 0
		inc				rcx
		; ===== next =====
		mov				rdi, [rdi + 8]
		cmp				rdi, byte 0
		je				end ; 1
		inc				rcx
		; ===== next =====

		mov				rdi, [rdi + 8]
		cmp				rdi, byte 0
		je				end ; 2
		inc				rcx
end:
		mov				rax, rcx ; 3
		ret */


/* 			section	.text
			global	_ft_list_sort

; delete RCX, R8 and RAX

_ft_list_sort:							; rdi = t_list **begin, rsi = int (*cmp)(d1, d2)
			push	rbx					; save rbx (next)
			push	r12					; save r12 (first)
			cmp		rdi, 0				; begin == NULL
			jz		restore
			mov		r12, [rdi]			; first = *begin
			cmp		rsi, 0				; cmp == NULL
			jz		return
			jmp		compare_main
increment_main:
			mov		rcx, [rdi]
			mov		rbx, [rcx + 8]
			mov		[rdi], rbx			; *begin = (*begin)->next
compare_main:
			cmp		QWORD [rdi], 0		; !*begin
			jz		return
			mov		rcx, [rdi]
			mov		rbx, [rcx + 8]		; current = (*begin)->next
compare_single:
			cmp		rbx, 0				; !current
			jz		increment_main
compare:
			push	rdi
			push	rsi
			mov		rax, rsi
			mov		rcx, [rdi]
			mov		rdi, [rcx]			; rdi = (*begin)->data
			mov		rsi, [rbx]			; rsi = current->data
			call	rax					; (*cmp)((*begin)->data, current->data)
			pop		rsi
			pop		rdi
			cmp		rax, 0				; cmp > 0
			jg		swap
increment_single:
			mov		rcx, [rbx + 8]
			mov		rbx, rcx			; current = current.next
			jmp		compare_single
swap:
			mov		r8, [rdi]
			mov		rcx, [r8]			; rcx = (*begin)->data
			mov		rax, [rbx]			; rax = current->data
			mov		[r8], rax			; (*begin)->data = current->data
			mov		[rbx], rcx			; current->data = (*begin)->data
			jmp		increment_single
return:
			mov		[rdi], r12			; *begin = first
restore:
			pop		r12					; restore r12
			pop		rbx					; restore rbx
			ret */


/* 			section	.text
			global	_ft_list_remove_if
			extern	_free

; delete RDI, R8 and everything that RDX, RCX and free destroy

_ft_list_remove_if:						; rdi = t_list **begin, rsi = *data_ref
										; rdx = int (*cmp)(data, data_ref), rcx = void (*free_fct)(data)
			push	rbp					; save rbp (tmp)
			push	rbx					; save rbx (previous)
			push	r12					; save r12 (first)
			mov		r12, [rdi]			; first = *begin
			xor		rbx, rbx			; previous = NULL
			cmp		rdi, 0				; begin == NULL
			jz		return
			cmp		rdx, 0
			jz		return
			cmp		rcx, 0
			jz		return
			jmp		compare_start
free_elt:
			mov		r8, [rdi]
			mov		rbp, [r8 + 8]		; tmp = (*begin)->next
			push	rsi
			push	rdx
			push	rcx
			push	rdi
			mov		rdx, [rdi]
			mov		rdi, [rdx]
			call	rcx					; (*free_fct)((*begin)->data)
			pop		rdi
			push	rdi
			mov		rdx, [rdi]
			mov		rdi, rdx
			call	_free				; free(*begin)
			pop		rdi
			pop		rcx
			pop		rdx
			pop		rsi
			mov		[rdi], rbp			; *begin = tmp
			cmp		rbx, 0				; previous == NULL
			jnz		set_previous_next
			mov		r12, rbp			; first == tmp
			jmp		compare_start
set_previous_next:
			mov		[rbx + 8], rbp		; previous.next = tmp
			jmp		compare_start
compare_null:
			xor		rdi, rsi
			mov		rax, rdi
			jmp		compare_end
move_next:
			mov		rbx, [rdi]
			mov		r8,	[rbx + 8]		; tmp = (*begin)->next
			mov		[rdi], r8			; *begin = tmp
compare_start:
			cmp		QWORD [rdi], 0		; *begin == NULL
			jz		return
			push	rdi
			push	rsi					; data_ref already in rsi
			push	rdx
			push	rcx
			mov		r8, [rdi]
			mov		rdi, [r8]			; (*begin)->data in rdi
			cmp		rdi, 0				; (*begin)->data == NULL
			jz		compare_null
			call	rdx					; (*cmp)((*begin)->data, data_ref)
compare_end:
			pop		rcx
			pop		rdx
			pop		rsi
			pop		rdi
			cmp		rax, 0				; (*cmp) == 0
			jz		free_elt			; (*free_fct)
			jmp		move_next
return:
			mov		[rdi], r12			; *begin = first
			pop		r12					; restore rbx
			pop		rbx					; restore rbx
			pop		rbp					; restore rbp
			ret */

/* global _ft_list_sort

%define NULL 0x0

; void ft_list_sort(t_list **begin_list, int (*cmp)(void*, void*));
_ft_list_sort:
	; t_list *slow   : rax = *begin_list
	; t_list *fast   : rbx = (*begin_list)->next
	; t_list *middle : rsp + 0

	; === base condition ===
	cmp  rdi, NULL
	je   FT_LIST_SORT_END              ; if begin_list == NULL return
	mov  rax, [rdi]
	cmp  rax, NULL
	je   FT_LIST_SORT_END              ; if *begin_list == NULL return
	mov  rbx, [rax + 8]
	cmp  rbx, NULL
	je   FT_LIST_SORT_END              ; if (*begin_list)->next == NULL return

	; === find list middle loop ===
FT_LIST_SORT_MIDDLE_LOOP:              ; do {
	mov  rbx, [rbx + 8]                ;     fast = fast->next
	cmp  rbx, NULL
	je   FT_LIST_SORT_MIDDLE_LOOP_END  ;     if fast == NULL break
	mov  rbx, [rbx + 8]                ;     fast = fast->next
	mov  rax, [rax + 8]                ;     slow = slow->next
	cmp  rbx, NULL
	jne  FT_LIST_SORT_MIDDLE_LOOP      ; } while (fast != NULL)
FT_LIST_SORT_MIDDLE_LOOP_END:

	; create a stack frame for local variable to store middle address
	push rbp
	mov  rbp, rsp
	sub  rsp, 8

	; store middle in [rbp - 8]
	mov  rcx, [rax + 8]
	mov  [rbp - 8], rcx
	mov  qword [rax + 8], NULL         ; slow->next = NULL

	; === sorting both child list ===
	push rdi
	push rsi
	call _ft_list_sort                 ; ft_list_sort(begin_list, cmp)
	lea  rdi, [rbp - 8]
	call _ft_list_sort                 ; ft_list_sort(&middle, cmp)
	pop  rsi
	pop  rdi

	; === merging sorted child ===
	push rdi
	push rsi
	mov  rdi, [rdi]                    ; arg_1 = *begin_list
	mov  rdx, rsi                      ; arg_3 = cmp
	mov  rsi, [rbp - 8]                ; arg_2 = middle
	call _st_merge_sorted_list
	pop  rsi
	pop  rdi
	mov  [rdi], rax                    ; *begin_list = st_merge_sorted_list(...);

	; restoring stack frame
	mov  rsp, rbp
	pop  rbp
FT_LIST_SORT_END:
	ret


; t_list *st_merge_sorted_list(t_list* l1, t_list* l2, int (*cmp)(void*, void*))
_st_merge_sorted_list:
	cmp  rdi, NULL
	je   MERGE_SORTED_LIST_RETURN_L2   ; if l1 == NULL return l2
	cmp  rsi, NULL
	je   MERGE_SORTED_LIST_RETURN_L1   ; if l2 == NULL return l1

	push rdi
	push rsi
	push rdx
	mov  rdi, [rdi + 0]                ; l1->data
	mov  rsi, [rsi + 0]                ; l2->data
	xor  rax, rax
	call rdx                           ; cmp
	pop  rdx
	pop  rsi
	pop  rdi

	cmp  eax, 0
	jl   MERGE_SORTED_LIST_L1_LT_L2

	; if l1 >= l2
	push rsi                           ; save l2
	mov  rsi, [rsi + 8]                ; l2 = l2->next
	call _st_merge_sorted_list         ; merge_sorted_list(l1, l2->next, cmp)
	pop  rsi                           ; restore rsi
	mov  [rsi + 8], rax
	mov  rax, rsi
	jmp  MERGE_SORTED_LIST_END
	; else
MERGE_SORTED_LIST_L1_LT_L2:
	push rdi
	mov  rdi, [rdi + 8]
	call _st_merge_sorted_list         ; merge_sort_list(l1->next, l2, cmp)
	pop  rdi
	mov  [rdi + 8], rax
	mov  rax, rdi
	jmp  MERGE_SORTED_LIST_END

MERGE_SORTED_LIST_RETURN_L1:
	mov  rax, rdi
	ret
MERGE_SORTED_LIST_RETURN_L2:
	mov  rax, rsi
MERGE_SORTED_LIST_END:
	ret */

/* global _ft_list_remove_if

extern _free

%define NULL 0x0

%macro EXTERN_FUNCTION_SAVE 0
	push rdi
	push rsi
	push rdx
	push rcx
%endmacro

%macro EXTERN_FUNCTION_SAVE_END 0
	pop  rcx
	pop  rdx
	pop  rsi
	pop  rdi
%endmacro

; ft_list_remove_if(t_list **begin_list, void *data_ref,
;                   int (*cmp)(void *data, void *data_ref),
;                   void (*free_fct)(void *))
_ft_list_remove_if:
	; t_list *saved_next

	; === prolog ===
	push rbp
	mov  rbp, rsp
	sub  rsp, 8

	; === base condition ===
	cmp  rdi, NULL
	je   FT_LIST_REMOVE_IF_END
	cmp  qword [rdi], NULL
	je   FT_LIST_REMOVE_IF_END

	; === compare (*begin_list)->data and data_ref
	EXTERN_FUNCTION_SAVE
	mov  rdi, [rdi]
	mov  rdi, [rdi + 0] 
	call rdx                         ; cmp((*begin_list)->data, data_ref)
	EXTERN_FUNCTION_SAVE_END
	cmp  rax, 0
	je   FT_LIST_REMOVE_IF_REMOVE

	; === next element ===
	push rdi
	mov  rdi, [rdi]
	lea  rdi, [rdi + 8]
	call _ft_list_remove_if
	pop  rdi
	jmp  FT_LIST_REMOVE_IF_END

	; === remove head and go next ===
FT_LIST_REMOVE_IF_REMOVE:
	mov  rax, [rdi]                    ; rax = *begin_list
	mov  rax, [rax + 8]                ; rax = rax->next
	mov  [rbp - 8], rax                ; saved_next = (*begin_list)->next

	push rdi                           ; strange behavior
	EXTERN_FUNCTION_SAVE
	mov  rdi, [rdi]
	mov  rdi, [rdi + 0]
	call rcx                           ; free_fct((*begin_list)->data)
	EXTERN_FUNCTION_SAVE_END
	pop  rdi

	EXTERN_FUNCTION_SAVE
	mov  rdi, [rdi]
	call _free                         ; free(*begin_list)
	EXTERN_FUNCTION_SAVE_END

	mov rax, [rbp - 8]
	mov [rdi], rax
	call _ft_list_remove_if

FT_LIST_REMOVE_IF_END:
	; === epilog ===
	mov  rsp, rbp
	pop  rbp
	ret */
 /*            global          _ft_list_sort
            section         .text

_ft_list_sort:
            mov     rcx, 1
_loop_changed:
            cmp     rcx, 0
            je      _end_loop_changed
            mov     rcx, 0
            mov     r9, [rdi]
            call    _loop_list
            jmp     _loop_changed

_end_loop_changed:
            ret


_loop_list:
            cmp     r9, byte 0
            je      _end_loop_list
            mov     r8, [r9+8]
            cmp     r8, byte 0
            je      _end_loop_list
            mov     rdx, rsi
            push    rdi
            push    rsi
            mov     rdi, [r9]
            mov     rsi, [r8]
            sub     rsp, 40
            call    rdx
            add     rsp, 40
            pop     rsi
            pop     rdi
            cmp     rax, 127 
            jl      _swap_data
            mov     r9, [r9+8]
            jmp     _loop_list

_swap_data:
            mov     rdx, [r9]
            mov     rbx, [r8]
            mov     [r9], rbx
            mov     [r8], rdx
            mov     rcx, 1
            mov     r9, [r9+8]
            jmp     _loop_list

_end_loop_list:
            ret */
/* 
            global      _ft_list_remove_if
            extern      _free
            section     .text

_ft_list_remove_if:
            xor         r10, r10
            mov         rbx, rsi
            mov         r14, rdi
            mov         r12, rdx
            mov         r9, [rdi]
            call        _loop_rem
            mov         rdi, r14
            mov         [rdi], rax
            cmp         r9, byte 0
            jne         _do_prev
            ret

_loop_rem:
            cmp         r9, byte 0
            je          _end_loop_rem
            mov         rdi, [r9]
            mov         rax, r12
            mov         rsi, rbx
            sub         rsp, 40
            call        rax
            add         rsp, 40
            cmp         rax, 0
            je          _remove_elt
            mov         rax, r9
            ret

_remove_elt:
            mov         rcx, [r9+8]
            push        rcx
            push        rbx
            push        r14
            push        r12
            mov         rdi, r9
            call        _free
            pop         r12
            pop         r14
            pop         rbx
            pop         rcx
            mov         r9, rcx
            mov         rax, r9
            jmp         _loop_rem

_end_loop_rem:
            ret

_do_prev:
            mov         r8, r9
            mov         r9, [r9+8]
            jmp         _loop_list

_free_list:
            mov         [r8+8], r10
            push        rcx
            push        rbx
            push        r14
            push        r12
            push        r10
            mov         rdi, r9
            call        _free
            pop         r10
            pop         r12
            pop         r14
            pop         rbx
            pop         rcx
            mov         r9, r10
            jmp         _loop_list
_loop_list: 
            cmp         r9, byte 0
            je          _end_loop_list
            mov         r10, [r9+8]
            mov         rdi, [r9]
            mov         rsi, rbx
            mov         rax, r12
            sub         rsp, 40
            call        rax
            add         rsp, 40
            cmp         rax, 0
            je          _free_list
            mov         r8, r9
            mov         r9, [r9+8]
            jmp         _loop_list

_end_loop_list:
            ret */