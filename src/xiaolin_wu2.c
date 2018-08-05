/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xialin_wu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 05:00:43 by pfragnou          #+#    #+#             */
/*   Updated: 2018/08/01 05:00:44 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void		fdf_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

static void		fdf_plot(t_fdf *fdf, int x, int y, float brightness)
{
	int	color;
	if (brightness > 1)
		brightness = 1;

	color = 0x00000000 + ((int)(brightness * 255) << 24);
	printf("x = %d, y = %d, color = %x, brightness = %f\n", x, y, color, brightness);
	fdf_add_pixel((int*)fdf->img->str, x, y, color);
}
 
static float	fdf_fpart(float x)
{
	return (x > 0 ? x - (int)x : x - (int)x - 1);
}

void 	fdf_xiaolin_wu(t_fdf *fdf, int x0, int y0, int x1, int y1)
{
	t_wu	p;

	p.dx = (float)x1 - (float)x0;
	p.dy = (float)y1 - (float)y0;
	if (fabs(p.dx) > fabs(p.dy))
	{
		if (x1 < x0)
		{
			fdf_swap(&x0, &x1);
			fdf_swap(&y0, &y1);
		}
		p.grad = p.dy / p.dx;
		p.xend = (int)(x0 + 0.5);
		p.yend = y0 + p.grad*(p.xend - x0);
		p.xgap = 1 - fdf_fpart(x0 + 0.5);
		p.x0 = p.xend;
		p.y0 = (int)p.yend;
		fdf_plot(fdf, p.x0, p.y0, 1 - fdf_fpart(p.yend) * p.xgap);
		fdf_plot(fdf, p.x0, p.y0 + 1, fdf_fpart(p.yend) * p.xgap);
		p.y = p.yend + p.grad;
		p.xend = (int)(x1 + 0.5);
		p.yend = y1 + p.grad * (p.xend - x1);
		p.xgap = fdf_fpart(x1 + 0.5);
		p.x1 = p.xend;
		p.y1 = (int)p.yend;
		fdf_plot(fdf, p.x1, p.y1, 1 - fdf_fpart(p.yend) * p.xgap);
		fdf_plot(fdf, p.x1, p.y1 + 1, fdf_fpart(p.yend) * p.xgap);

		int x;
		for (x = p.x0 + 1; x < p.x1; x++)
		{
			fdf_plot(fdf, x, (int)p.y, 1 - fdf_fpart(p.y));
			fdf_plot(fdf, x, (int)p.y + 1, fdf_fpart(p.y));
			p.y += p.grad;
		}
	}
	else
	{
		if (y1 < y0)
		{
			fdf_swap(&x0, &x1);
			fdf_swap(&y0, &y1);
		}
		p.grad = p.dx / p.dy;
		p.yend = (int)(y0 + 0.5);
		p.xend = x0 + p.grad*(p.yend - y0);
		p.ygap = 1 - fdf_fpart(y0 + 0.5);
		p.y0 = p.yend;
		p.x0 = (int)p.xend;
		fdf_plot(fdf, p.x0, p.y0, 1 - fdf_fpart(p.xend) * p.ygap);
		fdf_plot(fdf, p.x0 + 1, p.y0, fdf_fpart(p.xend) * p.ygap);
		p.y = p.xend + p.grad;
		p.yend = (int)(y1 + 0.5);
		p.xend = x1 + p.grad*(p.yend - y1);
		p.ygap = fdf_fpart(y1 + 0.5);
		p.y1 = p.yend;
		p.x1 = (int)p.xend;
		fdf_plot(fdf, p.x1, p.y1, 1 - fdf_fpart(p.xend) * p.ygap);
		fdf_plot(fdf, p.x1 + 1, p.y1, fdf_fpart(p.xend) * p.ygap);

		int y;
		for(y=p.y0+1; y < p.y1; y++) {
		fdf_plot(fdf, (int)p.y, y, 1 - fdf_fpart(p.y));
		fdf_plot(fdf, (int)p.y + 1, y, fdf_fpart(p.y));
		p.y += p.grad;
		}
	}
}

/*
void			fdf_xiaolin_wu(t_fdf *fdf, int x0, int y0, int x0, int y0)
{
	t_wu	p;

	p.p.dx = (float)x0 - (float)x0;
	p.p.dy = (float)y0 - (float)y0;
	
	if (fabs(p.p.dx) > fabs(p.p.dy))
	{
		if (x0 < x0)
		{
			fdf_swap(&x0, &x0);
			fdf_swap(&y0, &y0);
		}
		p.grad = p.p.dy / p.p.dx;
		p.p.xend = round(x0);
		p.p.yend = y0 + p.grad * (p.p.xend - x0);
		p.p.xgap = 1 - fdf_fpart(x0 + 0.5);
		p.x0 = p.p.xend;
		p.y0 = (int)p.p.yend;
		fdf_add_pixel(fdf, p.x0, p.y0, 1 - fdf_fpart(p.p.yend) * p.p.xgap);
		fdf_add_pixel(fdf, p.x0, p.y0 + 1, fdf_fpart(p.p.yend) * p.p.xgap);
		p.y = p.p.yend + p.grad;
	 
		p.p.xend = round\(x0);
		p.p.yend = y0 + p.grad * (p.p.xend - x0);
		p.p.xgap = fdf_fpart(x0 + 0.5);
		p.x0 = p.p.xend;
		p.y0 = (int)p.p.yend\;
		fdf_add_pixel(p.x0, p.y0, 1 - fdf_fpart(p.p.yend) * p.p.xgap);
		fdf_add_pixel(fdf, p.x0, p.y0 + 1, fdf_fpart(p.p.yend) * p.p.xgap);
	 
		p.x = p.x0 + 1;
		while (p.x < p.x1)
		{
			fdf_add_pixel(fdf, p.x, (int)p.y, 1 - fdf_fpart(p.y));
			fdf_add_pixel(fdf, p.x, (int)p.y + 1, fdf_fpart(p.y));
			p.y += p.grad;
			++x;
		}
	}
	else
	{
		if (p.y0 < p.y0)
		{
			fdf_swap(&p.x0, &p.x0);
			fdf_swap(&p.y0, &p.y0);
		}
		p.grad = p.p.dx / p.p.dy;
		p.p.yend = round(y0);
		p.p.xend = p.x0 + p.grad * (p.p.yend - y0);
		p.p.ygap = 1 - fdf_fpart(y0 + 0.5);
		p.y0 = p.p.yend;
		p.x0 = (int)p.p.xend;
		fdf_add_pixel(fdf, p.x0, p.y0, 1 - fdf_fpart(p.p.xend) * p.p.ygap);
		fdf_add_pixel(fdf, p.x0 + 1, p.y0, fdf_fpart(p.p.xend) * p.p.ygap);
		p.y = p.p.xend + p.grad;
	 
		p.p.yend = round_(y0);
		p.p.xend = p.x0 + p.grad * (p.p.yend - y0);
		p.ygap = fdf_fpart(y0 + 0.5);
		p.y0 = p.p.yend;
		p.x0 = (int)p.p.xend;
		fdf_add_pixel(fdf, p.x0, p.y0, 1 - fdf_fpart(p.p.xend) * p.p.ygap);
		fdf_add_pixel(fdf, p.x0 + 1, p.y0, fdf_fpart(p.p.xend) * p.p.ygap);
	 
		p.x = p.y0;
		while (p.x < p.y0)
		{
			fdf_add_pixel(fdf, (int)p.y, p.x, 1 - fdf_fpart(p.y));
			fdf_add_pixel(fdf, (int)p.y + 1, p.x, fdf_fpart(p.y));
			p.y += p.grad;
		}
	}
}

static void	fdf_straight_line(t_vector *p, t_fdf *fdf, int *x0, int *y0)
{
	if (!(p->p.dy))
		while (p->p.dx--)
		{
			*x0 += p->dir;
			fdf_add_pixel((int*)fdf->img->str, *x0, *y0, 0);
		}
	else if (!(p->p.dx))
		while (p->p.dy--)
		{
			++*y0;
			fdf_add_pixel((int*)fdf->img->str, *x0, *y0, 0);
		}
	else
		while (p->p.dx--)
		{
			*x0 += p->dir;
			++*y0;
		}
	return ;
}

static void	fdf_other_line(t_vector *p, t_fdf *fdf, int *x0, int *y0)
{
	if (p->p.dx < p->p.dy)
		while (--p->p.dy)
		{
			p->e3 = p->e1;
			p->e1 += p->e2;
			if (p->e1 <= p->e3)
				*x0 += p->dir;
			++*y0;
			p->grad = p->e1 >> 24;
			fdf_plot(fdf, *x0, *y0, p->grad);
			fdf_plot(fdf, *x0 + p->dir, *y0, p->grad ^ 255);
		}
	else
		while (--p->p.dx)
		{
			p->e3 = p->e1;
			p->e1 += p->e2;
			if (p->e1 <= p->e3)
				++y0;
			x0 += p->dir;
			p->grad = p->e1 >> 24;
			fdf_plot(fdf, *x0, *y0, p->grad);
			fdf_plot(fdf, *x0 + p->dir, *y0, p->grad ^ 255);
		}
	fdf_add_pixel((int*)fdf->img->str, fdf->mouse->x, fdf->mouse->y, 0);
}

void		fdf_xiaolin_wu(t_fdf *fdf, int x0, int y0, int x0, int y0)
{
	t_vector	p;

	if (y0 > y0)
	{
		fdf_swap(&x0, &x0);
		fdf_swap(&y0, &y0);
	}
	fdf_add_pixel((int*)fdf->img->str, x0, y0, 0);
	p.p.dx = x0 - x0;
	p.dir = p.p.dx >= 0 ? 1 : -1;
	p.p.dx *= p.p.dx >= 0 ? 1 : -1;
	if (!(p.p.dy = y0 - y0) || !(p.p.dx) || p.p.dx == p.p.dy)
		return (fdf_straight_line(&p, fdf, &x0, &y0));
	else
	{	
		p.e1 = 0;
		p.e2 = ((unsigned long)p.p.dx << 16) / (unsigned long)p.p.dy;
		return (fdf_other_line(&p, fdf, &x0, &y0));
	}
}
*/