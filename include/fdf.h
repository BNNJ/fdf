/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 04:59:15 by pfragnou          #+#    #+#             */
/*   Updated: 2018/08/01 04:59:20 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_

# define FDF_PI 3.14159265359

# define WIDTH 1800
# define HEIGHT 1200
# define MIN_X 50
# define MAX_X 1750
# define MIN_Y 50
# define MAX_Y 1150

# define KEY_ESC 53
# define KEY_A 0
# define KEY_PLUS 24
# define KEY_MINUS 27

# include "../libft/includes/libft.h"
# include <math.h>
# include <mlx.h>

typedef struct	s_vector
{
	double			x;
	double			y;
	double			z;
}				t_vector;

typedef struct	s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}				t_point;

typedef struct	s_bresenham
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				e1;
	int				e2;
}				t_bresenham;

typedef struct	s_xiaolinwu
{
	float			dx;
	float			dy;
	float			grad;
	float			y;
	int				x;
	int				x0;
	int				x1;
	int				steep;
}				t_xiaolinwu;

typedef struct	s_img
{
	void			*ptr;
	char			*str;
	int				bpp;
	int				size;
	int				endian;
	int				x;
	int				y;
}				t_img;

typedef struct	s_map
{
	int		x;
	int		y;
	int		gap;
	int		midx;
	int		midy;
	int		**grid;
}				t_map;

typedef struct	s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			aa;
	t_point			*m;
	t_img			*img;
	t_map			*map;
}				t_fdf;

int					fdf_key_hook(int key, t_fdf *fdf);
int					fdf_m_move_hook(int x, int y, t_fdf *fdf);
int					fdf_majortom(t_fdf *fdf);

void				fdf_clear_image(int *img, int color);
void				fdf_add_pixel(int *img, int x, int y, int color);

int					fdf_do_magic(t_fdf *fdf, int x, int y);

int					fdf_parser(t_fdf *fdf, char *filename);

void				fdf_xiaolin_wu(t_fdf *fdf, int x0, int y0, int x1, int y1);
void				fdf_bresenham(t_fdf *fdf, int x0, int y0, int x1, int y1);

#endif
