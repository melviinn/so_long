/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:02:09 by mduchauf          #+#    #+#             */
/*   Updated: 2023/12/03 17:24:44 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_map(t_game *g, char *av)
{
	char	*line;
	char	*map;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		error_msg("The Map couldn't be opened. Check if the map exist.", g);
	map = ft_strdup("");
	g->map.rows = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = ft_strappend(&map, line);
		free(line);
		g->map.rows++;
	}
	close(fd);
	g->map.map = ft_split(map, '\n');
	g->map_alloc = true;
	free(map);
}

void	check_args(int ac, char **av, t_game *g)
{
	int	args_len;

	if (ac > 2)
		error_msg("Too many arguments.", g);
	else if (ac < 2)
		error_msg("The map file is missing.", g);
	args_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][args_len - 4], ".ber", 4))
		error_msg("Map file extension is wrong. It should be .ber", g);
}
