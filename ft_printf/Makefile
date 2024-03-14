# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 15:38:57 by mduchauf          #+#    #+#              #
#    Updated: 2023/11/13 15:38:58 by mduchauf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c				ft_read_str.c			ft_write_decimal.c \
		ft_write_string.c		ft_write_char.c			ft_write_hexa.c \
		ft_write_uphexa.c		ft_write_unsigned.c		ft_write_percent.c \
		ft_write_ptr.c

HEADERS = header/ft_printf.h
NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Colors
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
YELLOW = \033[33m
RESET_COLOR = \033[0;39m



.c.o:
	@${CC} ${CFLAGS} -c -I ${HEADERS} $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@ranlib ${NAME}
	@echo "\033[32mft_printf Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ$(RESET_COLOR)\n"

all : ${NAME}

clean :
	@rm -rf ${OBJS}

fclean : clean
	@rm -f ${NAME}
	@echo "\033[31mEVERYTHING Deleted for ft_printf! ⌐(ಠ۾ಠ)¬$(RESET_COLOR)\n"

re : fclean all

.PHONY: all clean fclean re