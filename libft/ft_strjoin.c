/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:11:48 by mduchauf          #+#    #+#             */
/*   Updated: 2023/10/18 23:21:20 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len_verif(char const *s1, char const *s2, char *str)
{
	if ((ft_strlen(s1) + ft_strlen(s2) + 1) <= 0 || !str)
		return (0);
	return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	ft_len_verif(s1, s2, str);
	i = -1;
	j = 0;
	while (++i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		while (*s1)
			str[j++] = *s1++;
		while (*s2)
			str[j++] = *s2++;
	}
	str[j] = '\0';
	return (str);
}
