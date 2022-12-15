# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2022/12/15 14:47:19 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

ARFLAGS = rcs

rm = rm -rf

HEADERS = ft_printf.h

SRCS =						

OBJS = $(SRCS:.c=.o)

$(NAME) :	$(OBJS) $(MINILIBX) Makefile
			ar $(ARFLAGS) $(NAME) $(OBJS)


all	:		$(NAME)



clean :
			${MAKE} clean -C minilibx
			$(RM) $(OBJS)

fclean :	clean
			${MAKE} fclean -C minilibx
			$(RM) $(NAME)

re :		fclean all
