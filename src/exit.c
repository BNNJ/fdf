/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <pfragnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:56:50 by pfragnou          #+#    #+#             */
/*   Updated: 2018/11/29 03:05:18 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include <mlx.h>

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size.y)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

int		fdf_exit(t_fdf *fdf)
{
	free_map(&fdf->map);
	if (fdf->mlx.mlx && fdf->mlx.window)
		mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.window);
	if (fdf->mlx.mlx && fdf->mlx.image)
		mlx_destroy_image(fdf->mlx.mlx, fdf->mlx.image);
	exit(fdf->flag.exit_value);
}
