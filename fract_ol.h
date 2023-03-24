/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:16:22 by cprojean          #+#    #+#             */
/*   Updated: 2023/03/23 15:37:22 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# ifdef __linux__
#  include"minilibx/mlx.h"
#  define ESC			65307
#  define Q			113
#  define W			119
#  define REU			114
#  define RED			116
#  define IMU			105
#  define IMD			111
#  define C			99
#  define V			118
# elif __APPLE__
#  include "../mlx/mlx.h"
#  define ESC			53
#  define Q			12
#  define W			13
#  define REU			15
#  define RED			17
#  define IMU			105
#  define IMD			111
# endif

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define WINWIDTH 1000
# define WINHEIGTH 1000

typedef struct s_pos{
	double	x;
	double	y;
}				t_pos;

typedef struct s_info{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		iter;
	int		*iter_ptr;
	double	zoom;
	double	*zoom_ptr;
	double	reel;
	double	*reel_ptr;
	double	*im_ptr;
	double	imaginary;
	double	julia_r;
	double	julia_i;
	int		count;
	t_pos	mouse_pos;
	t_pos	*mouse_ptr;
	int		fract_type;
	int		color;
}	t_info;

//
int		zoom(int mousecode, int x, int y, t_info *info);
int		key_test(int key, t_info *mlx);
int		close_window(t_info *mlx);
void	aff_fract(t_info mlx);
t_pos	mouse_pos(int x, int y, t_info *mlx);
int		julia_keys(int key, t_info *mlx);
void	print_params(int argc, char **argv, t_info *mlx);
void	check_choice(char *array, t_info *mlx);
float	which_fractal(t_pos checking, t_info *mlx);
float	mandelbrot(t_pos checking, t_info mlx);
void	init_mandelbrot(t_info *mlx);
float	julia(t_pos checking, t_info mlx);
void	init_julia(t_info *mlx);
float	b_ship(t_pos checking, t_info mlx);
void	init_b_ship(t_info *mlx);
void	insane_colors(t_info *mlx, int key);

#endif
