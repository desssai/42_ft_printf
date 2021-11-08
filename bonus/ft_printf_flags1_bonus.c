/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:17:22 by ncarob            #+#    #+#             */
/*   Updated: 2021/11/09 00:12:17 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

int	ft_print_chr(t_flags *flags, int c)
{
	int	res;

	res = 0;
	if (flags->is_leftaligned)
		res += ft_putchar_int(c);
	while (flags->width-- - 1 > 0)
		res += ft_putchar_int(' ');
	if (!flags->is_leftaligned)
		res += ft_putchar_int(c);
	return (res);
}

int	ft_print_str(t_flags *flags, char *str)
{
	int	res;
	int	check;

	res = 0;
	check = 0;
	if (!str && !check++)
		str = ft_strdup("(null)");
	if (!str)
		return (0);
	if (flags->is_precision)
	{
		if (!check++)
			str = ft_strdup(str);
		*(str + flags->precision) = 0;
	}
	if (flags->is_leftaligned)
		res += ft_putstr_int(str);
	while (flags->width-- - (int)ft_strlen(str) > 0)
		res += ft_putchar_int(' ');
	if (!flags->is_leftaligned)
		res += ft_putstr_int(str);
	if (check)
		free(str);
	return (res);
}

int	ft_print_ptr(t_flags *flags, void *num)
{
	int	res;

	res = 0;
	if (flags->fill == '0')
		res += ft_putstr_int("0x");
	flags->width -= res;
	if (flags->fill == ' ')
		flags->width -= 2;
	if (flags->is_leftaligned)
	{
		if (flags->fill == ' ')
			res += ft_putstr_int("0x");
		ft_putnbr_hex((unsigned long)num, 0, &res);
	}
	while (flags->width-- - (int)ft_hex_len((unsigned long)num) > 0)
		res += ft_putchar_int(flags->fill);
	if (!flags->is_leftaligned)
	{
		if (flags->fill == ' ')
			res += ft_putstr_int("0x");
		ft_putnbr_hex((unsigned long)num, 0, &res);
	}
	return (res);
}

int	ft_print_per(t_flags *flags)
{
	int	res;

	res = 0;
	if (flags->is_leftaligned)
	{
		res += ft_putchar_int('%');
		flags->fill = ' ';
	}
	while (flags->width-- - 1 > 0)
		res += ft_putchar_int(flags->fill);
	if (!flags->is_leftaligned)
		res += ft_putchar_int('%');
	return (res);
}

int	ft_print_uin(t_flags *flags, unsigned int num)
{
	int	res;
	int	check;
	int length;

	res = 0;
	check = 0;
	length = (int)ft_len_unsigned_num(num);
	if (flags->precision > length)
		flags->width -= flags->precision;
	else
		flags->width -= length;
	if (flags->is_precision && !flags->precision && !num)
		check++;
	if (flags->is_leftaligned)
	{
		while (flags->precision-- - length > 0)
			res += ft_putchar_int('0');
		if (!check)
			ft_putnbr_unsigned_num(num, &res);
	}
	return (res + ft_print_uin_part2(flags, num, check, length));
}
