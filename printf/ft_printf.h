/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:38:20 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/01 16:45:11 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

//ft_printf
int		ft_printf(const char *array, ...);

//ft_putchar
void	ft_putchar(char c, int *count);

//ft_putstr
void	ft_putstr(char *str, int *count);

//ft_putnbr
void	ft_putnbr(int x, int *count);
void	ft_putlnbr(unsigned int x, int *count);

//ft_convert_hexa
void	ft_convert_hexa_maj(unsigned int number, int *count);
void	ft_convert_hexa_min(unsigned int number, int *count);
void	ft_print_address(size_t number, int *count);
//which_varia
void	which_varia(const char *array, va_list variadic, size_t *i, int *count);

#endif
