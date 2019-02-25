/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:22:01 by fstadelw          #+#    #+#             */
/*   Updated: 2018/11/10 18:28:27 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*prev;

	if (alst == (t_list **)NULL || *alst == (t_list *)NULL
		|| (void *)del == NULL)
		return ;
	tmp = *alst;
	while (tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		del(prev->content, prev->content_size);
		free(prev);
	}
	*alst = (t_list *)NULL;
}
