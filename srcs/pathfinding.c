/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:41:05 by mduchauf          #+#    #+#             */
/*   Updated: 2024/01/25 14:41:09 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**init_grid(t_game *g)
{
	int		i;
	char	**grid;

	i = 0;
	grid = ft_calloc((g->map.rows + 1), sizeof(char *));
	if (!grid)
		return (NULL);
	while (i < g->map.rows)
	{
		grid[i] = ft_strdup(g->map.map[i]);
		if (!grid[i])
			return (free_grid(grid), NULL);
		i++;
	}
	return (grid);
}

static int	flood_fill(t_map *map, int pos_x, int pos_y, char **grid)
{
	static int	coins = 0;
	static int	found_exit = 0;

	if (grid[pos_y][pos_x] == WALL)
		return (0);
	else if (grid[pos_y][pos_x] == COINS)
		coins++;
	else if (grid[pos_y][pos_x] == EXIT)
		return (found_exit = 1);
	grid[pos_y][pos_x] = WALL;
	flood_fill(map, pos_x + 1, pos_y, grid);
	flood_fill(map, pos_x - 1, pos_y, grid);
	flood_fill(map, pos_x, pos_y + 1, grid);
	flood_fill(map, pos_x, pos_y - 1, grid);
	return (coins == map->coins && found_exit);
}

void	check_path(t_game *g)
{
	char	**grid;

	grid = init_grid(g);
	if (!flood_fill(&g->map, g->map.player.x, g->map.player.y, grid))
	{
		free_grid(grid);
		error_msg("Invalid Path: The map is not playable", g);
	}
	free_grid(grid);
}
