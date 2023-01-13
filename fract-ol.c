#include "fract-ol.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_info *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_info	axis_converter(t_info mlx)
{
	t_info	returned;

	returned.reel = ((mlx.reel - (WINWIDTH / 2)) / 100 * (mlx.zoom));
	returned.imaginary = ((mlx.imaginary - (WINHEIGTH / 2)) / 100 * (mlx.zoom));
	return (returned);
}

float	fractal(t_info checking, t_info mlx)
{
	double		runner;
	float	Zn;
	float	x;
	float	y;

	x = 0;
	y = 0;
	runner = 0;
	while(runner < mlx.iter)
	{
		Zn = (x * x) - (y * y) + checking.reel;
		y = (2 * x * y + checking.imaginary);
		x = Zn;
		if ((x * x) + (y * y) > 4)
			return (runner);
		runner++;
	}
	return (1);
}

void	key_test(int key, t_info *mlx)
{
	ft_putnbr(key);
	mlx->iter += 1;
	mlx->reel_ptr = 0;
	mlx->im_ptr = 0;
	aff_fract(*mlx);
}

int		close_window(int key, t_info *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	exit(0);
}

void	aff_fract(t_info mlx)
{
	t_info	checking;
	float	checker;

	while (mlx.reel < WINWIDTH)
	{
		mlx.imaginary = 0;
		while(mlx.imaginary < WINHEIGTH)
		{
			checking = axis_converter(mlx);
			checker = fractal(checking, mlx);
			if (checker == 1)
				my_mlx_pixel_put(&mlx, mlx.reel, mlx.imaginary, 0x000000);
			else if (checker == 2)
				my_mlx_pixel_put(&mlx, mlx.reel, mlx.imaginary, 0xb08968);
			else if (checker == 3)
				my_mlx_pixel_put(&mlx, mlx.reel, mlx.imaginary, 0x7f5539);
			else if (checker >= 3)
				my_mlx_pixel_put(&mlx, mlx.reel, mlx.imaginary, 0xAAAAAA);
			else
				my_mlx_pixel_put(&mlx, mlx.reel, mlx.imaginary, 0x9c6644);
			mlx.imaginary++;
		}
		mlx.reel++;
	}
	if (mlx.count == 1)
		mlx_destroy_image(mlx.mlx_ptr, mlx.img_ptr);
	mlx.count = 1;
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img_ptr, 0, 0);
}

int main()
{
	t_info	mlx;
	float	checker;

	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, WINWIDTH, WINHEIGTH, "fract-ol");
	printf("%p\n", mlx.img_addr);
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WINWIDTH, WINHEIGTH);
	mlx.img_addr = mlx_get_data_addr(mlx.img_ptr, &mlx.bits_per_pixel, &mlx.line_length,
								&mlx.endian);
	printf("%p", mlx.img_addr);
	mlx.iter = 4;
	mlx.zoom = 1;
	mlx.reel = 0;
	mlx.imaginary = 0;
	mlx.count = 0;
	mlx.zoom_ptr = &mlx.zoom;
	mlx.reel_ptr = &mlx.reel;
	mlx.im_ptr = &mlx.imaginary;


	aff_fract(mlx);
	mlx_mouse_hook(mlx.mlx_win, zoom, &mlx);
	mlx_hook(mlx.mlx_win, 2, (1L<<0), key_test, &mlx);

	aff_fract(mlx);
	mlx_hook(mlx.mlx_win, 2, 1L<<0, close, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
