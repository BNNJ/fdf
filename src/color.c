/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 01:47:12 by fstadelw          #+#    #+#             */
/*   Updated: 2018/12/01 02:19:51 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static const t_disp	g_colorcheme[] =
{
	{
		.bg_color = 0x000000,
		.text_color = 0xFFFFFF,
		.usage_color = 0x00222222,
		.get_col = minecraft_fade
	},
	{
		.bg_color = 0x181D26,
		.text_color = 0xEEEEEE,
		.usage_color = 0x001D222B,
		.get_col = knife_fade
	},
	{
		.bg_color = 0x0,
		.text_color = 0xFFFFFF,
		.usage_color = 0x303030,
		.get_col = white_on_black
	}
};

void	get_next_colorcheme(t_disp *disp)
{
	unsigned int	nb;

	nb = disp->colortheme + 1;
	if (nb >= sizeof(g_colorcheme) / sizeof(t_disp))
		nb = 0;
	disp->colortheme = nb;
	disp->bg_color = g_colorcheme[nb].bg_color;
	disp->text_color = g_colorcheme[nb].text_color;
	disp->usage_color = g_colorcheme[nb].usage_color;
	disp->get_col = g_colorcheme[nb].get_col;
}
