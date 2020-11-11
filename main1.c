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

/* 			section	.text
			global	_ft_atoi_base

; delete R8, R9, R10 and RAX

_ft_atoi_base:								; rdi = *str, rsi = *base
			push	rbx						; save rbx (sign)
			push	r12						; save r12 (base_length)
			xor		rax, rax				; total = 0
			xor		rbx, rbx				; sign = 0
			xor		r12, r12				; base_length = 0
			jmp		base_check_loop
base_check_increment:
			inc		r12						; base_length++
base_check_loop:
			cmp		BYTE [rsi + r12], 0
			jz		base_check_end
			mov		r8, r12					; j = base_length
base_check_dup_inc:
			inc		r8						; j++
base_check_dup_loop:
			cmp		BYTE [rsi + r8], 0		; !base[j]
			jz		base_check_correct
			mov		r9b, [rsi + r8]
			cmp		BYTE [rsi + r12], r9b	; base[base_length] == base[j]
			je		set_rax
			jmp		base_check_dup_inc
base_check_correct:
			cmp		BYTE [rsi + r12], 32	; base[base_length] == ' '
			je		set_rax
			cmp		BYTE [rsi + r12], 43	; base[base_length] == '+'
			je		set_rax
			cmp		BYTE [rsi + r12], 45	; base[base_length] == '-'
			je		set_rax
			cmp		BYTE [rsi + r12], 9		; base[base_length] == '\t'
			je		set_rax
			cmp		BYTE [rsi + r12], 10	; base[base_length] == '\n'
			je		set_rax
			cmp		BYTE [rsi + r12], 13	; base[base_length] == '\r'
			je		set_rax
			cmp		BYTE [rsi + r12], 11	; base[base_length] == '\v'
			je		set_rax
			cmp		BYTE [rsi + r12], 12	; base[base_length] == '\f'
			je		set_rax
			jmp		base_check_increment
base_check_end:
			cmp		r12, 1					; base_length <= 1
			jle		set_rax
			xor		r8, r8					; i = 0
			jmp		skip_whitespaces
skip_whitespaces_inc:
			inc		r8						; i++
skip_whitespaces:
			cmp		BYTE [rdi + r8], 32		; str[i] == ' '
			je		skip_whitespaces_inc
			cmp		BYTE [rdi + r8], 9		; str[i] == '\t'
			je		skip_whitespaces_inc
			cmp		BYTE [rdi + r8], 10		; str[i] == '\n'
			je		skip_whitespaces_inc
			cmp		BYTE [rdi + r8], 13		; str[i] == '\r'
			je		skip_whitespaces_inc
			cmp		BYTE [rdi + r8], 11		; str[i] == '\v'
			je		skip_whitespaces_inc
			cmp		BYTE [rdi + r8], 12		; str[i] == '\f'
			je		skip_whitespaces_inc
			jmp		check_sign
is_negative:
			xor		bl, 0x00000001
is_positive:
			inc		r8
check_sign:
			cmp		BYTE [rdi + r8], 45		; str[i] == '-'
			je		is_negative
			cmp		BYTE [rdi + r8], 43		; str[i] == '+'
			je		is_positive
			jmp		atoi_loop
atoi_increment:
			inc		r8						; i++
atoi_loop:
			cmp		BYTE [rdi + r8], 0		; str[i] == 0
			je		set_rax
			xor		r9, r9					; j = 0
			jmp		atoi_idx
atoi_idx_inc:
			inc		r9						; j++
atoi_idx:
			mov		r10b, BYTE [rsi + r9]
			cmp		r10b, 0					; base[j] == 0
			je		set_rax
			cmp		BYTE [rdi + r8], r10b	; base[j] == str[i]
			jne		atoi_idx_inc
add_to_total:
			mul		r12						; total *= base_length
			add		rax, r9					; total += k
			jmp		atoi_increment
set_rax:
			mov		rax, rax				; ret = total
			cmp		rbx, 0					; sign is negative
			jz		return
			neg		rax						; ret = -ret
return:
			pop		r12						; restore r12
			pop		rbx						; restore rbx
			ret */