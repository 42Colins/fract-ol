/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:10:39 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/01 18:30:45 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
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
		aff_fract(*info);
	}
	else if (mousecode == 5) //zoom +
	{
		*info->zoom_ptr *= 1.1;
		info->iter += 1;
		info->mouse_pos = mouse_pos(x, y, info);
		aff_fract(*info);
	}
	return (mousecode);
}

int	julia_keys(int key, t_info *mlx)
{
	if (key == 15) //R 15
		mlx->julia_r += 0.1;
	if (key == 17) //T 17
		mlx->julia_r -= 0.1;
	if (key == 34) //I 34
		mlx->julia_i += 0.1;
	if (key == 31) //31 O
		mlx->julia_i -= 0.1;
	aff_fract(*mlx);
	return (key);
}

int	close_window(t_info *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	exit (0);
}

int	key_test(int key, t_info *mlx)
{
	t_pos	pos;

	pos.x = 0;
	pos.y = 0;
	if (key == 12) //Q
	{
		if (mlx->iter - 1 != 3)
			mlx->iter -= 1;
		mlx->reel_ptr = 0;
		mlx->im_ptr = 0;
		aff_fract(*mlx);
	}
	if (key == 13) //W
	{
		mlx->iter += 1;
		mlx->reel_ptr = 0;
		mlx->im_ptr = 0;
		aff_fract(*mlx);
	}
	if (key == 53) //ESC
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		exit (0);
	}
	julia_keys(key, mlx);
	return (key);
}

t_pos	mouse_pos(int x, int y, t_info *mlx)
{
	t_pos	pos;

	pos.x = (x - WINWIDTH / 2.0) / \
	(0.5 * mlx->zoom * WINWIDTH) + mlx->mouse_pos.x / (250);
	pos.y = (y - WINHEIGTH / 2.0) / \
	(0.5 * mlx->zoom * WINHEIGTH) + mlx->mouse_pos.y / (250);
	pos.x *= 250;
	pos.y *= 250;
	mlx->mouse_ptr = &pos;
	return (pos);
}
