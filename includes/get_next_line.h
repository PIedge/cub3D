/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:08:11 by tmerrien          #+#    #+#             */
/*   Updated: 2020/11/22 05:55:26 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# define BUFFER_SIZE 32

typedef struct		s_fdlist
{
	int				fd;
	char			*rest;
	struct s_fdlist	*next;
}					t_fd;

int					get_next_line(int fd, char **line);
int					line_nav_n_search(char *rest, char **line, int *ret_read,
int fd);
int					search_end_line(char *s);
int					create_new(t_fd **last, t_fd **current, int fd, int mode);

size_t				gnl_strlen(char const *s);
void				gnl_memcpy(char *to, char const *from, int max);
char				*gnl_strnjoin(char const *s1, char const *s2, int n);
void				ft_charcpy(char *s, int n, char c);
#endif
