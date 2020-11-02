#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define ZEROED_LEN (10)

// void ft_bzero(void* addr, long unsigned len);

size_t		ft_strlen(char *str);
char		*ft_strcpy(char *dst, char *src);
int			ft_strcmp(char *s1, char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t nbyte);
ssize_t		ft_read(int fd, void *buf, size_t nbyte);
char		*ft_strdup(char *str);

// int main()
// {
// /* 	char	*str;
// 	char	dest[10];

// 	str = malloc(sizeof(char) * 5);
// 	int test = ft_read(20, dest, 10); */
// 	//printf("%d", test);
// 	//printf("%d\n", ft_strlen(NULL));
// 	//printf("%d\n", ft_strlen("NULL"));
// 	//printf("%d\n", ft_strlen(""));

// 	//printf("%s|\n", ft_strcpy(dest, NULL));
// 	//printf("%s|\n", ft_strcpy(dest, "hello"));
// 	//printf("%s|\n", ft_strcpy(NULL, NULL));
// 	//printf("%s|\n", ft_strcpy(NULL, "hello"));

// 	//printf("MY: %d\n", ft_strcmp("abe", "abe"));
// 	//printf("O : %d\n",    strcmp("abe", "abe"));
// 	//printf("MY: %d\n", ft_strcmp("ab", "abea"));
// 	//printf("O : %d\n",    strcmp("ab", "abea"));
// 	//printf("MY: %d\n", ft_strcmp("abe", "ab"));
// 	//printf("O : %d\n",    strcmp("abe", "ab"));
// 	//printf("MY: %d\n", ft_strcmp("abex", NULL));
// 	//printf("O : %d\n",    strcmp("abex", NULL));   // segf
// 	//printf("MY: %d\n", ft_strcmp(NULL, "eve"));
// 	//printf("O : %d\n",    strcmp(NULL, "eve"));	 // segf
// 	//printf("%d\n", ft_strcmp("b", ""));
// 	//printf("%d\n",    strcmp("b", ""));
// 	//printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("\xff\xff", "\xff"));
//     //printf("|O| ==> the return value of    strcmp is |%d|\n\n",  strcmp("\xff\xff", "\xff"));

// 	// printf("%d\n", (int)ft_write(1, "NULL\n", 5));
// 	// printf("%d\n", (int)write(1, "NULL\n", 5));
// 	// printf("%d\n", (int)ft_write(1, NULL, 5));
// 	// printf("%d\n", (int)write(1, NULL, 5));
// 	// printf("%d\n", (int)ft_write(-1, "NULL\n", 5));
// 	// printf("%d\n", (int)write(-1, "NULL\n", 5));
// 	printf("%d\n", (int)ft_write(42, "NULL\n", 5));
// 	printf("%d\n", (int)write(42, "NULL\n", 5));

// 	//printf("%d | %s\n", (int)ft_read(1, str, 5), str);
// 	//printf("%d | %s\n", (int)read(1, str, 5), str);
// 	//printf("%d | %s\n", (int)ft_read(-1, str, 5), str);
// 	//printf("%d | %s\n", (int)read(-1, str, 5), str);
// 	//printf("%d | %s\n", (int)ft_read(42, str, 5), str);
// 	//printf("%d | %s\n", (int)read(42, str, 5), str);
// 	//printf("%d | %s\n", (int)ft_read(1, NULL, 5), str);
// 	//printf("%d | %s\n", (int)read(1, NULL, 5), str);

// 	//printf("%s\n", ft_strdup("Hello"));
// 	//printf("%s\n", ft_strdup(NULL));
// 	//printf("%s\n", ft_strdup(""));
	
// 	// char        *s = NULL;
//     // int            bz;
//     // ssize_t        n;
//     // char        *s1="\xff";
//     // char        *s2="\xffh";

//     // bz = 40;

//     // /* write */
//     // int fd1 = open("./test1", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
//     // int fd2 = open("./test2", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
//     // n = ft_write(fd1, s, bz);
//     // printf("\n|M| ==> the return value of ft_write is |%ld|\n", n);
//     // printf("errno = |%d|\n", errno);
//     // n =    write(fd2, s, bz);
//     // printf("\n|O| ==> the return value of    write is |%ld|\n", n);
//     // printf("errno = |%d|\n", errno);
//     // close(fd1);
//     // close(fd2);

