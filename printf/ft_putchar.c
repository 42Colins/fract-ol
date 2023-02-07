/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:48:52 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/03 23:22:23 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	if (*count == -1)
		return ;
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return ;
	}
	*count = *count + 1;
}
