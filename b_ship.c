/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ship.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:19:04 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/23 15:03:28 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

float	b_ship(t_pos checking, t_info mlx)
{
	double	runner;
	double	zn;
	double	x;
	double	y;
	double	abs;

	x = 0;
	y = 0;
	runner = 0;
	while (runner < mlx.iter)
	{
		zn = (x * x) - (y * y) + checking.x;
		abs = x * y;
		if (abs < 0)
			abs *= -1;
		y = (2 * abs + checking.y);
		x = zn;
		if ((x * x) + (y * y) > 4)
			return (runner);
		runner++;
	}
	return (1);
}

void	init_b_ship(t_info *mlx)
{
	mlx->iter = 2;
	mlx->zoom = 1;
	mlx->reel = 0;
	mlx->imaginary = 0;
	mlx->count = 0;
	mlx->im_ptr = &mlx->imaginary;
	mlx->mouse_ptr = &mlx->mouse_pos;
	mlx->mouse_pos.x = 0;
	mlx->mouse_pos.y = 0;
	mlx->julia_r = 0.418000;
	mlx->julia_i = -0.010000;
	mlx->color = 0xC879FF;
	mlx->fract_type = 3;
}