/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_HEXA.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:23:44 by mduchauf          #+#    #+#             */
/*   Updated: 2023/11/13 16:23:45 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

static void	ft_putuphexa(unsigned int x)
{
	static char	*upper_digits;

	upper_digits = "0123456789ABCDEF";
	if (x >= 16)
		ft_putuphexa(x / 16);
	write (1, &upper_digits[x % 16], 1);
}

void	ft_write_uphexa(va_list args, t_sc *sc)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	ft_putuphexa((unsigned long)x);
	sc->len += ft_count_digits_hexa((int)x);
}