// 	return (0);
// }


// size_t		ft_strlen(char *str);
// char		*ft_strcpy(char *dst, const char *src);
// int			ft_strcmp(const char *s1, const char *s2);
// ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
// ssize_t		ft_read(int fildes, const void *buf, size_t nbyte);
// char		*ft_strdup(const char *src);

int			main(void)
{
	// int			bz;
	// int 		fd1;
	// int			fd2;
	// ssize_t		n;
	char		s[64] = "Hello, World!";
	char		dest[10];
	
	// bz = 12;
	// char test[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // ft_bzero(test, ZEROED_LEN);
    // printf("%d\n", test[0]);
    // printf("%d\n", test[1]);
    // printf("%d\n", test[2]);
    // printf("%d\n", test[3]);
    // printf("%d\n", test[4]);
    // printf("%d\n", test[5]);
    // printf("%d\n", test[6]);
    // printf("%d\n", test[7]);
    // printf("%d\n", test[8]);
    // printf("%d\n", test[9]);
	/* 
	 * write  
	 */
 	// fd1 = open("./test1", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
	// fd2 = open("./test2", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
	// n = ft_write(fd1, s, bz);
	// printf("\n|M| ==> the return value of ft_write is |%ld|\n", n);
	// printf("errno = |%d|", errno);
	// n =    write(fd2, s, bz);
	// printf("\n|O| ==> the return value of    write is |%ld|\n", n);
	// printf("errno = |%d|\n", errno);
	// close(fd1);
	// close(fd2); 
	/*
	 ** read 
	 */
 	// fd1 = open("test1", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
	// fd2 = open("test2", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
	// n = ft_read(fd1, s, bz);
	// printf("\n|M| ==> the return value of ft_read is |%zd| and s=|%s|\n", n, s);
	// printf("errno = |%d|\n", errno);
	// n =    read(fd2, s, bz);
	// printf("|O| ==> the return value of    read is |%zd| and s=|%s|\n", n, s);
	// printf("errno = |%d|\n", errno);
	// close(fd1);
	// close(fd2); 
	/* 
	//  * strdup 
	//  */
	/* printf("|M| ==> string by ft_strdup is |%s|\n", ft_strdup("NULL"));
	printf("errno = |%d|\n", errno);
	printf("|O| ==> string by    strdup is |%s|\n",  strdup("NULL"));
	printf("errno = |%d|\n", errno); */
	// /* 
	//  * strlen 
	//  */
 	//printf("|M| ==> Return value by ft_strlen = |%zu|\n", ft_strlen(s));
	//printf("|O| ==> Return value by    strlen = |%zu|\n", strlen(s)); 
	//printf("%zu\n", ft_strlen(NULL));
	// printf("mine == %zu\n", ft_strlen("NULL"));
	// printf("origin == %zu\n", strlen("NULL"));
	// printf("mine == %zu\n", ft_strlen("-1"));
	// printf("origin == %zu\n", strlen("-1"));
	// /* 
	//  * strcpy 
	//  */
	// printf("|M| ==> the dest1 by ft_strcpy is |%s|\n", ft_strcpy(s, "How are you ?"));
	// printf("|O| ==> the dest2 by    strcpy is |%s|\n", strcpy(s, "How are you ?"));
	//printf("%s|\n", ft_strcpy(dest, NULL));
	//printf("%s|\n", ft_strcpy(dest, "hello"));
	//printf("mine = %s|\n", ft_strcpy(dest, "hello"));
	//printf("origin = %s|\n", strcpy(dest, "hello"));
	//printf("%s|\n", ft_strcpy(dest, NULL));
	//printf("%s|\n", ft_strcpy(NULL, "hello"));
	// /* 
	//  * strcmp 
	//  */
	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("", "hello"));
	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("", "hello"));
	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("h", "h"));
	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("h", "h"));
	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("hello", "helloa"));
	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("hello", "helloa"));
	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("helloa", "hello"));
	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("helloa", "hello"));
	printf("|M| ==> the return value of ft_strcmp is |%d|\n", ft_strcmp("hella", "hello"));
	printf("|O| ==> the return value of    strcmp is |%d|\n\n", strcmp("hella", "hello"));
	return (0);
}

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