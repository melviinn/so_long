/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:11:22 by mduchauf          #+#    #+#             */
/*   Updated: 2023/11/30 23:42:55 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all_allocated_memory(t_game *g)
{
	destroy_images(g);
	free_map(g);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	free(g);
}

void	free_map(t_game *g)
{
	int	str;

	str = 0;
	while (str < g->map.rows)
		free(g->map.map[str++]);
	free(g->map.map);
}

void	free_grid(char **grid)
{
	int	i;

	i = -1;
	while (grid[++i] != NULL)
		free(grid[i]);
	free(grid);
}

void	destroy_images(t_game *g)
{
	mlx_destroy_image(g->mlx, g->wall.xpm_ptr);
	mlx_destroy_image(g->mlx, g->floor.xpm_ptr);
	mlx_destroy_image(g->mlx, g->coins.xpm_ptr);
	mlx_destroy_image(g->mlx, g->player_front.xpm_ptr);
	mlx_destroy_image(g->mlx, g->player_left.xpm_ptr);
	mlx_destroy_image(g->mlx, g->player_right.xpm_ptr);
	mlx_destroy_image(g->mlx, g->player_back.xpm_ptr);
	mlx_destroy_image(g->mlx, g->exit_close.xpm_ptr);
	mlx_destroy_image(g->mlx, g->exit_open.xpm_ptr);
}
