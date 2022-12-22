#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx/mlx.h"
# include <unistd.h>

#define INTER 20
#define WINWIDTH 1920
#define WINHEIGTH 1080

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_pos {
	double	reel;
	double	imaginary;
}				t_pix;

#endif
