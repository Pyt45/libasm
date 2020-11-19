#include <stdio.h>
#include <stdlib.h>

int		ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v'
	|| c == '\n' || c == '\f' || c == '\r');
}

int		ft_strchar(char *str, char find)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
		if (find == *ptr++)
			return ((int)(ptr - str - 1));
	return (-1);
}

int		check_base(char *base)
{
	char	*base_check;
	int		len;
	int		i;

	base_check = base;
	while (*base_check++)
		;
	if ((len = (int)(base_check - base - 1)) <= 1)
		return (0);
	i = -1;
	while (++i < len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] <= 32 || base[i] > 126)
			return (0);
		if (ft_strchar(base + i + 1, base[i]) >= 0)
			return (0);
	}
	return (len);
}

int		ft_atoi_base1(char *str, char *base)
{
	int		base_len;
	int		index;
	char	*ptr;
	int		num;
	int		sign;

	num = 0;
	base_len = strlen(base);
	if (!check_base(base))
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	str += (str[0] == '+' || sign < 0) ? 1 : 0;
	// while (find_char_base(base, *str) < base_len)
	// 	num = (num * base_len) - find_char_base(base, *str++);
	ptr = str;
	while (*ptr)
		if (ft_strchar(base, *ptr++) < 0 && *(ptr - 1) != '-' && *(ptr - 1) != '+')
			return (0);
	while ((index = ft_strchar(base, *str++)) >= 0)
		num = num * base_len + index;
	return (sign * num);
}

int     main()
{
	return 0;
}