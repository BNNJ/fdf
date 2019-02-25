/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:11:06 by fstadelw          #+#    #+#             */
/*   Updated: 2018/11/15 18:11:07 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_s(char *dst, const char *src)
{
	if (dst == NULL || src == NULL)
		return (NULL);
	return (ft_strcpy(dst, src));
}
