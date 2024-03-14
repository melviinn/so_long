/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:41:01 by mduchauf          #+#    #+#             */
/*   Updated: 2023/12/03 17:37:51 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	check_finish(t_game *g, int new_y, int new_x)
{
	if (g->map.map[new_y][new_x] == EXIT && g->map.coins == 0)
		victory(g);
	else if (g->map.map[new_y][new_x] == ENEMY)
		defeat(g);
}

void	move_player(t_game *g, int new_y, int new_x, int player_sprite)
{
	int	last_x;
	int	last_y;

	last_x = g->map.player.x;
	last_y = g->map.player.y;
	g->player_sprite = player_sprite;
	check_finish(g, new_y, new_x);
	if (g->map.map[new_y][new_x] == WALL)
	{
		g->map.player.x = last_x;
		g->map.player.y = last_y;
	}
	else if (g->map.map[new_y][new_x] == FLOOR
		|| g->map.map[new_y][new_x] == COINS)
	{
		g->map.map[last_y][last_x] = FLOOR;
		if (g->map.map[new_y][new_x] == COINS)
			g->map.coins--;
		g->map.player.x = new_x;
		g->map.player.y = new_y;
		g->map.map[new_y][new_x] = PLAYER;
		g->moves++;
		render_map(g);
	}
}

void	print_movements(t_game *g)
{
	char	*moves;

	moves = ft_itoa(g->moves);
	mlx_string_put(g->mlx, g->win, 20, 20, 16774912, "Moves :");
	mlx_string_put(g->mlx, g->win, 70, 20, 16774912, moves);
	free(moves);
	moves = NULL;
}
