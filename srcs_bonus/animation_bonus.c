/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:04:24 by mduchauf          #+#    #+#             */
/*   Updated: 2023/12/08 12:04:25 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include <unistd.h>

int	anim_stars(t_game *g)
{
	t_img	sprite;

	if (g->anim_coins >= 300)
		g->anim_coins = 0;
	sprite = g->coins;
	mlx_destroy_image(g->mlx, sprite.xpm_ptr);
	if (g->anim_coins <= 100)
		g->coins = new_sprite(g->mlx, "textures/bonus/coin_0.xpm", g);
	else if (g->anim_coins <= 200)
		g->coins = new_sprite(g->mlx, "textures/bonus/coin_1.xpm", g);
	else if (g->anim_coins <= 300)
		g->coins = new_sprite(g->mlx, "textures/bonus/coin_2.xpm", g);
	g->anim_coins++;
	return (0);
}

int	refresh_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	render_map(game);
	anim_stars(game);
	return (0);
}
