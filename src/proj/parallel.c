/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 09:08:05 by fstadelw          #+#    #+#             */
/*   Updated: 2018/12/01 00:14:57 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

t_vec2	parallel_projection(t_fdf *fdf, int x, int y, int z)
{
	t_vec2	rtn;
	double	zoom;

	x -= fdf->map.size.x / 4;
	y -= fdf->map.size.y / 2;
	zoom = fdf->flag.zoom < 0 ? 1 / (double)-(fdf->flag.zoom) : fdf->flag.zoom;
	x *= zoom;
	y *= zoom;
	z *= zoom * fdf->flag.height_mod / 15;
	rtn.x = y + cos(deg_to_rad(fdf->flag.angle_mod)) * x;
	rtn.y = -z + sin(deg_to_rad(fdf->flag.angle_mod)) * x;
	rtn.x += fdf->flag.pos.x;
	rtn.y += fdf->flag.pos.y;
	return (rtn);
}
