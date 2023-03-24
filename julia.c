/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:17:37 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/24 10:38:19 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

float	julia(t_pos checking, t_info mlx)
{
	double	runner;
	double	zn;
	double	x;
	double	y;

	x = checking.x;
	y = checking.y;
	runner = 0;
	while (runner < mlx.iter)
	{
		zn = (x * x) - (y * y) + mlx.julia_r;
		y = (2 * x * y) + mlx.julia_i;
		x = zn;
		if ((x * x) + (y * y) > 4)
			return (runner);
		runner++;
	}
	return (1);
}

void	init_julia(t_info *mlx)
{
	mlx->iter = 2;
	mlx->zoom = 0.7;
	mlx->reel = 0;
	mlx->imaginary = 0;
	mlx->count = 0;
	mlx->zoom_ptr = &mlx->zoom;
	mlx->reel_ptr = &mlx->reel;
	mlx->im_ptr = &mlx->imaginary;
	mlx->mouse_ptr = &mlx->mouse_pos;
	mlx->mouse_pos.x = 0;
	mlx->mouse_pos.y = 0;
	mlx->julia_i = 0.000000;
	mlx->julia_r = -1.5000;
	mlx->color = 0xFFD7D5;
	mlx->fract_type = 2;
}

void	insane_colors(t_info *mlx, int key)
{
	if (key == C)
		mlx->color *= 1.2;
	if (key == V)
		mlx->color *= 0.8;
	ft_printf("%p", mlx->color);
	aff_fract(*mlx);
}
