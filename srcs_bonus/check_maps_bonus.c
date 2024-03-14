/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:57:38 by mduchauf          #+#    #+#             */
/*   Updated: 2023/12/03 18:44:27 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	check_rows(t_game *g)
{
	int	i;

	if (!g)
		error_msg("Pointeur NULL", g);
	i = 0;
	while (i < g->map.rows)
	{
		if (g->map.map[i][0] != WALL)
			error_msg("Invalid Map. Wall missing in the first column.", g);
		else if (g->map.map[i][g->map.columns - 1] != WALL)
			error_msg("Invalid Map. Wall missing in the last column.", g);
		i++;
	}
}

static void	check_columns(t_game *g)
{
	int	i;

	if (!g)
		error_msg("Pointeur NULL", g);
	i = 0;
	while (i < g->map.columns)
	{
		if (g->map.map[0][i] != WALL)
			error_msg("Invalid Map. There's a Wall missing in the first row.",
				g);
		else if (g->map.map[g->map.rows - 1][i] != WALL)
			error_msg("Invalid Map. There's a Wall missing in the last row.",
				g);
		i++;
	}
}

static void	count_map_params(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.rows)
	{
		x = 0;
		while (x < g->map.columns)
		{
			if (!ft_strchr_new("CEPM01", g->map.map[y][x]))
				error_msg("Invalid map. Not expected map parameters.", g);
			else if (g->map.map[y][x] == PLAYER)
			{
				g->map.players++;
				g->map.player.x = x;
				g->map.player.y = y;
			}
			else if (g->map.map[y][x] == COINS)
				g->map.coins++;
			else if (g->map.map[y][x] == EXIT)
				g->map.exit++;
			x++;
		}
		y++;
	}
}

static void	check_params(t_game *g)
{
	if (g->map.coins == 0)
		error_msg("Invalid Map. There are no coins.", g);
	if (g->map.exit != 1)
		error_msg("Invalid Map. Invalid exit count.", g);
	if (g->map.players != 1)
		error_msg("Invalid map. Invalid player count.", g);
}

void	check_map(t_game *g)
{
	check_rows(g);
	check_columns(g);
	count_map_params(g);
	check_params(g);
}
