/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:27:12 by mduchauf          #+#    #+#             */
/*   Updated: 2023/12/03 18:44:42 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_sprite(t_game *g, t_img sprite, int row, int column)
{
	mlx_put_image_to_window(g->mlx, g->win,
		sprite.xpm_ptr, (column * sprite.x), (row * sprite.y));
}

static void	render_player(t_game *g, int y, int x)
{
	if (g->player_sprite == FRONT)
		render_sprite(g, g->player_front, y, x);
	if (g->player_sprite == BACK)
		render_sprite(g, g->player_back, y, x);
	if (g->player_sprite == LEFT)
		render_sprite(g, g->player_left, y, x);
	if (g->player_sprite == RIGHT)
		render_sprite(g, g->player_right, y, x);
}

static void	identify_sprite(t_game *g, int y, int x)
{
	char	param;

	param = g->map.map[y][x];
	if (param == WALL)
		render_sprite(g, g->wall, y, x);
	else if (param == COINS)
		render_sprite(g, g->coins, y, x);
	else if (param == FLOOR)
		render_sprite(g, g->floor, y, x);
	else if (param == EXIT)
	{
		if (g->map.coins == 0)
			render_sprite(g, g->exit_open, y, x);
		else
			render_sprite(g, g->exit_close, y, x);
	}
	else if (param == PLAYER)
		render_player(g, y, x);
}

int	render_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.rows)
	{
		x = 0;
		while (x < g->map.columns)
		{
			identify_sprite(g, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
