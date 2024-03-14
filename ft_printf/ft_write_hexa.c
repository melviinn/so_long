/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:12:53 by mduchauf          #+#    #+#             */
/*   Updated: 2023/11/13 16:12:54 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

void	ft_puthexa(unsigned int x)
{
	static char	*lower_digits;

	lower_digits = "0123456789abcdef";
	if (x >= 16)
		ft_puthexa(x / 16);
	write(1, &lower_digits[x % 16], 1);
}

size_t	ft_count_digits_hexa(unsigned int x)
{
	size_t	digits;

	digits = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		digits += 1;
		x /= 16;
	}
	return (digits);
}

void	ft_write_hexa(va_list args, t_sc *sc)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	ft_puthexa((unsigned long)x);
	sc->len += ft_count_digits_hexa(x);
}
