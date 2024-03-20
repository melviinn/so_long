# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 22:39:07 by mduchauf          #+#    #+#              #
#    Updated: 2023/12/03 18:17:42 by mduchauf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				:=	srcs/so_long.c		srcs/check_maps.c		srcs/init_game.c \
						srcs/init_map.c		srcs/utils.c			srcs/render.c \
						srcs/input.c		srcs/free_utils.c		srcs/movements.c \
						srcs/pathfinding.c	srcs/check_maps_2.c	get_next_line/get_next_line.c \
						get_next_line/get_next_line_utils.c

SRCS_BONUS			:=	srcs_bonus/so_long_bonus.c			srcs_bonus/check_maps_bonus.c		srcs_bonus/init_game_bonus.c \
						srcs_bonus/init_map_bonus.c			srcs_bonus/utils_bonus.c			srcs_bonus/render_bonus.c \
						srcs_bonus/input_bonus.c			srcs_bonus/free_utils_bonus.c		srcs_bonus/movements_bonus.c \
						srcs_bonus/check_map_2_bonus.c		srcs_bonus/pathfinding_bonus.c		srcs_bonus/animation_bonus.c \
						get_next_line/get_next_line.c		get_next_line/get_next_line_utils.c

COMMON_SRCS_BONUS	:=	srcs_bonus/so_long_bonus.c		srcs_bonus/check_maps_bonus.c		srcs_bonus/init_game_bonus.c \
						srcs_bonus/init_map_bonus.c		srcs_bonus/utils_bonus.c			srcs_bonus/render_bonus.c \
						srcs_bonus/input_bonus.c		srcs_bonus/free_utils_bonus.c		srcs_bonus/movements_bonus.c \
						srcs_bonus/animation_bonus.c	srcs_bonus/pathfinding_bonus.c		srcs_bonus/check_map_len_bonus.c

CC					:= cc
OBJS				:= $(SRCS:.c=.o)
OBJS_BONUS			:= $(SRCS_BONUS:.c=.o)
NAME				:= so_long
NAME_BONUS			:= so_long_bonus

# Headers
HEADERS_LST			:= so_long.h
HEADERS_DIR			:= includes/
HEADERS				:= $(addprefix $(HEADERS_DIR), $(HEADERS_LST))

# Headers Bonus
HEADERS_BONUS_LST	:= so_long_bonus.h
HEADERS_BONUS_DIR	:= includes/
HEADERS_BONUS		:= $(addprefix $(HEADERS_BONUS_DIR), $(HEADERS_BONUS_LST))

# Printf
PRINTF_NAME			:= libftprintf.a
PRINTF_DIR			:= ft_printf/
PRINTF				:= $(addprefix $(PRINTF_DIR), $(PRINTF_NAME))

MLX_FLAGS			:= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
CFLAGS				:= -Wall -Wextra -Werror

# Mlx lib
MLX_PATH			:= mlx_linux/

# Libft lib
LIBFT_PATH			:= libft/
LIBFT_NAME			:= libft.a
LIBFT				:= $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))


# Colors
GREEN				:= \033[0;92m
BLUE				:= \033[0;94m
CYAN				:= \033[0;96m
YELLOW				:= \033[33m
RESET_COLOR			:= \033[0;39m

bold				:= $(shell tput bold)
sgr0				:= $(shell tput sgr0)

all: $(NAME)	## Build all the project

%.o: %.c
	@$(CC) $(CFLAGS) -I $(HEADERS) -I/usr/include -Imlx_linux -O3 -c -o $@ $<

$(NAME): $(OBJS)
	@echo "\n$(GREEN)----Compiling libft----$(RESET_COLOR)"
	@make --no-print-directory -C $(LIBFT_PATH)
	@echo "$(GREEN)----Compiling ft_printf----$(RESET_COLOR)"
	@make --no-print-directory -C $(PRINTF_DIR)
	@echo "$(GREEN)----Compiling so_long----$(RESET_COLOR)"
	@$(CC) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)
	@for obj in $(OBJS) ; do \
		echo Created $${obj} ; \
	done
	@echo Created $(NAME)
	@echo "\033[32mSo_long Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

$(NAME_BONUS):	$(OBJS_BONUS)
	@echo "\n$(GREEN)----Compiling libft----$(RESET_COLOR)"
	@make --no-print-directory -C $(LIBFT_PATH)
	@echo "$(GREEN)----Compiling ft_printf----$(RESET_COLOR)"
	@make --no-print-directory -C $(PRINTF_DIR)
	@echo "$(GREEN)----Compiling so_long----$(RESET_COLOR)"
	@$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME_BONUS)
	@for obj_bns in $(OBJS_BONUS) ; do \
		echo Created $${obj_bns} ; \
	done
	@echo Created $(NAME_BONUS)
	@echo "\033[32mSo_long bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

bonus: $(NAME_BONUS)	## Build the bonus program

libft:	## Build libft
	@make -C $(LIBFT_PATH)

libft_bonus:	## Build libft_bonus
	@make bonus -C $(LIBFT_PATH)

ft_printf:	## Build ft_printf
	@make -C $(PRINTF_DIR)

mlx:	## Build mlx
	@echo "$(GREEN)----Compiling mlx----$(RESET_COLOR)"
	@make --no-print-directory -C $(MLX_PATH)

clean:	## Remove all intermediate objects
	@make --no-print-directory clean -C $(LIBFT_PATH)
	@make --no-print-directory clean -C $(PRINTF_DIR)
	@rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean	## Remove all output and interemediate objects
	@echo "\033[33m----Cleaning libft----$(RESET_COLOR)"
	@make --no-print-directory fclean -C $(LIBFT_PATH)
	@echo "\033[33m----Cleaning ft_printf----$(RESET_COLOR)"
	@make --no-print-directory fclean -C $(PRINTF_DIR)
	@echo "\033[33m----Cleaning So_long----$(RESET_COLOR)"
	@rm -rf $(NAME) $(NAME_BONUS)
	@for obj in $(OBJS) ; do \
		echo Deleted $${obj} ; \
	done
	@for obj_bns in $(COMMON_SRCS_BONUS) ; do \
		echo Deleted $${obj_bns} ; \
	done
	@echo Deleted $(NAME)
	@echo Deleted $(NAME_BONUS)
	@echo "\033[31mEVERYTHING Deleted for So_long! ⌐(ಠ۾ಠ)¬\n"

help: ## Show help for each of the Makefile rules.
	@echo "Usage: make [rule] ...\n"
	@echo "rules:"
	@egrep -h '\s##\s' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m  %-30s\033[0m %s\n", $$1, $$2}'

re : fclean all

.PHONY: all clean fclean re libft mlx
