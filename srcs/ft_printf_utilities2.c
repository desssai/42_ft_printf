/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:17:24 by ncarob            #+#    #+#             */
/*   Updated: 2021/11/09 19:43:03 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	i = -1;
	if (!s)
		size = 0;
	else
		size = ft_strlen(s);
	if (size < start)
		len = 0;
	else if (size - start < len)
		len = size;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (++i < len)
		str[i] = s[start + i];
	str[i] = 0;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
	if (s[i] == (unsigned char)c)
		return ((char *)(&s[i]));
	return (NULL);
}

int	ft_putchar_int(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr_int(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		ft_putchar_int(s[i++]);
	return (i);
}
