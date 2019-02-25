/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 05:21:31 by fstadelw          #+#    #+#             */
/*   Updated: 2018/12/01 02:32:57 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	draw_helper(t_fdf *fdf, int col)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	y = 20;
	mlx = fdf->mlx.mlx;
	win = fdf->mlx.window;
	x = fdf->mlx.win_size.x - 270;
	mlx_string_put(mlx, win, x - 20, y, col, "Usage");
	mlx_string_put(mlx, win, x, y + 30, col, "Disable usage   space");
	mlx_string_put(mlx, win, x, y + 55, col, "Move            < ^ v >");
	mlx_string_put(mlx, win, x, y + 80, col, "Move            q w a d");
	mlx_string_put(mlx, win, x, y + 105, col, "Zoom            + -");
	mlx_string_put(mlx, win, x, y + 130, col, "Scale up        page up");
	mlx_string_put(mlx, win, x, y + 155, col, "Scale down      page down");
	mlx_string_put(mlx, win, x, y + 180, col, "Angle           q e");
	mlx_string_put(mlx, win, x, y + 205, col, "Projection      p");
	mlx_string_put(mlx, win, x, y + 230, col, "Colortheme      c");
}

void	clear_image(t_mlx *mlx, int color)
{
	int x;
	int y;

	x = 0;
	while (x < mlx->win_size.x)
	{
		y = 0;
		while (y < mlx->win_size.y)
		{
			put_pixel(mlx, x, y, color);
			++y;
		}
		++x;
	}
}

void	draw_usage_bg(t_fdf *fdf, int color)
{
	int i;
	int j;

	i = fdf->mlx.win_size.x - 300;
	while (i < fdf->mlx.win_size.x - 10)
	{
		j = 15;
		while (j < 285)
		{
			put_pixel(&fdf->mlx, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_win(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx.mlx, fdf->mlx.window);
	clear_image(&fdf->mlx, fdf->disp.bg_color);
	draw_fdf(fdf);
	if (!fdf->flag.disp_helper)
		draw_usage_bg(fdf, fdf->disp.usage_color);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.window, fdf->mlx.image,
		0, 0);
	if (!fdf->flag.disp_helper)
		draw_helper(fdf, fdf->disp.text_color);
}
