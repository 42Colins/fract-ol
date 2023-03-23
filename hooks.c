/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:10:39 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/23 15:17:59 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdio.h>
#include <unistd.h>

int	zoom(int mousecode, int x, int y, t_info *info)
{
	info->reel_ptr = 0;
	info->im_ptr = 0;
	if (mousecode == 4)
	{
		info->zoom /= 1.1;
		if (info->iter - 1 != 3)
			info->iter -= 1;
		info->mouse_pos = mouse_pos(x, y, info);
		aff_fract(*info);
	}
	else if (mousecode == 5)
	{
		info->zoom *= 1.1;
		info->iter += 1;
		info->mouse_pos = mouse_pos(x, y, info);
		aff_fract(*info);
	}
	return (mousecode);
}

int	julia_keys(int key, t_info *mlx)
{
	if (key == REu)
		mlx->julia_r += 0.1;
	if (key == REd)
		mlx->julia_r -= 0.1;
	if (key == IMu)
		mlx->julia_i += 0.1;
	if (key == IMd)
		mlx->julia_i -= 0.1;
	aff_fract(*mlx);
	return (key);
}

int	close_window(t_info *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit (0);
}

int	key_test(int key, t_info *mlx)
{
	if (key == Q)
	{
		if (mlx->iter - 1 != 3)
			mlx->iter -= 1;
		mlx->reel_ptr = 0;
		mlx->im_ptr = 0;
		aff_fract(*mlx);
	}
	if (key == W)
	{
		mlx->iter += 1;
		mlx->reel_ptr = 0;
		mlx->im_ptr = 0;
		aff_fract(*mlx);
	}
	if (key == ESC)
	{
		close_window(mlx);
		exit (0);
	}
	if (key == C)
		insane_colors(mlx);
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

