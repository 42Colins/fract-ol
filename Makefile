# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2023/03/29 10:46:50 by cprojean         ###   ########.fr        #
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

CFLAGS = -Wall -Wextra -Werror -g -Ofast

libftFLAGS = -L./libft -lft

rm = rm -rf

LIB = libft/libft.a

HEADERS = fract_ol.h

SRCS =	fract_ol.c	\
		hooks.c		\
		mandelbrot.c\
		julia.c		\
		b_ship.c	\
		init.c		\
		ft_atof.c

OBJS = $(SRCS:.c=.o)

all	:	libft MLX $(NAME)

%.o: %.c	$(LIB)
	$(CC) $(libftFLAGS) -I/usr/include -Imlx_linux -O3 $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(libft) $(MLX)
	$(CC) $(OBJS) -L$(MLXDIR) $(MLXFLAGS) $(libftFLAGS) -o $(NAME)

libft:
		$(MAKE) -C libft

MLX:
		$(MAKE) -C $(MLXDIR)

clean :
			$(MAKE) clean -C libft
			$(MAKE) clean -C $(MLXDIR)
			$(RM) $(OBJS)

fclean :	clean
			$(MAKE) fclean -C libft
			$(RM) $(NAME)

re :		fclean all

.PHONY : libft all clean re fclean

# .SILENT :	$(OBJS) $(MLXc) $(NAME) libft
