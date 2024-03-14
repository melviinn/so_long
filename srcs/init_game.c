/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:50:03 by mduchauf          #+#    #+#             */
/*   Updated: 2023/12/03 18:44:34 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_vars(t_game *g)
{
	g->mlx = NULL;
	g->win = NULL;
	g->map.coins = 0;
	g->map.exit = 0;
	g->map.players = 0;
	g->map.exit_pos.x = 0;
	g->map.exit_pos.y = 0;
	g->moves = 0;
	g->map.columns = ft_strlen(g->map.map[0]);
	g->player_sprite = RIGHT;
}

void	init_game(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
	{
		free(g->mlx);
		error_msg("Couldn't find mlx pointer.", g);
	}
	g->win = mlx_new_window(g->mlx, g->map.columns * IMG_WIDTH,
			g->map.rows * IMG_HEIGHT, "so_long");
	if (!g->win)
	{
		free(g->win);
		error_msg("Couldn't create the window.", g);
	}
}

void	init_sprites(t_game *g)
{
	void	*mlx;

	mlx = g->mlx;
	g->wall = new_sprite(mlx, "textures/wall.xpm", g);
	g->coins = new_sprite(mlx, "textures/coin.xpm", g);
	g->exit_close = new_sprite(mlx, "textures/exit_close.xpm", g);
	g->exit_open = new_sprite(mlx, "textures/exit_open.xpm", g);
	g->floor = new_sprite(mlx, "textures/floor.xpm", g);
	g->player_front = new_sprite(mlx, "textures/player_front.xpm", g);
	g->player_left = new_sprite(mlx, "textures/player_left.xpm", g);
	g->player_right = new_sprite(mlx, "textures/player_right.xpm", g);
	g->player_back = new_sprite(mlx, "textures/player_back.xpm", g);
}

t_img	new_sprite(void *mlx, char *path, t_game *g)
{
	t_img	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (!sprite.xpm_ptr)
		error_msg("Couldn't find the sprite.", g);
	return (sprite);
}
