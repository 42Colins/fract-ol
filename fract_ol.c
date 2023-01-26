/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:10:34 by cprojean          #+#    #+#             */
/*   Updated: 2023/01/26 18:27:51 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_info *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->line_length + x \
	* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_pos	axis_converter(t_info mlx)
{
	t_pos	returned;

	returned.x = (mlx.reel - WINWIDTH / 2.0) / \
	(0.5 * mlx.zoom * WINWIDTH) + mlx.mouse_pos.x / (250);
	returned.y = (mlx.imaginary - WINHEIGTH / 2.0) / \
	(0.5 * mlx.zoom * WINHEIGTH) + mlx.mouse_pos.y / (250);
	return (returned);
}

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

void	aff_fract(t_info mlx)
{
	t_pos	checking;
	float	checker;

	while (mlx.reel < WINWIDTH)
	{
		mlx.imaginary = 0;
		while (mlx.imaginary < WINHEIGTH)
		{
			checking = axis_converter(mlx);
			//checker = mandelbrot(checking, mlx);
			checker = julia(checking, mlx);
			my_mlx_pixel_put(&mlx, mlx.reel, mlx.imaginary, 0xFFD7D5 * checker);
			mlx.imaginary++;
		}
		mlx.reel++;
	}
	if (mlx.count == 1)
		mlx_destroy_image(mlx.mlx_ptr, mlx.img_ptr);
	mlx.count = 1;
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img_ptr, 0, 0);
}

void	init_mlx(t_info *mlx)
{
	mlx->iter = 4;
	mlx->zoom = 0.5;
	mlx->reel = 0;
	mlx->imaginary = 0;
	mlx->count = 0;
	mlx->zoom_ptr = &mlx->zoom;
	mlx->reel_ptr = &mlx->reel;
	mlx->im_ptr = &mlx->imaginary;
	mlx->mouse_ptr = &mlx->mouse_pos;
	mlx->mouse_pos.x = 0;
	mlx->mouse_pos.y = 0;
	mlx->julia_r = -0.8;
	mlx->julia_i = 0.4;
}

int main()
{
	t_info	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, WINWIDTH, WINHEIGTH, "fract-ol");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WINWIDTH, WINHEIGTH);
	mlx.img_addr = mlx_get_data_addr(mlx.img_ptr, &mlx.bits_per_pixel, \
	&mlx.line_length, &mlx.endian);
	init_mlx(&mlx);
	aff_fract(mlx);
	mlx_hook(mlx.mlx_win, 2, (1L<<0), key_test, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, close_window, &mlx);
	mlx_mouse_hook(mlx.mlx_win, zoom, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
