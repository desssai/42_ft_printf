/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:17:24 by ncarob            #+#    #+#             */
/*   Updated: 2021/11/08 23:50:19 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_putchar_int(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr_int(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr_int("(null)"));
	while (s[i])
		ft_putchar_int(s[i++]);
	return (i);
}

void	ft_putnbr_long(long long n, int *res)
{
	if (n < 0)
	{
		n *= -1;
		*res += ft_putchar_int('-');
	}
	if (n / 10)
		ft_putnbr_long((n / 10), res);
	*res += ft_putchar_int((n % 10) + 48);
}

void	ft_putnbr_hex(unsigned long n, int uppercase, int *res)
{
	if (n / 16)
		ft_putnbr_hex((n / 16), uppercase, res);
	if (n % 16 > 9 && uppercase)
		*res += ft_putchar_int((n % 16) + 55);
	else if (n % 16 > 9 && !uppercase)
		*res += ft_putchar_int((n % 16) + 87);
	else
		*res += ft_putchar_int((n % 16) + 48);
}

int	ft_print_ptr(void *num)
{
	int	res;

	res = 0;
	res += ft_putstr_int("0x");
	ft_putnbr_hex((unsigned long)num, 0, &res);
	return (res);
}
