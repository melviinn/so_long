/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:42:22 by mduchauf          #+#    #+#             */
/*   Updated: 2023/10/15 23:18:31 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if ((!dst && size == 0))
		return (0);
	if (size == 0)
		return (size + ft_strlen(src));
	i = 0;
	while (dst[i] && i < size)
		i++;
	j = i;
	while (src[i - j] && i < (size - 1))
	{
		dst[i] = src[i - j];
		i++;
	}
	if (j < size)
		dst[i] = '\0';
	return (j + ft_strlen(src));
}
