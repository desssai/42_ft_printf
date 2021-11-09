/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:17:31 by ncarob            #+#    #+#             */
/*   Updated: 2021/11/09 20:49:47 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	ft_print_value(t_flags *flags, va_list *ap)
{
	int	res;

	res = 0;
	if (!flags)
		return (0);
	if (flags->conversion == 'd' || flags->conversion == 'i')
		res = ft_print_int(flags, va_arg(*ap, int));
	if (flags->conversion == 'c')
		res = ft_print_chr(flags, va_arg(*ap, int));
	if (flags->conversion == 's')
		res = ft_print_str(flags, va_arg(*ap, char *));
	if (flags->conversion == 'p')
		res = ft_print_ptr(flags, va_arg(*ap, void *));
	if (flags->conversion == 'u')
		res = ft_print_uin(flags, va_arg(*ap, unsigned int));
	if (flags->conversion == 'x')
		res = ft_print_hex(flags, va_arg(*ap, unsigned int), false);
	if (flags->conversion == 'X')
		res = ft_print_hex(flags, va_arg(*ap, unsigned int), true);
	if (flags->conversion == '%')
		res = ft_print_per(flags);
	return (res);
}

static void	ft_get_flags(t_flags *flag)
{
	int	i;

	i = 0;
	while (flag->body[i] && !ft_strchr("123456789",
			flag->body[i]) && flag->body[i] != '.')
	{
		if (flag->body[i] == '-')
			flag->is_leftaligned = true;
		else if (flag->body[i] == '#')
			flag->hexstart = true;
		else if (flag->body[i] == ' ')
			flag->is_space = true;
		else if (flag->body[i] == '+')
			flag->sign = true;
		else if (flag->body[i] == '0')
			flag->fill = '0';
		i++;
	}
	flag->width = ft_atoi(&flag->body[i]);
	if (ft_strchr(flag->body, '.'))
	{
		flag->is_precision = true;
		flag->precision = ft_atoi(ft_strchr(flag->body, '.') + 1);
		flag->fill = ' ';
	}
}

static t_flags	*ft_init_flag(const char **str)
{
	t_flags	*flag;
	char	*flag_end;

	flag = (t_flags *)malloc(sizeof(t_flags));
	if (!flag)
		return (NULL);
	flag_end = (char *)(*str + 1);
	while (*flag_end && !ft_strchr("cspdiuxX%", *flag_end))
		flag_end++;
	flag->body = ft_substr(*str, 1, flag_end - *str);
	flag->conversion = *flag_end;
	flag->is_leftaligned = false;
	flag->is_precision = false;
	flag->is_space = false;
	flag->hexstart = false;
	flag->precision = 0;
	flag->sign = false;
	flag->width = 0;
	flag->fill = ' ';
	*str = flag_end;
	ft_get_flags(flag);
	return (flag);
}

static void	ft_empty_flag(t_flags **flag)
{
	if (!flag)
		return ;
	free((*flag)->body);
	free(*flag);
	*flag = NULL;
}

int	ft_printf(const char *s, ...)
{
	t_flags	*flag;
	int		res;
	va_list	ap;

	res = 0;
	flag = NULL;
	va_start(ap, s);
	while (s && *s)
	{
		if (*s != '%')
			res += ft_putchar_int(*s);
		else
		{
			flag = ft_init_flag(&s);
			if (!flag)
				return (res);
			res += ft_print_value(flag, &ap);
			ft_empty_flag(&flag);
		}
		s++;
	}
	va_end(ap);
	return (res);
}
