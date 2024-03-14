/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:04:28 by mduchauf          #+#    #+#             */
/*   Updated: 2023/11/13 13:04:30 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

size_t	ft_strlen_2(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, &(*s++), 1);
}

void	ft_write_string(va_list args, t_sc *sc)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		sc->len += 6;
	}
	else
	{
		ft_putstr(s);
		sc->len += ft_strlen_2(s);
	}
}
