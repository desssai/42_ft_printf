/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:14:30 by ncarob            #+#    #+#             */
/*   Updated: 2021/11/07 22:48:24 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_flags
{
	int		fill;
	bool	sign;
	int		width;
	char	*body;
	bool	hexstart;
	bool	is_space;
	int		precision;
	char	conversion;
	bool	is_precision;
	bool	is_leftaligned;

}	t_flags;

size_t	ft_len(int n);
size_t	ft_hex_len(unsigned long n);
int		ft_print_per(t_flags *flags);
int		ft_printf(const char *s, ...);
void	ft_putnbr_mod(int n, int *res);
size_t	ft_unsigned_len(unsigned int n);
int		ft_print_chr(t_flags *flags, int c);
int		ft_print_int(t_flags *flags, int num);
int		ft_print_ptr(t_flags *flags, void *num);
int		ft_print_str(t_flags *flags, char *str);
int		ft_print_uin(t_flags *flags, unsigned int num);
void	ft_unsigned_putnbr_mod(unsigned int n, int *res);
void	ft_putnbr_hex(unsigned long n, bool uppercase, int *res);
int		ft_print_hex(t_flags *flags, unsigned int num, bool uppercase);

#endif