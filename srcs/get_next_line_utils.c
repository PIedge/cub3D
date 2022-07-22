/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:36:52 by tmerrien          #+#    #+#             */
/*   Updated: 2020/11/25 18:40:50 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/get_next_line.h"

size_t	gnl_strlen(char const *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	ft_charcpy(char *s, int n, char c)
{
	while (n--)
		s[n] = c;
}

void	gnl_memcpy(char *to, char const *from, int max)
{
	while (max-- > 0 && *from != 0)
		*(to++) = *(from++);
	*to = 0;
}

char	*gnl_strnjoin(char const *s1, char const *s2, int n)
{
	size_t	len;
	char	*new;
	size_t	len_s1;

	len_s1 = gnl_strlen(s1);
	if (!n || n == -1)
		n = gnl_strlen(s2);
	len = len_s1 + n;
	if (!(new = malloc((sizeof(char) * (len + 1)))))
		return (0);
	if (s1)
		gnl_memcpy((void*)new, (void*)s1, len_s1);
	if (s2)
		gnl_memcpy((void*)(new + len_s1), (void*)s2, n);
	if (s1)
		free((char*)s1);
	new[len] = 0;
	return (new);
}
