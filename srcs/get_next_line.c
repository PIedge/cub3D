/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:19:54 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/01 23:17:29 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/get_next_line.h"

int		search_end_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (i == (BUFFER_SIZE + 1) || !s[i])
		return (-1);
	return (i);
}

int		read_the_thing(char *rest, int fd, int *ret_read)
{
	*(rest + BUFFER_SIZE + 1) = 1;
	if ((*ret_read = read(fd, rest, BUFFER_SIZE)) < 0)
		return (0);
	return (1);
}

int		line_nav_n_search(char *rest, char **line, int *ret_read, int fd)
{
	int		e_line;
	char	buff[BUFFER_SIZE];

	e_line = -1;
	*line = 0;
	ft_charcpy(buff, BUFFER_SIZE, 0);
	while (e_line == -1 && *ret_read > 0)
	{
		if (!(*(rest + BUFFER_SIZE + 1)))
			if (!read_the_thing(rest, fd, ret_read))
				return (0);
		e_line = search_end_line(rest);
		*line = gnl_strnjoin(*line, rest, e_line);
		if (e_line >= 0)
		{
			ft_charcpy(buff, BUFFER_SIZE, 0);
			gnl_memcpy(buff, rest + e_line + 1, BUFFER_SIZE - e_line);
			gnl_memcpy(rest, buff, BUFFER_SIZE);
		}
		if (e_line == -1)
			ft_charcpy(rest, BUFFER_SIZE + 2, 0);
	}
	return (1);
}

int		create_new(t_fd **last, t_fd **current, int fd, int mode)
{
	if (!mode)
	{
		if (!(*last = malloc(sizeof(t_fd))))
			return (0);
		*current = *last;
		(*current)->next = 0;
	}
	if (mode == 1)
	{
		if (!(*current = malloc(sizeof(t_fd))))
			return (0);
		(*last)->next = *current;
	}
	(*current)->fd = fd;
	if (!((*current)->rest = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		begin[1][BUFFER_SIZE + 2];
	int				ret_read;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	ret_read = 1;
	if (!line_nav_n_search(begin[0], line, &ret_read, fd))
		return (-1);
	if (ret_read > 0 || (ret_read == 0 && begin[0][0] != 0))
		return (1);
	return (0);
}
