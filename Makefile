# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2023/02/08 15:55:45 by cprojean         ###   ########.fr        #
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

CC = gcc

CFLAGS = -Wall -Wextra -g -Ofast

PRINTFFLAGS = -L./printf -lprintf

ARFLAGS = rcs

rm = rm -rf

HEADERS = fracto_ol.h

SRCS =	fract_ol.c	\
		hooks.c

OBJS = $(SRCS:.c=.o)

printf :
	$(MAKE) all -C printf

%.o: %.c

	$(CC) $(PRINTFFLAGS) -I/usr/include -Imlx_linux -O3 $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) printf Makefile $(MLX) Makefile
	$(MAKE) all -C $(MLXDIR)
	$(CC) $(OBJS) -L$(MLXDIR) $(MLXFLAGS) $(PRINTFFLAGS) -o $(NAME)

all	:		$(NAME)

clean :
			$(MAKE) clean -C printf
			$(MAKE) clean -C $(MLXDIR)
			$(RM) $(OBJS)

fclean :	clean
			$(MAKE) fclean -C printf
			$(RM) $(NAME)

re :		fclean all

.PHONY : printf all clean re fclean

.SILENT :	$(OBJS) $(MLXc) $(NAME) printf
