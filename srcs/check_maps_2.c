/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:59:09 by mduchauf          #+#    #+#             */
/*   Updated: 2024/02/29 12:59:11 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_len(char *av, t_game *g)
{
	int		fd;
	int		map_len;
	char	*line;

	line = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		error_msg("The map couldn't be opened, check if the map exist.", g);
	line = get_next_line(fd);
	if (!line || line[0] == '\n' || line[0] == ' ')
		return (close(fd), error_msg("Empty line at start of file.", g));
	map_len = ft_strlen(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\n' || line[0] == '\0' || line[0] == ' ')
			break ;
		if (map_len != (int)ft_strlen(line))
			return (free(line), close(fd),
				error_msg("The map is not rectangular", g));
		free(line);
	}
	return (close(fd), 0);
}
