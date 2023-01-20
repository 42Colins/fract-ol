#include "fract-ol.h"
#include <stdio.h>
#include <unistd.h>

int	zoom(int mousecode, int x, int y, t_info *info)
{
	info->reel_ptr = 0;
	info->im_ptr = 0;

	if (mousecode == 4) //zoom -
	{
		*info->zoom_ptr /= 1.1;
		if (info->iter - 1 != 3)
			info->iter -= 1;
		info->mouse_pos = mouse_pos(x, y, info);
		ft_putnbr(info->mouse_pos.x);
		ft_putchar('\n');
		ft_putnbr(info->mouse_pos.y);
		ft_putchar('\n');
		aff_fract(*info);
	}
	else if (mousecode == 5) //zoom +
	{
		*info->zoom_ptr *= 1.1;
		info->iter += 1;
		info->mouse_pos = mouse_pos(x, y, info);
		ft_putnbr(info->mouse_pos.x);
		ft_putchar('\n');
		ft_putnbr(info->mouse_pos.y);
		ft_putchar('\n');
		aff_fract(*info);
	}
	return (mousecode);
}

int	close_window(t_info *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	exit (0);
}

void	key_test(int key, t_info *mlx)
{
	t_pos	pos;

	pos.x = 0;
	pos.y = 0;
	ft_putnbr(key);
	if (key == 12) //Q
	{
		if (mlx->iter - 1 != 3)
			mlx->iter -= 1;
		mlx->reel_ptr = 0;
		mlx->im_ptr = 0;
	}
	if (key == 13) //W
	{
		mlx->iter += 1;
		mlx->reel_ptr = 0;
		mlx->im_ptr = 0;
	}
	if (key == 53) //ESC
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		exit (0);
	}
	aff_fract(*mlx);
}

t_pos	mouse_pos(int x, int y, t_info *mlx)
{
	t_pos	pos;


	//pos.x = ((x - (WINWIDTH / 2)) / (100 * (mlx->zoom)) + mlx->reel / 225);
	pos.x = (x - WINWIDTH / 2.0) / (0.5 * mlx->zoom * WINWIDTH) + mlx->mouse_pos.y / 250;
	//pos.x = ((x - (WINWIDTH / 2)) / (0.5 * (mlx->zoom) * WINWIDTH) + mlx->reel / 225);
	//pos.y = ((y - (WINHEIGTH / 2)) / (100 * (mlx->zoom)) + mlx->imaginary / 225);
	pos.y = (y - WINHEIGTH / 2.0) / (0.5 * mlx->zoom * WINHEIGTH) + mlx->mouse_pos.y / 250;
	pos.x *= 250;
	pos.y *= 250;
	mlx->mouse_ptr = &pos;
	ft_putnbr(pos.x);
	ft_putchar('\n');
	ft_putnbr(pos.y);
	return (pos);
}






















void    ft_next_putnbr(int x)
{
        char    mod;

        if (x > 9)
        {
                mod = x % 10 + 48;
                x = x / 10;
                ft_next_putnbr(x);
                write(1, &mod, 1);
        }
        else if ((x >= 0) && (x < 10))
        {
                mod = (x % 10) + 48;
                write(1, &mod, 1);
        }
}

void    ft_putnbr(int x)
{
    char    dash;

    dash = '-';
    if (x == -2147483648)
    {
        return ;
    }
    else if (x < 0)
    {
        ft_putnbr(x * -1);
    }
    ft_next_putnbr(x);
}

void    ft_print_address(size_t number)
{
        char    *hexa;

        hexa = "0123456789abcdef";
        if (number >= 16)
        {
                ft_print_address(number / 16);
                ft_putchar(hexa[number % 16]);
        }
        else
                ft_putchar(hexa[number % 16]);
}

void    ft_putchar(char c)
{
	write(1, &c, 1);
}
