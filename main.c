/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 23:08:48 by ncarob            #+#    #+#             */
/*   Updated: 2021/10/26 15:29:02 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s) + 1;
	while (--i > -1)
		if (s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
	return (NULL);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		*(char *)(s + i) = (char)c;
	return (s);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	if (n / 10)
		ft_putnbr_fd((sign * (n / 10)), fd);
	ft_putchar_fd((sign * (n % 10)) + 48, fd);
}

void	ft_decimal_to_scomplement(int n, char *complement, int i)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	if (n / 2)
		ft_decimal_to_scomplement((sign * (n / 2)), complement, i - 1);
	complement[i] = sign * (n % 2) + 48;
}

int	power(int a, int b)
{
	int	res;

	res = 1;
	while (b-- > 0)
		res = res * a;
	return (res);
}

void	ft_print_hex(char *complement, int lowercase)
{
	int	start = 0;
	int	i = -1;
	int	j = 0;
	int	n = 0;

	while (complement[++i])
	{
		n += ((complement[i] - 48) * (8 / power(2, j)));
		j++;
		if (j == 4)
		{
			if (n != 0)
				start = 1;
			if (start && n < 10)
				ft_putchar_fd(n + 48, 1);
			if (start && n > 9 && lowercase == 1)
				ft_putchar_fd(n + 87, 1);
			if (start && n > 9 && lowercase == 0)
				ft_putchar_fd(n + 55, 1);
			j = 0;
			n = 0;
		}
	}
}

void	ft_reverse_binary(char *complement)
{
	char *p;

	p = ft_strrchr(complement, '1');
	if (!p)
		return ;
	while (--p >= complement)
	{
		if (*p == '0')
			*p = '1';
		else if (*p == '1')
			*p = '0';
	}
}

void	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	if (n / 10)
		ft_putnbr_fd((n / 10), fd);
	ft_putchar_fd((n % 10) + 48, fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
		ft_putchar_fd(s[i], fd); 
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int value;
	int adress;
	size_t	i;
	char	complement[33];

	i = -1;
	va_start(ap, str);

	ft_memset(complement, '0', 32);
	complement[32] = 0;
	while (str[++i])
	{
		if (str[i] != '%')
			ft_putchar_fd(str[i], 1);
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
				ft_putstr_fd(va_arg(ap, char*), 1);
			if (str[i + 1] == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			if (str[i + 1] == 'd' || str[i + 1] == 'i')
				ft_putnbr_fd(va_arg(ap, int), 1);
			if (str[i + 1] == 'u')
				ft_unsigned_putnbr_fd(va_arg(ap, unsigned int), 1);
			if (str[i + 1] == 'p')
			{
				adress = (long)va_arg(ap, int);
				if (!adress)
					ft_putstr_fd("0x0", 1);
				else
				{
					ft_putstr_fd("0x1", 1);
					ft_decimal_to_scomplement(adress, complement, 31);
					if (value < 0)
						ft_reverse_binary(complement);
					ft_print_hex(complement, 1);
				}
			}
			if (str[i + 1] == 'x')
			{
				value = va_arg(ap, int);
				ft_decimal_to_scomplement(value, complement, 31);
				if (value < 0)
					ft_reverse_binary(complement);
				ft_print_hex(complement, 1);
			}
			if (str[i + 1] == 'X')
			{
				value = va_arg(ap, int);
				ft_decimal_to_scomplement(value, complement, 31);
				if (value < 0)
					ft_reverse_binary(complement);
				ft_print_hex(complement, 0);
			}
			if (str[i + 1] == '%')
				ft_putchar_fd('%', 1);
			i = i + 1;
		}
	}
	va_end(ap);
	return (0);
}

int main(void)
{
	char			c = 'c';
	char			s[13] = "Hello world!";
	int				d = -1000000;
	unsigned int	u = 1892281407;
	
	ft_printf("%c\n%s\n%s%s\n%p\n%d\n%i\n%u\n", c, s, s, s, &d, d, d, u);
	ft_printf("%s\n", s);
	ft_printf("%p\n", &d);
	ft_printf("%d\n", d);
	ft_printf("%i\n", d);
	ft_printf("%u\n", u);
	ft_printf("%X\n", d);
	ft_printf("%X\n", u);
	ft_printf("%%\n\n\n");

	printf("%c\n%s\n%s%s\n%p\n%d\n%i\n%u\n", c, s, s, s, &d, d, d, u);
	printf("%s\n", s);
	printf("%p\n", &d);
	printf("%d\n", d);
	printf("%i\n", d);
	printf("%u\n", u);
	printf("%X\n", d);
	printf("%X\n", u);
	printf("%%\n");
}
