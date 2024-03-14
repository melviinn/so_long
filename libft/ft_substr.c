/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:50:10 by mduchauf          #+#    #+#             */
/*   Updated: 2023/11/27 11:24:38 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	sub = NULL;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	size = 0;
	while (s[start + size] && size < len)
		size++;
	sub = malloc((size + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	s += start;
	ft_strlcpy(sub, s, size + 1);
	return (sub);
}
