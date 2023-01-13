#include "fract-ol.h"
#include <stdio.h>
#include <unistd.h>

int	zoom(int mousecode, int x, int y, t_info info)
{
	(void)x;
	(void)y; 
	if (mousecode == 4)
	{
		info.zoom += 0.01;
		aff_fract(info);
	}
	else if (mousecode == 5)
	{
		if (info.zoom - 0.01 != 0)
			info.zoom -= 0.01;
		aff_fract(info);
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