/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 09:18:32 by fstadelw          #+#    #+#             */
/*   Updated: 2018/11/29 09:21:36 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <math.h>

static void		plot(t_mlx *mlx, t_pixel p, double grad)
{
	unsigned int	c;
	unsigned int	shift;

	shift = (int)(0xFF * grad);
	c = (p.color | (shift << 24));
	put_pixel(mlx, p.x, p.y, c);
}

static void		fdf_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

static int		what_color_is_my_stupid_pixel(t_pixel *p1, t_pixel *p2, int mod)
{
	t_vec2	r;
	t_vec2	g;
	t_vec2	b;
	int		dist;

	dist = p2->x - p1->x;
	r.x = (p1->color & 0xFF0000) >> 16;
	r.y = (p2->color & 0xFF0000) >> 16;
	g.x = (p1->color & 0x00FF00) >> 8;
	g.y = (p2->color & 0x00FF00) >> 8;
	b.x = p1->color & 0x0000FF;
	b.y = p2->color & 0x0000FF;
	r.x += ((double)(r.y - r.x) / dist) * mod;
	g.x += ((double)(g.y - g.x) / dist) * mod;
	b.x += ((double)(b.y - b.x) / dist) * mod;
	return ((r.x << 16) + (g.x << 8) + b.x);
}

static void		drawline(int steep, t_mlx *mlx, t_pixel *p1, t_pixel *p2)
{
	int		color;
	int		x;
	double	y;
	double	grad;

	x = p1->x;
	y = (double)p1->y;
	grad = p2->x - p1->x
		? (double)(p2->y - p1->y) / (double)(p2->x - p1->x) : 1;
	while (x < p2->x)
	{
		color = what_color_is_my_stupid_pixel(p1, p2, x - p1->x);
		if (steep)
		{
			plot(mlx, (t_pixel){(int)y - 1, x, color}, fpart(y));
			plot(mlx, (t_pixel){(int)y, x, color}, 1 - fpart(y));
		}
		else
		{
			plot(mlx, (t_pixel){x, (int)y - 1, color}, fpart(y));
			plot(mlx, (t_pixel){x, (int)y, color}, 1 - fpart(y));
		}
		y += grad;
		++x;
	}
}

void			draw_line(t_mlx *mlx, t_pixel *p1, t_pixel *p2)
{
	int	steep;

	steep = ft_abs(p2->y - p1->y) > ft_abs(p2->x - p1->x);
	if (steep)
	{
		fdf_swap(&p1->x, &p1->y);
		fdf_swap(&p2->x, &p2->y);
	}
	if (p1->x > p2->x)
	{
		fdf_swap(&p1->x, &p2->x);
		fdf_swap(&p1->y, &p2->y);
		fdf_swap(&p1->color, &p2->color);
	}
	drawline(steep, mlx, p1, p2);
}
