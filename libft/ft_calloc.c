/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:38:10 by mduchauf          #+#    #+#             */
/*   Updated: 2023/10/18 21:47:43 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmenb, size_t size)
{
	void		*ptr;

	if (!nmenb || !size)
		return (malloc(0));
	if (nmenb > (INT_MAX / size))
		return (NULL);
	ptr = (void *)malloc((size * nmenb));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nmenb);
	return (ptr);
}
