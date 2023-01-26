# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2023/01/26 18:21:51 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract_ol

CC = gcc

CFLAGS = -Wall -Wextra -g -O3

MLXFLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

ARFLAGS = rcs

rm = rm -rf

HEADERS = fracto_ol.h

SRCS =	fract_ol.c	\
		hooks.c

OBJS = $(SRCS:.c=.o)

%.o: %.c	Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLXFLAGS) -o $(NAME)

all	:		$(NAME)

clean :
#${MAKE} clean -C minilibx
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(NAME)

re :		clean all
