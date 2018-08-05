/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:47:46 by pfragnou          #+#    #+#             */
/*   Updated: 2018/08/01 12:47:47 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void		fdf_plot(t_fdf *fdf, int x, int y, float grad)
{
	unsigned int	c;
	int				shift;

	shift = (int)(255 * grad);	
	c = (shift << 16) + (shift << 8) + shift;
	fdf_add_pixel((int*)fdf->img->str, x, y, c);
}

static void		fdf_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

static float	fdf_fpart(float x)
{
	return (x > 0 ? x - (int)x : x - (int)x - 1);
}

static void		fdf_drawline(t_xiaolinwu *p, t_fdf *fdf)
{
	if (p->steep)
	{
		p->x = p->x0;
		while (p->x < p->x1)
		{
			fdf_plot(fdf, (int)p->y, p->x, 1 - fdf_fpart(p->y));
			fdf_plot(fdf, (int)p->y - 1, p->x, fdf_fpart(p->y));
			p->y += p->grad;
			++p->x;
		}
	}
	else
	{
		p->x = p->x0;
		while (p->x < p->x1)
		{
			fdf_plot(fdf, p->x, (int)p->y, 1 - fdf_fpart(p->y));
			fdf_plot(fdf, p->x, (int)p->y - 1, fdf_fpart(p->y));
			p->y += p->grad;
			++p->x;
		}
	}
}

void 			fdf_xiaolin_wu(t_fdf *fdf, int x0 , int y0 , int x1 , int y1)
{
	t_xiaolinwu	p;

	p.steep = abs(y1 - y0) > abs(x1 - x0) ;
	if (p.steep)
	{
		fdf_swap(&x0 , &y0);
		fdf_swap(&x1 , &y1);
	}
	if (x0 > x1)
	{
		fdf_swap(&x0 ,&x1);
		fdf_swap(&y0 ,&y1);
	}
	p.dx = x1 - x0;
	p.dy = y1 - y0;
	p.grad = p.dy / p.dx;
	if (p.dx == 0.0)
		p.grad = 1;
	p.x0 = x0;
	p.x1 = x1;
	p.y = y0;
	fdf_drawline(&p, fdf);
}
