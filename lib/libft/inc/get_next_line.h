/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:10:00 by fstadelw          #+#    #+#             */
/*   Updated: 2018/11/21 17:20:43 by fstadelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 2048

typedef struct	s_content
{
	int			fd;
	char		*save;
}				t_content;

int				get_next_line(const int fd, char **line);
int				get_next_line_pure(const int fd, char **line, char **save);

#endif
