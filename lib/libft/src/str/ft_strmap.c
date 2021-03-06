/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:22:01 by fstadelw          #+#    #+#             */
/*   Updated: 2018/11/09 21:38:43 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*rtn;

	if (s == (char *)NULL || (void *)f == NULL)
		return (NULL);
	rtn = ft_strnew(ft_strlen(s));
	if (rtn == (char *)NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		rtn[i] = f(s[i]);
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
