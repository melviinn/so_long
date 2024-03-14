/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:02:40 by mduchauf          #+#    #+#             */
/*   Updated: 2023/12/03 18:45:09 by mduchauf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define IMG_WIDTH 32
# define IMG_HEIGHT 32

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define FRONT 1
# define LEFT 2
# define RIGHT 3
# define BACK 4

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define EVENT_CLOSE_BTN 17

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define RESET "\033[0m"

# include "../ft_printf/header/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>

typedef enum s_bool
{
	false,
	true
}			t_bool;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_img
{
	void	*xpm_ptr;
	int		x;
	int		y;
}			t_img;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		columns;
	int		coins;
	int		exit;
	int		players;
	t_pos	exit_pos;
	t_pos	player;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_bool	map_alloc;
	int		player_sprite;
	int		moves;
	t_img	wall;
	t_img	floor;
	t_img	coins;
	t_img	exit_close;
	t_img	exit_open;
	t_img	player_front;
	t_img	player_back;
	t_img	player_left;
	t_img	player_right;

}			t_game;

/* Check maps */
void		check_map(t_game *g);
int			check_path(t_game *g);
void		check_valid_path(t_game *g);
int			check_map_len(char *av, t_game *g);

/* Initialisation */
void		init_map(t_game *g, char *av);
void		init_game(t_game *g);
void		init_vars(t_game *g);
void		init_sprites(t_game *g);
t_img		new_sprite(void *mlx, char *path, t_game *g);

/* Utils */
char		*ft_strchr_new(const char *str, int argument);
char		*ft_strappend(char **s1, const char *s2);
int			error_msg(char *msg, t_game *g);
void		check_args(int ac, char **av, t_game *g);

/* Free Utils */
void		destroy_images(t_game *g);
void		free_all_allocated_memory(t_game *g);
void		free_map(t_game *g);

/* Events */
int			close_handler(t_game *g);
int			key_event(int keysym, t_game *g);
int			victory(t_game *g);

/* Render */
int			render_map(t_game *g);
void		render_sprite(t_game *g, t_img sprite, int row, int column);
void		print_movements(t_game *g);

/* Input */
int			handle_input(int keysym, t_game *g);

/* Movements */
void		move_player(t_game *g, int new_y, int new_x, int player_sprite);

#endif
