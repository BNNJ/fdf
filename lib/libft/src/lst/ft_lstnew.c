/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:22:01 by fstadelw          #+#    #+#             */
/*   Updated: 2018/11/10 19:25:48 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if (rtn == (t_list *)NULL)
		return ((t_list *)NULL);
	if (content != NULL)
	{
		rtn->content = malloc(content_size);
		if (rtn->content == NULL)
		{
			free(rtn);
			return ((t_list *)NULL);
		}
		ft_memcpy(rtn->content, content, content_size);
		rtn->content_size = content_size;
	}
	else
	{
		rtn->content = NULL;
		rtn->content_size = 0;
	}
	rtn->next = NULL;
	return (rtn);
}
