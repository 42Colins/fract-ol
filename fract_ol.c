/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:10:34 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/29 11:23:38 by cprojean         ###   ########.fr       */
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

	returned.x = mlx.sign * (mlx.reel - WINWIDTH / 2.0) / \
	(0.5 * mlx.zoom * WINWIDTH) + mlx.mouse_pos.x / (250);
	returned.y = (mlx.imaginary - WINHEIGTH / 2.0) / \
	(0.5 * mlx.zoom * WINHEIGTH) + mlx.mouse_pos.y / (250);
	return (returned);
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
			checker = which_fractal(checking, &mlx);
			my_mlx_pixel_put(&mlx, mlx.reel, mlx.imaginary, \
				mlx.color * (checker / 5));
			mlx.imaginary++;
		}
		mlx.reel++;
	}
	if (mlx.count == 1)
		mlx_destroy_image(mlx.mlx_ptr, mlx.img_ptr);
	mlx.count = 1;
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img_ptr, 0, 0);
}

int	main(int argc, char **argv)
{
	t_info	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, WINWIDTH, WINHEIGTH, "fract-ol");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WINWIDTH, WINHEIGTH);
	mlx.img_addr = mlx_get_data_addr(mlx.img_ptr, &mlx.bits_per_pixel, \
	&mlx.line_length, &mlx.endian);
	print_params(argc, argv, &mlx);
	aff_fract(mlx);
	mlx_hook(mlx.mlx_win, 2, (1L << 0), key_test, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, close_window, &mlx);
	mlx_mouse_hook(mlx.mlx_win, zoom, &mlx);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_image(mlx.mlx_ptr, mlx.img_ptr);
	mlx_destroy_window(mlx.mlx_ptr, mlx.mlx_win);
	mlx_destroy_display(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
}
