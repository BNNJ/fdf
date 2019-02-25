/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:22:01 by fstadelw          #+#    #+#             */
/*   Updated: 2018/11/09 16:03:40 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*rtn;

	i = 0;
	while (s1[i] != '\0')
		i++;
	rtn = (char *)malloc(sizeof(char) * (i + 1));
	if (rtn == (char *)NULL)
	{
		errno = ENOMEM;
		return ((char *)NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		rtn[i] = s1[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
