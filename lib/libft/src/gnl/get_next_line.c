/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:08:02 by fstadelw          #+#    #+#             */
/*   Updated: 2018/11/15 19:44:39 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static int	split_buff(char **save, char **line, ssize_t read_rtn)
{
	size_t		i;

	i = 0;
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	*line = malloc(i + 1);
	if (*line == NULL)
		return (-1);
	i = 0;
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
	{
		(*line)[i] = (*save)[i];
		i++;
	}
	(*line)[i] = '\0';
	if ((*save)[i] == '\n')
		i++;
	ft_memmove((*save), &(*save)[i], ft_strlen(&(*save)[i]) + 1);
	if ((*save)[0] == '\0')
		ft_strdel(save);
	else if (read_rtn == 0 && (*save) == NULL)
		return (0);
	return (1);
}

static int	read_next_buff(char **line, char **save,
						const int fd, ssize_t *read_rtn)
{
	char		buff[BUFF_SIZE + 1];
	size_t		i;
	size_t		j;
	char		*rtn;

	if ((*read_rtn = read(fd, buff, BUFF_SIZE)) < 0)
		return (-1);
	if (*save == NULL && (*read_rtn) == 0 && (*line = NULL) == NULL)
		return (0);
	if ((*read_rtn) != 0)
	{
		if ((rtn = malloc(ft_strlen_s(*save) + *read_rtn + 2)) == NULL)
			return (-1);
		i = ft_strlen_s(*save);
		ft_strcpy_s(rtn, *save);
		ft_strdel(save);
		j = 0;
		while (j < (size_t)(*read_rtn))
			rtn[i++] = buff[j++];
		rtn[i] = '\0';
		(*save) = rtn;
	}
	return (1);
}

int			get_next_line_pure(const int fd, char **line, char **save)
{
	ssize_t		read_rtn;
	int			rtn;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	read_rtn = BUFF_SIZE;
	while ((*save == NULL || ft_strchr(*save, '\n') == NULL)
			&& read_rtn == BUFF_SIZE)
	{
		rtn = read_next_buff(line, save, fd, &read_rtn);
		if (rtn != 1)
			return (rtn);
	}
	return (split_buff(save, line, read_rtn));
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*save_list = NULL;
	t_list			*tmp;
	t_content		content;
	int				rtn;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	tmp = save_list;
	while (tmp != NULL && ((t_content *)(tmp->content))->fd != fd)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		content.save = NULL;
		content.fd = fd;
		tmp = ft_lstnew(&content, sizeof(t_content));
		if (tmp == NULL)
			return (-1);
		ft_lstadd(&save_list, tmp);
	}
	rtn = get_next_line_pure(fd, line, &((t_content *)(tmp->content))->save);
	if (rtn != 1)
		ft_lstdelelem(&save_list, tmp);
	return (rtn);
}
