/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:13:34 by ncarob            #+#    #+#             */
/*   Updated: 2021/11/08 02:51:55 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void	ft_print_int_part2(t_flags *flags, int num, int *res, int check)
{
	while (flags->width-- + check > 0)
		*res += ft_putchar_fd(flags->fill, 1);
	if (!flags->is_leftaligned)
	{
		if (num < 0 && flags->fill != '0')
			*res += ft_putchar_fd('-', 1);
		if (num >= 0 && flags->sign && flags->fill != '0')
			*res += ft_putchar_fd('+', 1);
		if (flags->is_precision && (num < 0 || flags->sign))
			flags->precision++;
		while (flags->is_precision
			&& (flags->precision-- - (int)ft_len(num) > 0))
			*res += ft_putchar_fd('0', 1);
		if (num == -2147483648)
			*res += ft_putstr_fd("2147483648", 1);
		else if (!check)
			ft_putnbr_mod(num, res);
	}
}

int	ft_print_int(t_flags *flags, int num)
{
	int	res;
	int	check;

	res = 0;
	check = 0;
	if (flags->is_space && num > -1 && flags->width == 0)
		res += ft_putchar_fd(' ', 1);
	if (flags->precision > (int)ft_len(num))
	{
		flags->width -= flags->precision;
		if (num < 0)
			flags->width--;
	}
	else
		flags->width -= (int)ft_len(num);
	if (flags->is_precision && !flags->precision && !num)
		check++;
	if (flags->is_leftaligned || flags->fill == '0')
	{
		if (num < 0 || (num < 0 && flags->fill == '0'))
			res += ft_putchar_fd('-', 1);
		if (num >= 0 && flags->sign && flags->width-- && flags->fill == '0')
			res += ft_putchar_fd('+', 1);
		if (flags->is_precision && (num < 0 || flags->sign))
			flags->precision++;
		while (flags->is_precision
			&& (flags->precision-- - (int)ft_len(num) > 0))
			res += ft_putchar_fd('0', 1);
		if (num == -2147483648 && flags->is_leftaligned)
			res += ft_putstr_fd("2147483648", 1);
		else if (flags->is_leftaligned && !check)
			ft_putnbr_mod(num, &res);
	}
	ft_print_int_part2(flags, num, &res, check);
	return (res);
}

int	ft_print_per(t_flags *flags)
{
	int	res;

	res = 0;
	if (flags->is_leftaligned)
	{
		res += ft_putchar_fd('%', 1);
		flags->fill = ' ';
	}
	while (flags->width-- - 1 > 0)
		res += ft_putchar_fd(flags->fill, 1);
	if (!flags->is_leftaligned)
		res += ft_putchar_fd('%', 1);
	return (res);
}
