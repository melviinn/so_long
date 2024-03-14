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

static char	check_surrounding(int y, int x, t_game *g)
{
	if (g->map.map[y][x] == WALL)
		return (1);
	return (0);
}

int	check_path(t_game *g)
{
	if (check_surrounding(g->map.player.y + 1, g->map.player.x, g) == 1)
		if (check_surrounding(g->map.player.y, g->map.player.x + 1, g) == 1)
			if (check_surrounding(g->map.player.y - 1, g->map.player.x, g) == 1)
				if (check_surrounding(g->map.player.y, g->map.player.x - 1,
						g) == 1)
					return (1);
	return (0);
}
