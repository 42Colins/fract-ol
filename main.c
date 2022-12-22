/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:49:18 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/22 18:06:32 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *params)
{
	ft_putchar('X');
	return (0);
}

// long	iteration_nb_julia(t_complex z, t_complex *c)
// {
// 	long	i;
// 	double	zrtemp;

// 	i = 0;
// 	while ((z.r * z.r) + (z.i * z.i) <= 4 && i < c->max)
// 	{
// 		zrtemp = z.r;
// 		z.r = (z.r * z.r) - (z.i * z.i) - c->r;
// 		z.i = (2 * zrtemp * z.i) - c->i;
// 		i++;
// 	}

float	fractal(t_pix position)
{
	int		max_iter;
	int		runner;
	double	Zn;
	double	x;
	double	y;

	x = 0;
	y = 0;
	runner = 0;
	max_iter = 30;
	while(runner < max_iter && (x * x) + (y * y) <= 4)
	{
		Zn = (x);
		x = (x * x) - (y * y);
		y = (2 * Zn * position.imaginary);
		printf("x = %f\ny = %f\n", x, y);
		printf("runner = %d\n\n", runner);
		runner++;
	}
	return (runner);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_pix	position;
	int	nb;
	int	max_iter = 30;

	position.reel = 0;
	position.imaginary = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINWIDTH, WINHEIGTH, "Hello world!");
	img.img = mlx_new_image(mlx, WINWIDTH, WINHEIGTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (position.imaginary < WINHEIGTH)
	{
		position.reel = 0;
		while (position.reel < WINWIDTH)
		{
			nb = fractal(position);
			//printf("nb = %d\n", nb);
			if (nb == max_iter)
				my_mlx_pixel_put(&img, position.reel, position.imaginary, 0x101010);
			else
				my_mlx_pixel_put(&img, position.reel, position.imaginary, 0x100010);
			position.reel++;
		}
		position.imaginary++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
