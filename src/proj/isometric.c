/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 09:25:21 by fstadelw          #+#    #+#             */
/*   Updated: 2018/12/01 00:13:48 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

t_vec2	isometric_projection(t_fdf *fdf, int x, int y, int z)
{
	t_vec2	rtn;
	int		angle;
	double	zoom;

	if (fdf->flag.angle_mod > 45)
		angle = 45;
	else if (fdf->flag.angle_mod < -45)
		angle = -45;
	else
		angle = fdf->flag.angle_mod;
	zoom = fdf->flag.zoom < 0 ? 1 / (double)-(fdf->flag.zoom) : fdf->flag.zoom;
	x -= fdf->map.size.x / 2;
	y -= fdf->map.size.y / 2;
	x *= zoom;
	y *= zoom;
	z *= zoom * fdf->flag.height_mod / 10;
	rtn.x = cos(deg_to_rad(angle)) * (y - fdf->map.size.y / 2)
		- cos(deg_to_rad(angle)) * (x - fdf->map.size.x / 2);
	rtn.y = -z * cos(deg_to_rad(angle * 2))
		+ sin(deg_to_rad(angle)) * (x - fdf->map.size.x / 2)
		+ sin(deg_to_rad(angle)) * (y - fdf->map.size.y / 2);
	rtn.x += fdf->flag.pos.x;
	rtn.y += fdf->flag.pos.y;
	return (rtn);
}
