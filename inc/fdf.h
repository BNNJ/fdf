/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:39:38 by fstadelw          #+#    #+#             */
/*   Updated: 2018/12/01 03:02:58 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define DEFAULT_COLOR 0x00000000

# include <stdbool.h>

typedef struct	s_vec2
{
	int			x;
	int			y;
}				t_vec2;

typedef struct	s_pixel
{
	int			x;
	int			y;
	int			color;
}				t_pixel;

typedef struct	s_point
{
	int			color;
	int			h;
}				t_point;

typedef struct	s_map
{
	t_point		**map;
	t_vec2		size;
}				t_map;

typedef struct	s_mlx
{
	void		*image;
	char		*buff;
	int			buf_wid;
	void		*window;
	void		*mlx;
	t_vec2		win_size;
	int			bpp;
	int			endian;
}				t_mlx;

typedef struct	s_flag
{
	bool		disp_helper;
	int			height_mod;
	t_vec2		pos;
	int			zoom;
	int			angle_mod;
	int			exit_value;
	int			proj;
}				t_flag;

typedef struct	s_disp
{
	int				colortheme;
	int				bg_color;
	int				text_color;
	int				usage_color;
	unsigned int	(*get_col)(int h);
}				t_disp;

typedef struct	s_fdf
{
	t_map		map;
	t_mlx		mlx;
	t_flag		flag;
	t_disp		disp;
}				t_fdf;

/*
** init
*/
void			init_fdf(t_fdf *fdf, int x, int y);

/*
** mlx
*/
int				display_mlx_win(t_fdf *fdf);

/*
** hook
*/
int				key_hook(int keycode, t_fdf *fdf);
int				move_hook(int keycode, t_fdf *fdf);

/*
** exit
*/
int				fdf_exit(t_fdf *fdf);
void			free_map(t_map *map);

/*
** parser
*/
int				parser(t_fdf *fdf, const char *file_name);
int				add_line(t_fdf *fdf, char **arr);
int				check_line(t_fdf *fdf, char *line);

/*
** draw
*/
void			draw_win(t_fdf *fdf);
void			put_pixel(t_mlx *mlx, int x, int y, int color);
void			draw_line(t_mlx *mlx, t_pixel *p1, t_pixel *p2);
void			draw_fdf(t_fdf *fdf);

/*
** projection
*/
t_vec2			parallel_projection(t_fdf *fdf, int x, int y, int z);
t_vec2			isometric_projection(t_fdf *fdf, int x, int y, int z);

/*
** math
*/
double			deg_to_rad(int degree);
double			fpart(double x);

/*
** color
*/
void			get_next_colorcheme(t_disp *disp);

/*
** fade
*/
unsigned int	knife_fade(int h);
unsigned int	minecraft_fade(int h);
unsigned int	white_on_black(int h);

#endif
