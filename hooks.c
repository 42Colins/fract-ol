#include "fract-ol.h"
#include <stdio.h>
#include <unistd.h>

int	zoom(int mousecode, int x, int y, t_info *info)
{
	(void)x;
	(void)y;
	info->reel_ptr = 0;
	info->im_ptr = 0;
	if (mousecode == 4)
	{
		*info->zoom_ptr += 0.01;
		//mlx_destroy_image(info->mlx_ptr, info->img_ptr);
		aff_fract(*info);
	}
	else if (mousecode == 5)
	{
		if (*info->zoom_ptr - 0.01 != 0)
			*info->zoom_ptr -= 0.01;
		//mlx_destroy_image(info->mlx_ptr, info->img_ptr);
		aff_fract(*info);
	}
	return (mousecode);
}

void    			ft_next_putnbr(int x)
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
