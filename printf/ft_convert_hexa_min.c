/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa_min.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:43:48 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/03 23:45:57 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_hexa_min(unsigned int number, int *count)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (number >= 16)
	{
		ft_convert_hexa_min(number / 16, count);
		ft_putchar(hexa[number % 16], count);
	}
	else
		ft_putchar(hexa[number % 16], count);
}
