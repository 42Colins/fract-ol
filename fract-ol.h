#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx/mlx.h"
# include <unistd.h>

#define WINWIDTH 500
#define WINHEIGTH 500

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_pos {
	float	reel;
	float	imaginary;
}				t_pix;

typedef struct	s_info{
	void	*mlx_ptr;
	void	*mlx_win;
	int		iter;
	float	zoom;
}				t_info;

void	zoom(int mousecode, t_info info);

#endif

