# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2023/01/04 15:15:33 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

CC = gcc

CFLAGS = -Wall -Werror -Wextra -O3

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

ARFLAGS = rcs

rm = rm -rf

HEADERS = fracto-ol.h

SRCS =

OBJ =	fract-ol.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all	:		$(NAME)

clean :
			${MAKE} clean -C minilibx
			$(RM) $(OBJS)

fclean :	clean
			$(RM) $(NAME)

re :		fclean all
