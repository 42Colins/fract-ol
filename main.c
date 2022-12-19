/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:49:18 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/19 16:44:25 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *params)
{
	ft_putchar('X');
	return (0);
}

float	fractal(double pt_x, double pt_y)
{
	int		max_iter;
	int		runner;
	double	Zn;
	double	x;
	double	y;

	x = 0;
	y = 0;
	runner = 0;
	max_iter = 10;
	while(runner < max_iter)
	{
		Zn = ((x * x) - (y * y) + pt_x);
		y = (2 * x * y) + pt_y;
		x = Zn;
		if ((x * x) + (y * y) > 4)
			return (runner / max_iter);
		runner++;
	}
	return (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	t_data	img;
	//void	*img.addr;
	void	*window;
	double	x;
	double	y;

	img.addr = mlx_init();
	img.img = mlx_new_image(img.addr, WINWIDTH, WINHEIGTH);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	window = mlx_new_window(img.addr, WINWIDTH, WINHEIGTH, "Window");
	x = 0;
	y = 0;
	//fractal(pixel.x, pixel.y);
	while (x != WINHEIGTH)
	{
		while (y != WINWIDTH)
		{
			if (fractal(x/480, y/270) == 1)
				my_mlx_pixel_put(&img, x, y, 0xAAAAAA);
			else
				my_mlx_pixel_put(&img, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
	//mlx_put_image_to_window(img.addr, window, );
	//mlx_pixel_put(img.addr, window, 250, 250, 0xFFFFFF);
	mlx_put_image_to_window(img.addr, window, img.img, WINWIDTH/2, WINHEIGTH/2);
	mlx_key_hook(window, deal_key, (void *)0);
	mlx_loop(img.addr);
}
