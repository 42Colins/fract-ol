#include "fract-ol.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_pix	axis_converter(t_pix position, t_info mlx)
{
	t_pix	returned;

	returned.reel = ((position.reel - (WINWIDTH / 2)) / 100 * (mlx.zoom) - 0.5);
	returned.imaginary = ((position.imaginary - (WINHEIGTH / 2)) / 100 * (mlx.zoom));
	return (returned);
}

float	fractal(t_pix position, t_info mlx)
{
	double		runner;
	float	Zn;
	float	x;
	float	y;

	x = 0;
	y = 0;
	runner = 0;
	// printf("%f\n", position.reel);
	// printf("%f\n", position.imaginary);
	while(runner < mlx.iter)
	{
		Zn = (x * x) - (y * y) + position.reel;
		y = (2 * x * y + position.imaginary);
		x = Zn;
		if ((x * x) + (y * y) > 4)
			return (runner);
		// printf("x = %f\ny = %f\n", x, y);
		// printf("runner = %f\n\n", runner);
		runner++;
	}
	return (1);
}

void	*iter(t_info mlx)
{
	mlx.iter += 1;
}

void	aff_fract(t_info mlx, t_pix position, t_data img)
{
	t_pix	checking;
	float	checker;

	while (position.reel < WINWIDTH)
	{
		position.imaginary = 0;
		while(position.imaginary < WINHEIGTH)
		{
			checking = axis_converter(position, mlx);
			checker = fractal(checking, mlx);
			//printf("checker = %f\n", checker);
			if (checker == 1)
				my_mlx_pixel_put(&img, position.reel, position.imaginary, 0x000000);
			else if (checker == 2)
				my_mlx_pixel_put(&img, position.reel, position.imaginary, 0xb08968);
			else if (checker == 3)
				my_mlx_pixel_put(&img, position.reel, position.imaginary, 0x7f5539);
			else
				my_mlx_pixel_put(&img, position.reel, position.imaginary, 0x9c6644);
			position.imaginary++;
		}
		position.reel++;
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, img.img, 0, 0);
}

int main()
{
	t_info	mlx;
	t_data	img;
	t_pix	position;
	t_pix	checking;
	float	checker;

	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, WINWIDTH, WINHEIGTH, "fract-ol");
	img.img = mlx_new_image(mlx.mlx_ptr, WINWIDTH, WINHEIGTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx.iter = 40;
	mlx.zoom = 1;
	position.reel = 0;
	position.imaginary = 0;

	aff_fract(mlx, position, img);
	
	//mlx_key_hook(mlx.mlx_win, iter(), &mlx);
	mlx_loop(mlx.mlx_ptr);
}
