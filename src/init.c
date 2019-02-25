/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 03:57:23 by fstadelw          #+#    #+#             */
/*   Updated: 2018/12/01 02:42:42 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	init_fdf(t_fdf *fdf, int x, int y)
{
	fdf->mlx.win_size.x = x;
	fdf->mlx.win_size.y = y;
	fdf->flag.height_mod = 4;
	fdf->flag.zoom = 11;
	fdf->flag.angle_mod = 30;
	fdf->flag.pos.x = fdf->mlx.win_size.x / 2;
	fdf->flag.pos.y = fdf->mlx.win_size.y / 2;
	get_next_colorcheme(&fdf->disp);
}
