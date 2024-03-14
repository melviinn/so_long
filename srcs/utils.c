/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:18:33 by mduchauf          #+#    #+#             */
/*   Updated: 2023/12/03 17:26:02 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strchr_new(const char *str, int argument)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)argument)
			return ((char *)&str[i]);
		i++;
	}
	if (argument == '\0')
		return ((char *)&str[i]);
	return ((void *)0);
}

char	*ft_strappend(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

int	close_handler(t_game *g)
{
	free_all_allocated_memory(g);
	exit(EXIT_FAILURE);
}

int	victory(t_game *g)
{
	free_all_allocated_memory(g);
	ft_putstr_fd(GREEN "\n\
	██████████████████████████████████████████████████████████████████\n\
	██                                                              ██\n\
	██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
	██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
	██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
	██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
	██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
	██                                                              ██\n\
	██████████████████████████████████████████████████████████████████\n\n",
		1);
	exit(EXIT_SUCCESS);
}

int	error_msg(char *msg, t_game *g)
{
	if (g->map_alloc == true)
		free_map(g);
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(RESET, 2);
	free(g);
	exit(EXIT_FAILURE);
}
