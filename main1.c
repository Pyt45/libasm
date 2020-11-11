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

t_list		*ft_new_list1(void	*data)
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
		*begin_list = ft_new_list1(data);
	else
	{
		list = ft_new_list1(data);
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
		if (tmp->next)
			printf("%s --> ", tmp->data);
		else
			printf("%s", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
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
					*begin_list = current->next;
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

// int			test(char *str);

// size_t		ft_strlen(char *str);
// char		*ft_strcpy(char *dst, char *src);
// int			ft_strcmp(char *s1, char *s2);
// ssize_t		ft_write(int fd, const void *buf, size_t nbyte);
// ssize_t		ft_read(int fd, void *buf, size_t nbyte);
// char		*ft_strdup(char *str);
void		ft_list_push_front(t_list **begin_list, void *data);
int			ft_list_size(t_list *begin_list);
t_list		*ft_new_list(void	*data);
void 	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
void		ft_list_sort(t_list **begin_list, int (*cmp)());
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
	char	*s = "2";
	
	list = NULL;
	list = ft_new_list(strdup("1"));
	ft_list_push_front(&list, strdup("2"));
	ft_list_push_front(&list, strdup("3"));
	ft_list_push_front(&list, strdup("4"));
	ft_list_push_front(&list, strdup("5"));
	ft_list_push_front(&list, strdup("6"));
	print_list(list);
	printf("\n===================\n\n");
	ft_list_remove_if1(&list, s, strcmp);
	print_list(list);
	//ft_list_remove_if(&list, strdup("1"), strcmp);
	//printf("\n===================\n\n");
	//print_list(list);
	// ft_list_push_front1(&list1, strdup("d"));
	// ft_list_push_front(&list, strdup("d"));
	// print_list(list);
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

/* 				global		ft_list_remove_if
				section		.text

				extern		free

%define			NULL		dword 0x0

; void	ft_list_remove_if(
;	t_list **begin_list			-> rdi,
;	void *data_ref				-> rsi,
;	int (*cmp)()				-> rdx,
;	void (*free_fct)(void *)	-> rcx
; )

;	t_list *tmp					-> r8
;	*begin_list					-> r9

ft_list_remove_if:
				; if (!begin_list)
				cmp			rdi, 0
				je			end

				; if (!*begin_list)
				cmp			[rdi], NULL
				je			end

				; if (!data_ref)
				cmp			rsi, 0
				je			end

				; if (!cmp)
				cmp			rdx, 0
				je			end

				; if (!free_fct)
				cmp			rcx, 0
				je			end

				; getting *begin_list
				mov			r9, [rdi]

calling:
				push		rdi
				push		rsi
				push		rdx
				push		rcx

				; ; moving in rdi (*begin_list)->data, no need to move data_ref in rsi
				; ; because it's already in there
				mov			rdi, [r9]
				call		rdx

				pop			rcx
				pop			rdx
				pop			rsi
				pop			rdi

				; cmp(...) == 0 then goto delone
				cmp			eax, dword 0
				je			delone

				; else recursive call
				push		rdi
				push		rsi
				push		rdx
				push		rcx

				mov			r9, [rdi]
				add			r9, 8			; <=> &(*begin_list)->next
				mov			rdi, r9

				; recursive call of ft_list_remove_if in the case where we ignore
				; the current element
				call		ft_list_remove_if

				pop			rcx
				pop			rdx
				pop			rsi
				pop			rdi

				jmp			end

delone:
				; preparing tmp, and *begin_list
				mov			r9, [rdi]
				mov			r8, r9

				; (*begin_list)->next and affecting it to *begin_list
				mov			r9, [r9 + 8]
				mov			[rdi], r9

				; preparing the call of free_fct and calling it
				push		rdi
				push		rsi
				push		rdx
				push		rcx
				push		r8

				mov			rdi, [r8]
				call		rcx

				; restoring tmp and free-ing it
				pop			r8
				mov			rdi, r8
				call		free

				; restoring all register before doing the recursive call
				pop			rcx
				pop			rdx
				pop			rsi
				pop			rdi

				; preparing and doing the recursive call then restoring registers
				push		rdi
				push		rsi
				push		rdx
				push		rcx

				; recursive call of ft_list_remove_if with the previous registers
				call		ft_list_remove_if

				pop			rcx
				pop			rdx
				pop			rsi
				pop			rdi

end:
				ret */





/* ; Assembly ft_list_remove_if
; For Linux Systems

; ft_list_remove_if prototype:
;	void	ft_list_remove_if(t_list **begin_list, void *data_ref,
;	int (*cmp)());

; rdi = **begin_list
; rsi = *data_ref
; rdx = (*cmp)()

				global		ft_list_remove_if
				extern		free

ft_list_remove_if:
				push		rbp
				mov			rbp, rsp

				test		rdi, rdi		; check if begin_list == NULL
				jz			exit

				push		r12				; r12: pointer to previous
				push		r13				; r13: pointer to current
				push		r14				; r14: pointer to next
				mov			[rsp], rdx		; Storing (*cmp)() on the stack.

				sub			rsp, 16			; Storing **begin_list on stack.
				mov			[rsp], rdi

				sub			rsp, 16
				mov			[rsp], rsi		; Storing *data_ref on stack.

				xor			r12, r12		; r12 = 0, r13 = 0, r14 = 0
				xor			r13, r13
				xor			r14, r14

init_setup:		
				mov			r12, 0
				mov			rcx, [rsp + 16]
				mov			r13, [rcx]
				mov			r14, [r13 + 8]

loop:
				test		r13, r13
				jz			process_complete

test_data:
				mov			rdi, [r13]
				mov			rsi, [rsp]
				call		[rsp + 32]
				test		rax, rax
				jz			link_prev
				jmp			next_elem

link_prev:
				cmp			r12, 0
				je			new_head
				mov			[r12 + 8], r14
				jmp			next_elem

new_head:
				mov			rcx, [rsp + 16]
				mov			[rcx], r14

next_elem:
				mov			rcx, r13
				mov			r13, r14
				test		rax, rax
				jnz			set_new_prev

free_prev:
				mov			rdi, rcx
				sub			rsp, 8
				call		free
				add			rsp, 8
				jmp			set_new_next

set_new_prev:
				mov			r12, rcx
set_new_next:
				test		r14, r14
				jz			process_complete
				mov			r14, [r13 + 8]
				jmp			loop

process_complete:
				add			rsp, 48
				pop			r14
				pop			r13
				pop			r12

exit:
				mov			rsp, rbp
				pop			rbp
				ret */


/* ; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *)	
;									rdi				rsi				rdx			rcx
;	(*cmp)(list_ptr->data, data_ref);
;	(*free_fct)(list_ptr->data)


; r12 = stores the last undeleted element (t_list *)
; r13 = current element (t_list *)
; r14 = next element (t_list *)
; r15 = data of current element (void *)

section .text
	global ft_list_remove_if
	extern free

ft_list_remove_if:
	push rbp
	mov rbp, rsp

	cmp rdi, 0				; check all argument != NULL
	je return
	mov r12, [rdi]			; check all argument != NULL
	cmp r12, 0				; check all argument != NULL
	je return
	cmp rsi, 0
	je return
	cmp rdx, 0
	je return
	cmp rcx, 0
	je return

	sub rsp, 32				; CREATE SPACE ON STACK
	mov [rsp], rdx			; save to stack cmp function
	mov [rsp + 8], rcx		; save to stack free function
	mov [rsp + 16], rdi		; save to stack first argument (= pointer to first element)
	mov [rsp + 24], rsi		; save to stack data_ref

							; SET REGISTERS
	mov r12, rdi			; save first element pointer to r12, will be replace by previous element in the loop
	mov r13, [rdi]			; save current element to r13
	mov r14, [r13 + 8]		; save next element's address in r14
	mov r15, [r13]			; dereference current element to access its data
	jmp cmp_loop

next_element:
	
	cmp r14, 0
	je return
	mov r13, r14			; move to next element address
	mov r14, [r13 + 8]		; save current's next element address in r14
	mov r15, [r13]			; dereferenc rdi to access its data

cmp_loop:
	mov rdi, r15			; put data in rdi for cmp function
	mov rsi, [rsp + 24]		; reset data_ref
	call [rsp]				; call cmp function
	cmp rax, 0
	je erase_data
	mov r12, r13			; set current element in r12 before moving to next one
	jmp next_element
	
erase_data:
	mov rdi, r15			; put data in rdi for free function
	call [rsp + 8]			; call the free_fct to free data
	cmp [rsp + 16], r12		; check if current element is the first of the list
	je reattache_first_element
	mov [r12 + 8], r14		; set next elemen in the previou's next pointer : shortcut the current
	mov rdi, r13			; set current element address in rdi for free function
	call free				; free the element
	jmp next_element	

reattache_first_element:
	mov rax, [rsp + 16]		; get the pointer to the head of list
	mov [rax], r14			; change pointer content to make it point to current's next element
	mov rax, [rax]			; dereference it to access
	jmp next_element	

return:
	mov rdi, [rsp + 16]
	add rsp, 32

	mov rsp, rbp
	pop rbp
	ret */

/*


		; current = *begin
		push			r12 ; r12 = current = *begin
		;push			r9 ; r9 = last
		push			rbx ; rbx = tmp = current
		mov				r12, [rdi]
		cmp				rdi, 0
		je				end
		xor				rbx, rbx
		xor				r9, r9
		cmp				rdx, 0
		je				end
		jmp				big_loop

free_elt:
		mov				rbx, [rdi] ; tmp = current
		mov				rcx, [rdi]
		mov				r8, [rcx + 8]
		mov				[rdi], r8 ; current = current->next
		push			rdi
		mov				rdi, rbx
		call			free
		pop				rdi
		jmp				big_loop


give_it_add:
		mov				rcx, [rdi] ; rcx = current
		mov				rax, [rcx + 8] ; rax = current->next
		mov				r12, rax ; *begin = current->next
		jmp				free_elt

remove_elt:
		mov				rcx, r12 	; rcx = *begin
		mov				r8, [rdi] 	; r8 = current
		sub				r8, rcx
		cmp				r8, 0 		; current == *begin
		je				give_it_add
		mov				rcx, [rdi] ; rcx = current
		mov				rax, [rcx + 8] ; rax = current->next
		mov				[r9 + 8], rax ; last->next = current->next
		jmp				free_elt

big_loop:
		cmp				qword [rdi], 0 ; !(current)
		je				end
		push			rdi
		push			rsi
		mov				rcx, [rdi]
		mov				rdi, [rcx] ; rdi = current->dara
		call			rdx ; cmp(current->data, rsi = data_ref)
		pop				rsi
		pop				rdi
		cmp				rdx, 0
		jne				increment
		jmp				remove_elt

increment:
		mov				r9, [rdi] ; last = current
		mov				r8, [rdi]
		mov				rcx, [r8 + 8]
		mov				[rdi], rcx ; current = current->next
		jmp				big_loop

end:
		mov				[rdi], r12
		pop				rbx
		;pop				r9
		pop				r12
		ret
*/

/*

		; rdi = begin , rsi = data_ref , rdx = cmp
		; r8 --> tmp
		; r9 --> *begin
		cmp				rdi, 0 ; !begin
		je				end

		cmp				qword [rdi], 0 ; !(*begin)
		je				end

		cmp				rsi, 0 ; !data_ref
		je				end

		cmp				rdx, 0 ; !cmp
		je				end

		mov				r9, [rdi] ; r9 = (*begin)

do_remove:
		push			rdi
		push			rsi
		push			rdx

		mov				rdi, [r9]
		call			rdx
		pop				rdx
		pop				rsi
		pop				rdi
		cmp				rax, 0
		je				del_elt
		push			rdi
		push			rsi
		push			rdx

		; send &(*begin)->next to ft_remove_if
		; rdi = &(*begin)->next
		mov				r9, [rdi]
		add				r9, 8
		mov				rdi, r9

		call			ft_list_remove_if

		pop				rdx
		pop				rsi
		pop				rdi

		jmp				end

del_elt:
		mov				r9, [rdi]
		mov				r8, r9

		mov				r9, [r9 + 8]
		mov				[rdi], r9

		push			rdi
		push			rsi
		push			rdx
		push			r8

		mov				rdi, r8
		call			free

		pop				r8
		pop				rdx
		pop				rsi
		pop				rdi

		push			rdi
		push			rsi
		push			rdx

		call			ft_list_remove_if
		pop				rdx
		pop				rsi
		pop				rdi
end:
		ret
*/