# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2023/02/14 11:04:09 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(shell uname -s), Linux)
	MLXDIR	=	./minilibx/
	MLXFLAGS	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif
ifeq ($(shell uname -s), Darwin)
	MLXDIR	=	./mlx/
	MLXFLAGS =	-lmlx -framework OpenGL -framework AppKit
endif

NAME = fract_ol

CC = cc

CFLAGS = -Wall -Wextra -g -Ofast

libftFLAGS = -L./libft -lft

rm = rm -rf

HEADERS = fract_ol.h

SRCS =	fract_ol.c	\
		hooks.c

OBJS = $(SRCS:.c=.o)

%.o: %.c

	$(CC) $(libftFLAGS) -I/usr/include -Imlx_linux -O3 $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(libft) Makefile $(MLX) Makefile
	$(MAKE) bonus -C libft
	$(MAKE) all -C $(MLXDIR)
	$(CC) $(OBJS) -L$(MLXDIR) $(MLXFLAGS) $(libftFLAGS) -o $(NAME)

all	:		$(NAME)

clean :
			$(MAKE) clean -C libft
			$(MAKE) clean -C $(MLXDIR)
			$(RM) $(OBJS)

fclean :	clean
			$(MAKE) fclean -C libft
			$(RM) $(NAME)

re :		fclean all

.PHONY : libft all clean re fclean

.SILENT :	$(OBJS) $(MLXc) $(NAME) libft
