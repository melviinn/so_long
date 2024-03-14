/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:04:30 by mduchauf          #+#    #+#             */
/*   Updated: 2023/11/13 17:04:32 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

static size_t	ft_count_digits_ptr(uintptr_t num)
{
	size_t	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_print_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_print_ptr(num / 16);
		ft_print_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'a'));
	}
}

void	ft_write_ptr(va_list args, t_sc *sc)
{
	unsigned long long	ptr;

	ptr = va_arg(args, unsigned long long);
	if ((void *)ptr == (void *)0)
	{
		write(1, "(nil)", 5);
		sc->len += 5;
		return ;
	}
	sc->len += write(1, "0x", 2);
	if (ptr == 0)
		sc->len += write(1, "0", 1);
	else
	{
		ft_print_ptr(ptr);
		sc->len += ft_count_digits_ptr(ptr);
	}
}
