/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:30:41 by mduchauf          #+#    #+#             */
/*   Updated: 2023/11/13 16:30:46 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

void	ft_putnbr_unsigned(unsigned int u, t_sc *sc)
{
	static char	*digits;

	digits = "0123456789";
	if (u < 0)
		write(1, "4294967296", 10);
	else if (u > 9)
		ft_putnbr_unsigned(u / 10, sc);
	write(1, &digits[u % 10], 1);
}

void	ft_write_unsigned(va_list args, t_sc *sc)
{
	unsigned int	u;

	u = va_arg(args, unsigned int);
	ft_putnbr_unsigned(u, sc);
	if ((int)u < 0)
		sc->len += 10;
	else
		sc->len += ft_count_digits(u);
}
