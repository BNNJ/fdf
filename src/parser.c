/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 19:09:32 by pfragnou          #+#    #+#             */
/*   Updated: 2018/08/02 19:09:36 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int	fdf_count_xy(int fd, t_point *p)
{
	char	prev;
	char	*line;
	int		i;

	p->y = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		p->x = 0;
		prev = ' ';
		i = 0;
		while (line[i])
		{
			if (line[i] >= '0' && line[i] <= '9' && (prev == ' '))
				++p->x;
			prev = line[i];
			++i;
		}
		free(line);
		if (p->y > 0 && p->x != p->z)
			return (0);
		p->z = p->x;
		++p->y;
	}
	return (1);
}

static int	fdf_make_map(t_fdf *fdf, int fd, int x, int y)
{
	char	*line;
	int		lx;
	int		ly;
	int		k;

	if (!(fdf->map->grid = (int**)malloc(sizeof(int*) * y)))
		return (0);
	ly = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(fdf->map->grid[ly] = (int*)malloc(sizeof(int) * x)))
			return (0);
		lx = 0;
		k = 0;
		while (line[k])
		{
			fdf->map->grid[ly][lx] = ft_atoi(line + k);
			while (line[k] >= '0' && line[k] <= '9')
				++k;
			while (line [k] == ' ')
				++k;
			++lx;
		}
		++ly;
	}
	return (1);
}

int			fdf_parser(t_fdf *fdf, char *filename)
{
	int		fd;
	t_point	p;

	if ((fd = open(filename, O_RDONLY)) < 2)
		return (0);
	if (!(fdf_count_xy(fd, &p)))
		return (0);
	close(fd);
	fdf->map->y = p.y;
	fdf->map->x = p.x;
	if ((fd = open(filename, O_RDONLY)) < 2)
		return (0);
	if (!(fdf_make_map(fdf, fd, p.x, p.y)))
		return (0);
	close(fd);
	return (1);
}
