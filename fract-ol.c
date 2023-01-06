#include "fract-ol.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_pix	axis_converter(t_pix position)
{
	t_pix	returned;

	returned.reel = ((position.reel - (WINWIDTH / 2)) / 100);
	returned.imaginary = ((position.imaginary - (WINHEIGTH / 2)) / 100);
	return (returned);
}

float	fractal(t_pix position)
{
	double		max_iter;
	double		runner;
	float	Zn;
	float	x;
	float	y;

	x = 0;
	y = 0;
	runner = 0;
	max_iter = 100;
	// printf("%f\n", position.reel);
	// printf("%f\n", position.imaginary);
	while(runner < max_iter)
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

int main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_pix	position;
	t_pix	checking;
	float	checker;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINWIDTH, WINHEIGTH, "fract-ol");
	img.img = mlx_new_image(mlx, WINWIDTH, WINHEIGTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	position.reel = 0;
	position.imaginary = 0;
	while (position.reel < WINWIDTH)
	{
		position.imaginary = 0;
		while(position.imaginary < WINHEIGTH)
		{
			checking = axis_converter(position);
			checker = fractal(checking);
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
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
