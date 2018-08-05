/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groundcontrol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:27:26 by pfragnou          #+#    #+#             */
/*   Updated: 2018/08/03 00:27:28 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		fdf_key_hook(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	else if (key == KEY_A)
		fdf->aa = !fdf->aa;
	else if (key == KEY_PLUS)
		fdf->map->gap += 10;
	else if (key == KEY_MINUS && fdf->map->gap > 10)
		fdf->map->gap -= 10;
	return (1);
}

int		fdf_m_move_hook(int x, int y, t_fdf *fdf)
{
	fdf->m->x = x;
	fdf->m->y = y;
	return (1);
}

int		fdf_majortom(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	fdf_clear_image((int*)fdf->img->str, 0x00FFFFFF);
	while (y < fdf->map->y)
	{
		x = 0;
		while (x < fdf->map->x)
		{
			fdf_do_magic(fdf, x, y);
			++x;
			printf("%d, %d, %d, %d\n", y, fdf->map->y, x, fdf->map->x);
		}
		++y;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->ptr, 0, 0);
	return (1);
}



/*
	if (fdf->aa)
		fdf_xiaolin_wu(fdf, WIDTH / 2, HEIGHT / 2, fdf->m->x, fdf->m->y);
	else
		fdf_bresenham(fdf, WIDTH / 2, HEIGHT / 2, fdf->m->x, fdf->m->y);
			
			printf("%d, %d, %d, %d\n", fdf->map->grid[y][x].x,
					fdf->map->grid[y][x].y, fdf->map->grid[y][x + 1].x,
					fdf->map->grid[y][x + 1].y);
			printf("%d, %d, %d, %d\n\n", fdf->map->grid[y][x].x,
					fdf->map->grid[y][x].y, fdf->map->grid[y + 1][x].x,
					fdf->map->grid[y + 1][x].y);
*/
