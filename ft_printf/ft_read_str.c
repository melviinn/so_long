/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:02:01 by mduchauf          #+#    #+#             */
/*   Updated: 2023/11/13 16:02:02 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

char	*ft_strchr_percent(const char *s)
{
	if (!s)
		return ((char *)s);
	while (*s)
	{
		if (*s == '%')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

const char	*ft_read_str(t_sc *sc, const char *format)
{
	char	*next;

	next = ft_strchr_percent(format);
	if (next)
		sc->width = (next - format);
	else
		sc->width = ft_strlen_2(format);
	write(1, format, sc->width);
	sc->len += sc->width;
	while (*format && *format != '%')
		++format;
	return (format);
}
