/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfragnou <pfragnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:56:20 by pfragnou          #+#    #+#             */
/*   Updated: 2018/11/29 03:11:47 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

/*
** Gets the color
*/

static int		get_color(char *str)
{
	static const char	*base1 = "0123456789abcdef";
	static const char	*base2 = "0123456789ABCDEF";
	int					v;

	if ((str = ft_strchr(str, ',')) == NULL)
		v = DEFAULT_COLOR;
	else
	{
		v = 0;
		str += 3;
		while ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f')
			|| (*str >= 'A' && *str <= 'F'))
		{
			v = v * 16 + (ft_stridx(*str >= 'a' ? base1 : base2, *str));
			++str;
		}
	}
	return (v);
}

static int		get_height(char *str, int *h)
{
	long	v;
	char	sign;
	int		count;

	v = 0;
	count = 0;
	sign = *str == '+' || *str == '-' ? -(*str++ - 44) : 1;
	while (*str == '0' && *str)
		++str;
	while (*str >= '0' && *str <= '9')
	{
		v = v * 10 + (*str - '0');
		++count;
		++str;
	}
	v *= sign;
	if (v < INT_MIN || v > INT_MAX || count > 11)
		return (0);
	else
	{
		*h = v;
		return (1);
	}
}

static t_point	*parse_line(t_fdf *fdf, char **arr)
{
	int		i;
	t_point	*new;

	i = 0;
	if (!(new = ft_memalloc(sizeof(t_point) * fdf->map.size.x)))
		return (NULL);
	while (arr[i])
	{
		if (!(get_height(arr[i], &new[i].h)))
			return (NULL);
		new[i].color = get_color(arr[i]);
		++i;
	}
	return (new);
}

int				add_line(t_fdf *fdf, char **arr)
{
	int		i;
	t_point	**tmp;

	if (!(tmp = ft_memalloc(sizeof(t_point*) * (fdf->map.size.y))))
		return (0);
	i = fdf->map.size.y - 1;
	if (!(tmp[i] = parse_line(fdf, arr)))
		return (0);
	if (fdf->map.map)
	{
		while (--i >= 0)
			tmp[i] = fdf->map.map[i];
		free(fdf->map.map);
	}
	fdf->map.map = tmp;
	return (1);
}
