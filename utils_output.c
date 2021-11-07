/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:17:24 by ncarob            #+#    #+#             */
/*   Updated: 2021/11/07 23:11:18 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_len(int n)
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

size_t	ft_unsigned_len(unsigned int n)
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

void	ft_putnbr_mod(int n, int *res)
{
	if (n < 0)
		n *= -1;
	if (n / 10)
		ft_putnbr_mod((n / 10), res);
	*res += ft_putchar_fd((n % 10) + 48, 1);
}

void	ft_unsigned_putnbr_mod(unsigned int n, int *res)
{
	if (n / 10)
		ft_unsigned_putnbr_mod((n / 10), res);
	*res += ft_putchar_fd((n % 10) + 48, 1);
}

void	ft_putnbr_hex(unsigned long n, bool uppercase, int *res)
{
	if (n / 16)
		ft_putnbr_hex((n / 16), uppercase, res);
	if (n % 16 > 9 && uppercase)
		*res += ft_putchar_fd((n % 16) + 55, 1);
	else if (n % 16 > 9 && !uppercase)
		*res += ft_putchar_fd((n % 16) + 87, 1);
	else
		*res += ft_putchar_fd((n % 16) + 48, 1);
}
