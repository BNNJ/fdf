/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:41:48 by fstadelw          #+#    #+#             */
/*   Updated: 2018/11/30 05:12:54 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "fdf.h"

int			main(const int ac, const char *av[])
{
	t_fdf	fdf;
	int		rtn;

	rtn = 1;
	if (ac >= 2)
	{
		ft_bzero(&fdf, sizeof(t_fdf));
		if (parser(&fdf, av[1]))
		{
			init_fdf(&fdf,
				ac >= 3 ? ft_atoi(av[2]) : 1800,
				ac >= 4 ? ft_atoi(av[3]) : 1200);
			if (display_mlx_win(&fdf) == 0)
				rtn = 0;
		}
		else
		{
			free_map(&fdf.map);
			ft_printf("Error\n");
		}
	}
	else
		ft_printf("usage: %s map.fdf\n", av[0]);
	return (rtn);
}
