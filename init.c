/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:44:43 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/28 13:44:47 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	print_params(int argc, char **argv, t_info *mlx)
{
	ft_printf("Welcome to fract-ol !\n");
	ft_printf("Select what you wanna see \n");
	ft_printf("M for Mandelbrot \n");
	ft_printf("Or\n");
	ft_printf("J for Julia\n");
	ft_printf("Or\n");
	ft_printf("B for Burning Ship\n");
	if (argc == 4)
	{
		is_julia_args(argv, mlx);
	}
	else if (argc == 2)
		check_choice(argv[1], mlx);
	else
	{
		ft_printf("ERROR, WRONG ARGS");
		close_window(mlx);
	}
}

void	check_choice(char *array, t_info *mlx)
{
	if ((ft_strncmp(array, "M", 1) == 0) || ft_strncmp(array, "m", 1) == 0)
		init_mandelbrot(mlx);
	else if ((ft_strncmp(array, "J", 1) == 0) || ft_strncmp(array, "j", 1) == 0)
		init_julia(mlx);
	else if ((ft_strncmp(array, "B", 1) == 0) || ft_strncmp(array, "b", 1) == 0)
		init_b_ship(mlx);
	else
	{
		ft_printf("ERROR, WRONG ARGS");
		close_window(mlx);
	}
}

float	which_fractal(t_pos checking, t_info *mlx)
{
	if (mlx->fract_type == 1)
		return (mandelbrot(checking, *mlx));
	else if (mlx->fract_type == 2)
		return (julia(checking, *mlx));
	else if (mlx->fract_type == 3)
		return (b_ship(checking, *mlx));
	else
		return (-1);
}

void	is_julia_args(char **argv, t_info *mlx)
{
	if ((ft_strncmp(argv[1], "J", 1) == 0) \
		|| (ft_strncmp(argv[1], "j", 1) == 0))
	{
		init_julia(mlx);
		mlx->julia_r = ft_atof(argv[2]);
		mlx->julia_i = ft_atof(argv[3]);
	}
	else
	{
		ft_printf("ERROR, WRONG ARGS");
		close_window(mlx);
	}
}
