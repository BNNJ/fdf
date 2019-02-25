/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:40:31 by pfragnou          #+#    #+#             */
/*   Updated: 2018/11/28 18:40:32 by pfragnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

/*
** Verifies the validity of a point :
** Its z value, and the hexadecimal color value if one is specified.
*/

static char		*check_point(char *str)
{
	if (*str == '-' || *str == '+')
		++str;
	while (*str != ' ' && *str != ',' && *str)
	{
		if (*str < '0' || *str > '9')
			return (NULL);
		++str;
	}
	if (*str == ',')
	{
		if (*(str + 1) != '0' || *(str + 2) != 'x')
			return (NULL);
		str += 3;
		while (*str != ' ' && *str)
		{
			if ((*str < '0' || *str > '9') && (*str < 'a' || *str > 'f')
				&& (*str < 'A' || *str > 'F'))
				return (NULL);
			++str;
		}
	}
	return (str);
}

/*
** Verifies the validity of a line
*/

int				check_line(t_fdf *fdf, char *line)
{
	int		x;

	x = 0;
	while (*line)
	{
		while (*line == ' ')
			++line;
		if (!(line = check_point(line)))
			return (0);
		while (*line == ' ')
			++line;
		++x;
	}
	if (fdf->map.size.x != 0 && x != fdf->map.size.x)
		return (0);
	fdf->map.size.x = x;
	return (1);
}
