/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities3_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:17:24 by ncarob            #+#    #+#             */
/*   Updated: 2021/11/09 00:12:52 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = s[i];
	str[i] = 0;
	return (str);
}

size_t	ft_len_num(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i++;
	while (n || !i)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

size_t	ft_len_unsigned_num(unsigned int n)
{
	size_t	i;

	i = 0;
	while (n || !i)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	ft_putnbr_num(int n, int *res)
{
	if (n < 0)
		n *= -1;
	if (n / 10)
		ft_putnbr_num((n / 10), res);
	*res += ft_putchar_int((n % 10) + 48);
}

void	ft_putnbr_unsigned_num(unsigned int n, int *res)
{
	if (n / 10)
		ft_putnbr_unsigned_num((n / 10), res);
	*res += ft_putchar_int((n % 10) + 48);
}