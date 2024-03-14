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

static int	check_first_line(int fd, char *line, t_game *g)
{
	if (!line || line[0] == '\n' || line[0] == ' ')
		return (free(line), close(fd), error_msg("Empty line", g));
	free(line);
	return (0);
}

int	check_map_len(char *av, t_game *g)
{
	int			fd;
	int			map_len;
	static char	*line = NULL;
	static int	i = -1;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		error_msg("The map couldn't be opened, check if the map exist.", g);
	line = get_next_line(fd);
	check_first_line(fd, line, g);
	map_len = ft_strlen(line);
	while (line)
	{
		line = get_next_line(fd);
		while (line[++i])
			if (!ft_strchr_new("CEP01", line[i]))
				return (free(line), close(fd), error_msg("Invalid character", g));
		i = 0;
		printf("MAP_LEN: %d", map_len);
		if (map_len != (int)ft_strlen(line))
			return (free(line), close(fd),
				error_msg("The map is not rectangular", g));
		if (!line || line[0] == '\n' || line[0] == '\0' || line[0] == ' ')
			break ;
		free(line);
	}
	return (close(fd), 0);
}
