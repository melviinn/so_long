/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:52:00 by mduchauf          #+#    #+#             */
/*   Updated: 2023/11/13 11:52:03 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

const char	*ft_find_args(va_list args, const char *format, t_sc *sc)
{
	if (*format == 'c')
		ft_write_char(args, sc);
	else if (*format == 's')
		ft_write_string(args, sc);
	else if (*format == 'd' || *format == 'i')
		ft_write_decimal(args, sc);
	else if (*format == 'x')
		ft_write_hexa(args, sc);
	else if (*format == 'X')
		ft_write_uphexa(args, sc);
	else if (*format == 'u')
		ft_write_unsigned(args, sc);
	else if (*format == '%')
		ft_write_percent(sc);
	else if (*format == 'p')
		ft_write_ptr(args, sc);
	else
		return (NULL);
	format++;
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_sc	sc;

	va_start(args, format);
	sc.len = 0;
	sc.width = 0;
	if (!format)
	{
		sc.len += -1;
		va_end(args);
		return (sc.len);
	}
	while (*format)
	{
		if (*format == '%')
			format = ft_find_args(args, format + 1, &sc);
		else
			format = ft_read_str(&sc, format);
	}
	va_end(args);
	return (sc.len);
}
