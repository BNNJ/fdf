/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:59:11 by pfragnou          #+#    #+#             */
/*   Updated: 2018/11/28 22:59:13 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <errno.h>

static void		free_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&arr[i]);
		++i;
	}
	free(arr);
}

static int		pars_error(char *line, char *save, char **arr)
{
	ft_strdel(&line);
	ft_strdel(&save);
	if (arr)
		free_arr(arr);
	return (0);
}

int				parser(t_fdf *fdf, const char *file_name)
{
	int		fd;
	char	*line;
	char	*save;
	char	**arr;

	if ((fd = open(file_name, O_RDWR)) < 0)
		if (errno == EISDIR || (fd = open(file_name, O_RDONLY)) < 0)
			return (0);
	save = NULL;
	while ((get_next_line_pure(fd, &line, &save)) > 0)
	{
		if (!(check_line(fdf, line)))
			return (pars_error(line, save, NULL));
		if (!(arr = ft_strsplit(line, ' ')))
			return (pars_error(line, save, NULL));
		++fdf->map.size.y;
		if (!(add_line(fdf, arr)))
			return (pars_error(line, save, arr));
		free_arr(arr);
		arr = NULL;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	return (1);
}
