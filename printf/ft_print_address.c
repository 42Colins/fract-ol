/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:58:21 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/03 23:45:51 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_address(size_t number, int *count)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (number >= 16)
	{
		ft_print_address(number / 16, count);
		ft_putchar(hexa[number % 16], count);
	}
	else
		ft_putchar(hexa[number % 16], count);
}
