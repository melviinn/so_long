/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:23:50 by mduchauf          #+#    #+#             */
/*   Updated: 2023/11/30 23:41:30 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_input(int keysym, t_game *g)
{
	if (!g)
		return (0);
	if (keysym == KEY_W || keysym == KEY_UP)
		move_player(g, g->map.player.y - 1, g->map.player.x, BACK);
	else if (keysym == KEY_A || keysym == KEY_LEFT)
		move_player(g, g->map.player.y, g->map.player.x - 1, LEFT);
	else if (keysym == KEY_S || keysym == KEY_DOWN)
		move_player(g, g->map.player.y + 1, g->map.player.x, FRONT);
	else if (keysym == KEY_D || keysym == KEY_RIGHT)
		move_player(g, g->map.player.y, g->map.player.x + 1, RIGHT);
	else if (keysym == XK_Escape || keysym == EVENT_CLOSE_BTN)
	{
		close_handler(g);
		return (0);
	}
	else
		return (1);
	return (0);
}
