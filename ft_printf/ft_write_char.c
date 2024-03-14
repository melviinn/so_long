/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:48:55 by mduchauf          #+#    #+#             */
/*   Updated: 2023/11/13 12:48:57 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_write_char(va_list args, t_sc *sc)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar(c);
	sc->len += 1;
}
