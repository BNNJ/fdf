/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:28:08 by fstadelw          #+#    #+#             */
/*   Updated: 2018/12/01 00:32:29 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec2	map_to_2d(t_fdf *fdf, int x, int y, int z)
{
	return (fdf->flag.proj
		? parallel_projection(fdf, x, y, z)
		: isometric_projection(fdf, x, y, z));
}

static void		draw_between(t_fdf *fdf, t_vec2 v1, t_vec2 v2)
{
	t_pixel		p1;
	t_pixel		p2;
	t_vec2		tmp;

	tmp = map_to_2d(fdf, v1.x, v1.y, fdf->map.map[v1.x][v1.y].h);
	p1.x = tmp.x;
	p1.y = tmp.y;
	if (0x000000 != fdf->map.map[v1.x][v1.y].color)
		p1.color = fdf->map.map[v1.x][v1.y].color;
	else
		p1.color = fdf->disp.get_col(fdf->map.map[v1.x][v1.y].h);
	tmp = map_to_2d(fdf, v2.x, v2.y, fdf->map.map[v2.x][v2.y].h);
	p2.x = tmp.x;
	p2.y = tmp.y;
	if (0x000000 != fdf->map.map[v2.x][v2.y].color)
		p2.color = fdf->map.map[v2.x][v2.y].color;
	else
		p2.color = fdf->disp.get_col(fdf->map.map[v2.x][v2.y].h);
	if ((p1.x > 0 && p1.x < fdf->mlx.win_size.x
		&& p1.y > 0 && p1.y < fdf->mlx.win_size.y)
		|| (p2.x > 0 && p2.x < fdf->mlx.win_size.x
		&& p2.y > 0 && p2.y < fdf->mlx.win_size.y))
		draw_line(&fdf->mlx, &p1, &p2);
}

void			draw_fdf(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.size.y)
	{
		j = 0;
		while (j < fdf->map.size.x)
		{
			if (i != 0)
				draw_between(fdf, (t_vec2){i, j}, (t_vec2){i - 1, j});
			if (j != 0)
				draw_between(fdf, (t_vec2){i, j}, (t_vec2){i, j - 1});
			j++;
		}
		i++;
	}
}
