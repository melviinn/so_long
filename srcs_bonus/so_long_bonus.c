/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:33:02 by mduchauf          #+#    #+#             */
/*   Updated: 2023/12/03 16:53:45 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->map_alloc = false;
	if (!game)
		error_msg("malloc() error: struct t_game could not be allocated", game);
	check_args(ac, av, game);
	check_map_len(av[1], game);
	init_map(game, av[1]);
	init_vars(game);
	check_map(game);
	if (check_path(game) == 1)
		error_msg("Invalid Map. There is no valid path", game);
	init_game(game);
	init_sprites(game);
	start_gameplay(game);
	mlx_loop(game->mlx);
	free_all_allocated_memory(game);
	return (0);
}
