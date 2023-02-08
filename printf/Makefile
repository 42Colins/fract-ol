# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2023/02/08 15:44:24 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

ARFLAGS = rcs

rm = rm -rf

HEADERS = ft_printf.h

SRCS =						ft_printf.c				\
							ft_convert_hexa_maj.c	\
							ft_convert_hexa_min.c	\
							ft_print_address.c		\
							ft_putnbr.c				\
							ft_putlnbr.c			\
							ft_putstr.c				\
							which_varia.c			\
							ft_putchar.c			\

OBJS = $(SRCS:.c=.o)

$(NAME) :	$(OBJS) $(LIBFT) Makefile
			$(MAKE) bonus -C libft
			ar $(ARFLAGS) $(NAME) $(OBJS)


all	:		$(NAME)



clean :
			${MAKE} clean -C libft
			$(RM) $(OBJS)

fclean :	clean
			${MAKE} fclean -C libft
			$(RM) $(NAME)

re :		fclean all

.SILENT : $(OBJS) $(NAME)