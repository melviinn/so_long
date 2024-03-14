/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_len_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:54:15 by mduchauf          #+#    #+#             */
/*   Updated: 2024/02/29 14:54:17 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_map_len(char *av, t_game *g)
{
	int		fd;
	int		map_len;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		error_msg("The map couldn't be opened, check if the map exist.", g);
	line = get_next_line(fd);
	map_len = ft_strlen(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\n')
			break ;
		if (map_len != (int)ft_strlen(line))
		{
			free(line);
			error_msg("The map is not rectangular", g);
		}
		free(line);
	}
	close(fd);
}
