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
int		ft_list_size(t_list *begin_list);
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
	ft_list_push_front1(&list1, strdup("d"));
	print_list(list1);
	ft_list_push_front(&list, strdup("d"));
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