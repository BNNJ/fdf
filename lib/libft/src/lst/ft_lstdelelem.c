/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:32:54 by fstadelw          #+#    #+#             */
/*   Updated: 2018/11/15 19:42:36 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelelem(t_list **alst, t_list *elem)
{
	t_list	*tmp;
	t_list	*prev;

	if (alst == (t_list **)NULL || *alst == (t_list *)NULL
		|| elem == (t_list *)NULL)
		return ;
	tmp = *alst;
	prev = NULL;
	while (tmp != NULL && tmp == elem)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == elem)
	{
		if (prev == NULL)
			*alst = elem->next;
		else
			prev->next = elem->next;
		free(elem->content);
		free(elem);
	}
}
