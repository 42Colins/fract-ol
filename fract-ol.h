#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx/mlx.h"
# include <unistd.h>

#define WINWIDTH 500
#define WINHEIGTH 500

typedef struct	s_info{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		iter;
	float	zoom;
	float	reel;
	float	imaginary;
}				t_info;

int	zoom(int mousecode, int x, int y, t_info info);

void	aff_fract(t_info mlx);

void    ft_putnbr(int x);

void    ft_next_putnbr(int x);



#endif

