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

#include "../includes/so_long.h"

void	move_player(t_game *g, int new_y, int new_x, int player_sprite)
{
	int	last_x;
	int	last_y;

	last_x = g->map.player.x;
	last_y = g->map.player.y;
	g->player_sprite = player_sprite;
	if (g->map.map[new_y][new_x] == EXIT && g->map.coins == 0)
		victory(g);
	else if (g->map.map[new_y][new_x] == WALL)
	{
		g->map.player.x = last_x;
		g->map.player.y = last_y;
	}
	else if ((g->map.map[new_y][new_x] == FLOOR
		|| g->map.map[new_y][new_x] == COINS) && ++g->moves)
	{
		g->map.map[last_y][last_x] = FLOOR;
		if (g->map.map[new_y][new_x] == COINS)
			g->map.coins--;
		g->map.player.x = new_x;
		g->map.player.y = new_y;
		g->map.map[new_y][new_x] = PLAYER;
		render_map(g);
	}
	print_movements(g);
}

void	print_movements(t_game *g)
{
	static int	previous_count_movements = -1;
	int			current_count_movements;

	current_count_movements = g->moves;
	if (current_count_movements != previous_count_movements)
	{
		printf("You moved %d times.\n", current_count_movements);
		previous_count_movements = current_count_movements;
	}
}
