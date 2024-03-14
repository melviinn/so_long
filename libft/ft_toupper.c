/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:27:40 by mduchauf          #+#    #+#             */
/*   Updated: 2023/10/18 20:43:56 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	letter;

	letter = (unsigned char)c;
	if (letter >= 'a' && letter <= 'z')
		return (letter -= 32);
	else
		return (letter);
}
