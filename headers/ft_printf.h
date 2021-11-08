/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:14:30 by ncarob            #+#    #+#             */
/*   Updated: 2021/11/08 23:45:46 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar_int(char c);
int		ft_putstr_int(char *s);
int		ft_print_ptr(void *num);
int		ft_printf(const char *s, ...);
void	ft_putnbr_long(long long n, int *res);
void	ft_putnbr_hex(unsigned long n, int uppercase, int *res);

#endif /* FT_PRINTF_H */