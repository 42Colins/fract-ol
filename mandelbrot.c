/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:15:57 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/29 11:23:28 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

float	mandelbrot(t_pos checking, t_info mlx)
{
	double	runner;
	double	zn;
	double	x;
	double	y;

	x = 0;
	y = 0;
	runner = 0;
	while (runner < mlx.iter)
	{
		zn = (x * x) - (y * y) + checking.x;
		y = (2 * x * y + checking.y);
		x = zn;
		if ((x * x) + (y * y) > 4)
			return (runner);
		runner++;
	}
	return (1);
}

void	init_mandelbrot(t_info *mlx)
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
	mlx->julia_r = 0.418000;
	mlx->julia_i = -0.010000;
	mlx->color = 0xFFD7D5;
	mlx->fract_type = 1;
	mlx->motion = 15;
	mlx->sign = 1;
}
