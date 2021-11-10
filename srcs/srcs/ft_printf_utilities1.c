/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:17:24 by ncarob            #+#    #+#             */
/*   Updated: 2021/11/09 22:13:12 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

size_t	ft_hex_len(unsigned long n)
{
	size_t	i;

	i = 0;
	while (n || !i)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

void	ft_putnbr_hex(unsigned long n, bool uppercase, int *res)
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

int	ft_atoi(const char *num)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while ((num[i] > 8 && num[i] < 14) || num[i] == 32)
		i++;
	if (num[i] == 43 || num[i] == 45)
	{
		if (num[i] == 45)
			sign = -1;
		i++;
	}
	while (num[i] > 47 && num[i] < 58)
	{
		result = result * 10 + num[i] - 48;
		i++;
	}
	return (result * sign);
}

int	ft_print_ptr_part2(t_flags *flags, void *n, int check)
{
	int	res;

	res = 0;
	while (flags->width-- - (int)ft_hex_len((unsigned long)n) > 0)
		res += ft_putchar_int(flags->fill);
	if (!flags->is_leftaligned)
	{
		if (flags->fill == ' ')
			res += ft_putstr_int("0x");
		if (!check)
			ft_putnbr_hex((unsigned long)n, 0, &res);
	}
	return (res);
}
