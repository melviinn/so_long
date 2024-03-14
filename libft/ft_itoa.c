/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:15:10 by mduchauf          #+#    #+#             */
/*   Updated: 2023/11/09 12:15:11 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_size(int n)
{
	size_t	i;

	i = 0;
	if (n < 1)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	size_t		n_size;
	long int	nb;

	nb = n;
	n_size = ft_count_size(nb);
	result = (char *)malloc(sizeof(char) * (n_size + 1));
	if (!result)
		return (NULL);
	result[n_size--] = '\0';
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		result[n_size--] = nb % 10 + '0';
		nb /= 10;
	}
	return (result);
}
