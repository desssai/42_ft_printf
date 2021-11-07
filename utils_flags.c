/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:17:22 by ncarob            #+#    #+#             */
/*   Updated: 2021/11/08 02:01:07 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_chr(t_flags *flags, int c)
{
	int	res;

	res = 0;
	if (flags->is_leftaligned)
		res += ft_putchar_fd(c, 1);
	while (flags->width-- - 1 > 0)
		res += ft_putchar_fd(' ', 1);
	if (!flags->is_leftaligned)
		res += ft_putchar_fd(c, 1);
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
		res += ft_putstr_fd(str, 1);
	while (flags->width-- - (int)ft_strlen(str) > 0)
		res += ft_putchar_fd(' ', 1);
	if (!flags->is_leftaligned)
		res += ft_putstr_fd(str, 1);
	if (check)
		free(str);
	return (res);
}

int	ft_print_ptr(t_flags *flags, void *num)
{
	int	res;

	res = 0;
	if (flags->fill == '0')
		res += ft_putstr_fd("0x", 1);
	flags->width -= res;
	if (flags->fill == ' ')
		flags->width -= 2;
	if (flags->is_leftaligned)
	{
		if (flags->fill == ' ')
			res += ft_putstr_fd("0x", 1);
		ft_putnbr_hex((unsigned long)num, 0, &res);
	}
	while (flags->width-- - (int)ft_hex_len((unsigned long)num) > 0)
		res += ft_putchar_fd(flags->fill, 1);
	if (!flags->is_leftaligned)
	{
		if (flags->fill == ' ')
			res += ft_putstr_fd("0x", 1);
		ft_putnbr_hex((unsigned long)num, 0, &res);
	}
	return (res);
}

int	ft_print_uin(t_flags *flags, unsigned int num)
{
	int	res;
	int	check;

	res = 0;
	check = 0;
	if (flags->precision > (int)ft_unsigned_len(num))
		flags->width -= flags->precision;
	else
		flags->width -= (int)ft_unsigned_len(num);
	if (flags->is_precision && !flags->precision && !num)
		check++;
	if (flags->is_leftaligned)
	{
		while (flags->precision-- - (int)ft_unsigned_len(num) > 0)
			res += ft_putchar_fd('0', 1);
		if (!check)
			ft_unsigned_putnbr_mod(num, &res);
	}
	while (flags->width-- + check > 0)
		res += ft_putchar_fd(flags->fill, 1);
	if (!flags->is_leftaligned)
	{
		while (flags->precision-- - (int)ft_unsigned_len(num) > 0)
			res += ft_putchar_fd('0', 1);
		if (!check)
			ft_unsigned_putnbr_mod(num, &res);
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
		res += ft_putstr_fd("0X", 1);
	else if (flags->hexstart && !uppercase && flags->fill == '0' && num)
		res += ft_putstr_fd("0x", 1);
	flags->width -= res;
	if (flags->is_leftaligned)
	{
		while (flags->precision-- - (int)ft_hex_len(num) > 0)
			res += ft_putchar_fd('0', 1);
		if (!check)
			ft_putnbr_hex(num, uppercase, &res);
	}
	while (flags->width-- + check > 0)
		res += ft_putchar_fd(flags->fill, 1);
	if (flags->hexstart && uppercase && flags->fill == ' ' && num)
		res += ft_putstr_fd("0X", 1);
	else if (flags->hexstart && !uppercase && flags->fill == ' ' && num)
		res += ft_putstr_fd("0x", 1);
	if (!flags->is_leftaligned)
	{
		while (flags->precision-- - (int)ft_hex_len(num) > 0)
			res += ft_putchar_fd('0', 1);
		if (!check)
			ft_putnbr_hex(num, uppercase, &res);
	}
	return (res);
}
