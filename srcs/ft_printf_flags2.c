/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:13:34 by ncarob            #+#    #+#             */
/*   Updated: 2021/11/09 19:38:30 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	ft_print_int_part2(t_flags *flags, int num, int *res, int *check)
{
	if ((flags->is_leftaligned || flags->fill == '0')
		&& num < 0 && check[3] == 0 && !check[1]++)
		*res += ft_putchar_int('-');
	if (!flags->is_leftaligned && num < 0 && flags->fill != '0'
		&& check[3] == 1 && !check[1]++)
		*res += ft_putchar_int('-');
	if ((flags->is_leftaligned || flags->fill == '0') && num >= 0 && flags->sign
		&& flags->width-- && check[3] == 0 && !check[1]++)
		*res += ft_putchar_int('+');
	if (!flags->is_leftaligned && num >= 0 && flags->sign
		&& flags->fill != '0' && check[3] == 1 && !check[1]++)
		*res += ft_putchar_int('+');
	if (((check[3] == 0 && flags->is_leftaligned) || (check[3] == 1
				&& !flags->is_leftaligned)) && !check[2])
		while (flags->is_precision
			&& (flags->precision-- - (int)ft_len_num(num) > 0))
			*res += ft_putchar_int('0');
	if (((flags->is_leftaligned && !check[3]) || (!flags->is_leftaligned
				&& check[3] == 1)) && num == -2147483648 && !check[2]++)
		*res += ft_putstr_int("2147483648");
	else if (((flags->is_leftaligned && !check[3])
			|| (!flags->is_leftaligned && check[3] == 1))
		&& !check[0] && !check[2]++)
		ft_putnbr_num(num, res);
	check[3]++;
}

int	ft_print_int(t_flags *flags, int num)
{
	int	res;
	int	check[4];

	res = 0;
	check[0] = 0;
	check[1] = 0;
	check[2] = 0;
	check[3] = 0;
	if (flags->is_space && num > -1 && flags->width == 0)
		res += ft_putchar_int(' ');
	if (flags->precision >= (int)ft_len_num(num))
	{
		flags->width -= flags->precision;
		if (num < 0 && flags->precision++)
			flags->width--;
	}
	else
		flags->width -= (int)ft_len_num(num);
	if (flags->is_precision && !flags->precision && !num)
		check[0]++;
	ft_print_int_part2(flags, num, &res, check);
	while (flags->width-- + check[0] > 0)
		res += ft_putchar_int(flags->fill);
	ft_print_int_part2(flags, num, &res, check);
	return (res);
}

static int	ft_print_hex_part2(t_flags *flags, unsigned int num,
	bool uppercase, int check)
{
	int	res;

	res = 0;
	if (flags->is_leftaligned)
	{
		while (flags->precision-- - (int)ft_hex_len(num) > 0)
			res += ft_putchar_int('0');
		if (!check)
			ft_putnbr_hex(num, uppercase, &res);
	}
	while (flags->width-- + check > 0)
		res += ft_putchar_int(flags->fill);
	if (flags->hexstart && uppercase && flags->fill == ' ' && num)
		res += ft_putstr_int("0X");
	else if (flags->hexstart && !uppercase && flags->fill == ' ' && num)
		res += ft_putstr_int("0x");
	if (!flags->is_leftaligned)
	{
		while (flags->precision-- - (int)ft_hex_len(num) > 0)
			res += ft_putchar_int('0');
		if (!check)
			ft_putnbr_hex(num, uppercase, &res);
	}
	return (res);
}

int	ft_print_hex(t_flags *flags, unsigned int num, bool uppercase)
{
	int	res;
	int	check;

	res = 0;
	check = 0;
	if (flags->precision > (int)ft_hex_len(num))
		flags->width -= flags->precision;
	else
		flags->width -= (int)ft_hex_len(num);
	if (flags->is_precision && !flags->precision && !num)
		check++;
	if (flags->hexstart && uppercase && flags->fill == '0' && num)
		res += ft_putstr_int("0X");
	else if (flags->hexstart && !uppercase && flags->fill == '0' && num)
		res += ft_putstr_int("0x");
	return (res + ft_print_hex_part2(flags, num, uppercase, check));
}

int	ft_print_uin_part2(t_flags *flags, unsigned int num, int check, int length)
{
	int	res;

	res = 0;
	while (flags->width-- + check > 0)
		res += ft_putchar_int(flags->fill);
	if (!flags->is_leftaligned)
	{
		while (flags->precision-- - length > 0)
			res += ft_putchar_int('0');
		if (!check)
			ft_putnbr_unsigned_num(num, &res);
	}
	return (res);
}
