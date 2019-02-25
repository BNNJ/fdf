/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 09:12:12 by fstadelw          #+#    #+#             */
/*   Updated: 2018/11/30 19:07:12 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**                   _______
**             _____/       \_____
**             |  _     ___   _   ||
**             | | \     |   | \  ||
**             | |  |    |   |  | ||
**             | |_/     |   |_/  ||
**             | | \     |   |    ||
**             | |  \    |   |    ||
**             | |   \. _|_. | .  ||
**             |                  ||
**             |    seg fault     ||
**             |                  ||
**     *       | *   **    * **   |**      **
**      \))ejm97/.,(//,,..,,\||(,,.,\\,.((//
**
** RIP : Here lies a segfault that could kick you out of your session
*/

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int		*img;

	img = (int*)mlx->buff;
	if (x >= 0 && x < mlx->win_size.x && y >= 0 && y < mlx->win_size.y)
		img[x + mlx->win_size.x * y] = color;
}
