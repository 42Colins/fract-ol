#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>

#define WINWIDTH 500
#define WINHEIGTH 500


typedef struct	s_pos{
	double	x;
	double	y;
}				t_pos;

typedef struct	s_info{
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
	int		count;
	t_pos	mouse_pos;
	t_pos	*mouse_ptr;
	}			t_info;


int	zoom(int mousecode, int x, int y, t_info *info);

void	key_test(int key, t_info *mlx);

int		close_window(t_info *mlx);

void	aff_fract(t_info mlx);

void    ft_putnbr(int x);

void    ft_next_putnbr(int x);

void    ft_putchar(char c);

void    ft_print_address(size_t number);

t_pos	mouse_pos(int x, int y, t_info *mlx);

#endif
