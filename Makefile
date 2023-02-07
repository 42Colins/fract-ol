# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2023/02/04 18:46:15 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract_ol

CC = gcc

CFLAGS = -Wall -Wextra -g -Ofast

MLXFLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

ARFLAGS = rcs

rm = rm -rf

HEADERS = fracto_ol.h

SRCS =	fract_ol.c	\
		hooks.c

OBJS = $(SRCS:.c=.o)

%.o: %.c	Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(PRINTF) Makefile $(MLX) Makefile
	$(MAKE) all -C mlx
	$(MAKE) all -C printf
	$(CC) $(OBJS) $(MLXFLAGS) -o $(NAME)

all	:		$(NAME)

clean :
			$(MAKE) clean -C printf
			$(MAKE) clean -C mlx
			$(RM) $(OBJS)

fclean :	clean
			$(MAKE) fclean -C printf
			$(RM) $(NAME)

re :		fclean all

.SILENT :	$(OBJS) $(MLXc)