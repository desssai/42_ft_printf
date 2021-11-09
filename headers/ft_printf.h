/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:14:30 by ncarob            #+#    #+#             */
/*   Updated: 2021/11/09 22:13:02 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
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

size_t	ft_len_num(int n);
int		ft_putstr_int(char *s);
int		ft_putchar_int(char c);
int		ft_atoi(const char *num);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
size_t	ft_hex_len(unsigned long n);
int		ft_print_per(t_flags *flags);
int		ft_printf(const char *s, ...);
void	ft_putnbr_num(int n, int *res);
char	*ft_strchr(const char *s, int c);
size_t	ft_len_unsigned_num(unsigned int n);
int		ft_print_chr(t_flags *flags, int c);
int		ft_print_int(t_flags *flags, int num);
int		ft_print_ptr(t_flags *flags, void *num);
int		ft_print_str(t_flags *flags, char *str);
void	ft_unsigned_putnbr(unsigned int n, int *res);
int		ft_print_uin(t_flags *flags, unsigned int num);
void	ft_putnbr_unsigned_num(unsigned int n, int *res);
int		ft_print_ptr_part2(t_flags *flags, void *n, int check);
void	ft_putnbr_hex(unsigned long n, bool uppercase, int *res);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_print_hex(t_flags *flags, unsigned int num, bool uppercase);
int		ft_print_uin_part2(t_flags *flags, unsigned int num, int check,
			int length);

#endif /* FT_PRINTF_H */
