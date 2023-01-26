/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:16:22 by cprojean          #+#    #+#             */
/*   Updated: 2023/01/26 18:24:59 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx/mlx.h"
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
}	t_info;

//
int		zoom(int mousecode, int x, int y, t_info *info);
int		key_test(int key, t_info *mlx);
int		close_window(t_info *mlx);
void	aff_fract(t_info mlx);
t_pos	mouse_pos(int x, int y, t_info *mlx);
int		julia_keys(int key, t_info *mlx);

#endif
