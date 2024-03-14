/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:43:16 by mduchauf          #+#    #+#             */
/*   Updated: 2023/10/18 19:04:17 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char	*str_cpy;
	size_t	start;
	size_t	end;

	if (!s || !set)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s) - 1;
	while (ft_strchr(set, s[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(s + end + 1));
	while (ft_strchr(set, s[end]) && end >= 0)
		end--;
	str_cpy = (char *)malloc((end - start + 2));
	if (!str_cpy)
		return (NULL);
	ft_strlcpy(str_cpy, &s[start], end - start + 2);
	return (str_cpy);
}
