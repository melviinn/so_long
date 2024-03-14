/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:09:39 by mduchauf          #+#    #+#             */
/*   Updated: 2023/10/18 20:44:07 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	letter;

	letter = (unsigned char)c;
	if (letter >= 'A' && letter <= 'Z')
		return (letter += 32);
	else
		return (letter);
}
