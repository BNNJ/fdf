/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:32:12 by pfragnou          #+#    #+#             */
/*   Updated: 2018/08/04 18:32:13 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

double		fdf_rad(double angle)
{
	return (angle * M_PI / 180);
}

t_vector	fdf_proj_par(t_fdf *fdf, int x, int y, int z)
{
	t_vector	v;

	x = ((x - fdf->map->x / 2) * fdf->map->gap);
	y = ((y - fdf->map->y / 2) * fdf->map->gap) + z * 20;
	v.x = x - cos(30) * -y;
	v.y = -z - sin(30) * -y;
//	v.z = z;
	v.x = fdf->map->midx - v.x;
	v.y = fdf->map->midy - v.y;
	return (v);
}

t_vector	fdf_proj_iso(t_fdf *fdf, int x, int y, int z)
{
	t_vector	v;

	write(1, "check\n", 6);
	x = ((x - fdf->map->x / 2) * fdf->map->gap);
	y = ((y - fdf->map->y / 2) * fdf->map->gap) + z * 20;
	v.x = cos(fdf_rad(-30)) * x + cos(fdf_rad(-150)) * y;
	v.y = -z - sin(fdf_rad(-150)) * y - sin(fdf_rad(-30)) * x;
	v.z = z;
	v.x = fdf->map->midx - v.x;
	v.y = fdf->map->midy - v.y;
	return (v);
}

int			fdf_do_magic(t_fdf *fdf, int x, int y)
{
	t_vector	v1;
	t_vector	v2;

	v1 = fdf_proj_par(fdf, x, y, fdf->map->grid[y][x]);
	printf("%F, %F, %F\n", v1.x, v1.y, v1.z);
	if (x < fdf->map->x - 1)
	{
		v2 = fdf_proj_iso(fdf, x + 1, y, fdf->map->grid[y][x + 1]);
		fdf_xiaolin_wu(fdf, v1.x, v1.y, v2.x, v2.y);
	}
	if (y < fdf->map->y - 1)
	{	
		v2 = fdf_proj_iso(fdf, x, y + 1, fdf->map->grid[y + 1][x]);
		fdf_xiaolin_wu(fdf, v1.x, v1.y, v2.x, v2.y);
	}
	return (1);
}


/*
x0 = fdf->map->midx + ((x - fdf->map->x / 2) * fdf->map->gap);

parallele
x = p.x - cos(angle) * -p.y
y = -p.z - sin(angle) * -p.y

iso
x = cos(angle(-30)) * p.x + cos(angle(-150)) * p.y
y = -p.z - sin(angle(-150)) * pos.y - sin(angle(-30)) * p.x
*/
