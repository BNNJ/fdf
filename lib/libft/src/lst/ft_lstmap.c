/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:22:01 by fstadelw          #+#    #+#             */
/*   Updated: 2018/11/10 19:24:52 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*rtn;
	t_list	*tmp;
	t_list	*prev;

	if ((void *)f == NULL)
		return (t_list *)NULL;
	rtn = (t_list *)NULL;
	prev = (t_list *)NULL;
	if (lst != NULL)
	{
		rtn = f(lst);
		lst = lst->next;
		rtn->next = (t_list *)NULL;
	}
	tmp = rtn;
	while (lst != (t_list *)NULL)
	{
		prev = tmp;
		tmp = f(lst);
		prev->next = tmp;
		tmp->next = (t_list *)NULL;
		lst = lst->next;
	}
	return (rtn);
}
