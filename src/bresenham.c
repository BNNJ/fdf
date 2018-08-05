/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 05:00:08 by pfragnou          #+#    #+#             */
/*   Updated: 2018/08/01 05:00:09 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	fdf_bresenham(t_fdf *fdf, int x0, int y0, int x1, int y1)
{
	t_bresenham	p;

	p.dx = abs (x1 - x0);
	p.dy = -abs (y1 - y0);
	p.sx = x0 < x1 ? 1 : -1;
	p.sy = y0 < y1 ? 1 : -1; 
	p.e1 = p.dx + p.dy;
	while (42)
	{
		fdf_add_pixel((int*)fdf->img->str, x0, y0, 0x00000000);
		if (x0 == x1 && y0 == y1)
			break ;
		p.e2 = 2 * p.e1;
		if (p.e2 >= p.dy)
		{
			p.e1 += p.dy;
			x0 += p.sx;
		}
		if (p.e2 <= p.dx)
		{
			p.e1 += p.dx;
			y0 += p.sy;
		}
	}
}
