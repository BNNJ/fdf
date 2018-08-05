/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 05:00:30 by pfragnou          #+#    #+#             */
/*   Updated: 2018/08/01 05:00:31 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	fdf_groundcontrol(t_fdf *fdf)
{
	mlx_key_hook(fdf->win_ptr, fdf_key_hook, fdf);
	mlx_hook(fdf->win_ptr, 6, (1 << 6), fdf_m_move_hook, fdf);
	mlx_loop_hook(fdf->mlx_ptr, fdf_majortom, fdf);
	mlx_loop(fdf->mlx_ptr);
}

static int	fdf_init(t_fdf *fdf, char *title)
{
	if (!(fdf->mlx_ptr = mlx_init()))
		return (0);
	if (!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, title)))
		return (0);
	if (!(fdf->img->ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT)))
		return (0);
	if (!(fdf->img->str = mlx_get_data_addr(fdf->img->ptr, &fdf->img->bpp,
		&fdf->img->size, &fdf->img->endian)))
		return (0);
	fdf->map->midx = WIDTH / 2;
	fdf->map->midy = HEIGHT / 2;
	fdf->map->gap = (WIDTH - 60) / fdf->map->x < (HEIGHT - 60) / fdf->map->y
		? (WIDTH - 60) / (fdf->map->x - 1) : (HEIGHT - 60) / (fdf->map->y - 1);
	return (1);
}

int			main(int argc, char *argv[])
{
	t_fdf	fdf;
	t_point	m;
	t_img	img;
	t_map	map;

	fdf.m = &m;
	fdf.img = &img;
	fdf.map = &map;
	if (argc != 2)
		return (0);
	fdf_parser(&fdf, argv[1]);
	if (!(fdf_init(&fdf, argv[1])))
		return (0);
	fdf_groundcontrol(&fdf);
	return (0);
}

/*
	int	y = 0;
	int	x;
	while (y < fdf.map->y)
	{
		x = 0;
		while (x < fdf.map->x)
		{
			printf("%d, ", fdf.map->grid[y][x]);
			++x;
		}
		printf("\n");
		++y;
	}
*/