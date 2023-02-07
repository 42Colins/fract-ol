/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:47:59 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/03 23:52:54 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	int		index;
	char	*null;

	null = "(null)";
	index = 0;
	if (!str)
	{
		str = null;
	}
	while (str[index])
	{
		ft_putchar(str[index], count);
		index++;
	}
}
