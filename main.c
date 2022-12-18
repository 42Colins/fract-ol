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
	int	max_iter;
	int	runner;
	double	Zn;
	double	x;
	double	y;

	x = 0;
	y = 0;
	runner = 0;
	max_iter = 20;
	while(runner < max_iter)
	{
		Zn = (x * x - y * y + pt_x);
		y = 2 * x * y + pt_y;
		x = Zn;
		if (x * x + y * y > 4)
			return (runner / max_iter);
		runner++;
	}
	return (1);
}

int main()
{
	pix_pos	pixel;
	void *mlx_ptr;
	void *window;
	double	x;
	double	y;

	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, WINWIDTH, WINHEIGTH, "Window");
	x = 0;
	y = 0;
	//fractal(pixel.x, pixel.y);
	while (x != WINHEIGTH)
	{
		while (y != WINWIDTH)
		{

			if (fractal(x, y) == 1)
				mlx_pixel_put(mlx_ptr, window, x, y, 0xFFFFFF);
			else
				mlx_pixel_put(mlx_ptr, window, x, y, 0xAAAAAA);
			y++;
		}
		x++;
	}
	//mlx_pixel_put(mlx_ptr, window, 250, 250, 0xFFFFFF);
	mlx_key_hook(window, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
