/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:17:31 by ncarob            #+#    #+#             */
/*   Updated: 2021/11/08 23:54:13 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	ft_print_value(char conversion, va_list *ap)
{
	int	res;

	res = 0;
	if (!conversion)
		return (0);
	if (conversion == 'd' || conversion == 'i')
		ft_putnbr_long(va_arg(*ap, int), &res);
	if (conversion == 'c')
		res = ft_putchar_int(va_arg(*ap, int));
	if (conversion == 's')
		res = ft_putstr_int(va_arg(*ap, char *));
	if (conversion == 'p')
		res = ft_print_ptr(va_arg(*ap, void *));
	if (conversion == 'u')
		ft_putnbr_long(va_arg(*ap, unsigned int), &res);
	if (conversion == 'x')
		ft_putnbr_hex(va_arg(*ap, unsigned int), 0, &res);
	if (conversion == 'X')
		ft_putnbr_hex(va_arg(*ap, unsigned int), 1, &res);
	if (conversion == '%')
		res = ft_putchar_int('%');
	return (res);
}

int	ft_printf(const char *s, ...)
{
	char	conversion;
	int		res;
	va_list	ap;

	res = 0;
	conversion = 0;
	va_start(ap, s);
	while (s && *s)
	{
		if (*s != '%')
			res += ft_putchar_int(*s);
		else
			res += ft_print_value(*(s++ + 1), &ap);
		s++;
	}
	va_end(ap);
	return (res);
}
