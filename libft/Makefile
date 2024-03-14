# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mduchauf <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 22:55:24 by mduchauf          #+#    #+#              #
#    Updated: 2024/02/08 19:16:07 by mduchauf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 			ft_atoi.c		ft_isalnum.c		ft_isalpha.c \
				ft_isascii.c	ft_isdigit.c		ft_isprint.c \
				ft_putchar_fd.c ft_putendl_fd.c		ft_putnbr_fd.c \
				ft_putstr_fd.c	ft_strdup.c			ft_strlcat.c \
				ft_strlen.c		ft_strncmp.c		ft_strtrim.c \
				ft_bzero.c		ft_memcpy.c			ft_memset.c \
				ft_memmove.c	ft_memchr.c			ft_strchr.c \
				ft_tolower.c 	ft_toupper.c		ft_strlcpy.c \
				ft_calloc.c 	ft_memcmp.c 		ft_substr.c \
				ft_strjoin.c 	ft_strrchr.c		ft_strnstr.c \
				ft_itoa.c		ft_split.c 			ft_strmapi.c \
				ft_striteri.c	ft_strcmp.c

SRCS_BONUS = 	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c \
				ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c \
				ft_lstiter.c 	ft_lstclear.c 		ft_lstmap.c 

HEADER = libft.h
NAME = libft.a

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Colors
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
RESET_COLOR = \033[0;39m

.c.o:
	@${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@ranlib ${NAME}
	@echo "\033[32mLibft Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

all : ${NAME}

bonus : ${OBJS_BONUS}
	@ar rcs ${NAME} ${OBJS_BONUS}
	@ranlib ${NAME}

clean :
	@rm -rf ${OBJS} ${OBJS_BONUS}

fclean : clean
	@rm -f ${NAME}
	@echo "\033[31mEVERYTHING Deleted for libft! ⌐(ಠ۾ಠ)¬\n"


re : fclean all
	@echo "$(GREEN)\nCleaned and Rebuild EVERYTHING for libft! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n$(RESET_COLOR)"


.PHONY: all bonus clean fclean re
