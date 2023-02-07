/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:26:47 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/03 23:54:49 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_next_putnbr(int x, int *count)
{
	char	mod;

	if (x > 9)
	{
		mod = x % 10 + 48;
		x = x / 10;
		ft_next_putnbr(x, count);
		ft_putchar(mod, count);
	}
	else if ((x >= 0) && (x < 10))
	{
		mod = (x % 10) + 48;
		ft_putchar(mod, count);
	}
}

void	ft_putnbr(int x, int *count)
{
	char	dash;

	dash = '-';
	if (x == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	else if (x < 0)
	{
		ft_putchar(dash, count);
		ft_putnbr(x * -1, count);
	}
	ft_next_putnbr(x, count);
}
