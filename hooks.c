#include "fract-ol.h"
#include <stdio.h>
#include <unistd.h>

void	zoom(int mousecode, t_info info)
{
	if (mousecode == 4)
	{
		info.zoom += 0.01;
	}
	else if (mousecode == 5)
	{
		info.zoom -= 0.01;
	}
	else if (mousecode == 3)
		write(1,"aigri", 5);
}
