/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_thickener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 22:26:18 by pfragnou          #+#    #+#             */
/*   Updated: 2018/08/02 22:26:19 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_add_pixel(int *img, int x, int y, int color)
{
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
		img[x + WIDTH * y] = color;
}

void	fdf_clear_image(int *img, int color)
{
	int x;
	int y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fdf_add_pixel(img, x, y, color);
			++y;
		}
		++x;
	}
}
