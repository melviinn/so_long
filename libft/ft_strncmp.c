/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:42:01 by mduchauf          #+#    #+#             */
/*   Updated: 2023/10/13 23:14:04 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((string1[i] == string2[i]) && (string1[i] != '\0')
		&& (string2[i] != '\0') && (i < (n - 1)))
		i++;
	return (string1[i] - string2[i]);
}
