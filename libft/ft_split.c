/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:27:08 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/18 12:58:04 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		how_many_split(char const *str, char c)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[++i])
		if (str[i] == c && str[i - 1] != c)
			res++;
	if (str[i - 1] != c)
		res++;
	return (res);
}

static char		*advance_to_next(const char *s, char c)
{
	while (*s == c)
		s++;
	return ((char*)s);
}

static int		free_if_wrong(char **ret, char *s, char *last_pos, int i)
{
	if (!(ret[i] = ft_substr(last_pos, 0, s - last_pos)))
	{
		while (i >= 0)
			free(ret[i--]);
		free(ret);
		ret = 0;
		return (0);
	}
	return (1);
}

static char		**to_all(char const *s, char c)
{
	int		nb_of_split;
	char	**ret;
	char	*last_pos;
	int		i;

	nb_of_split = how_many_split(s, c);
	i = 0;
	s++;
	last_pos = advance_to_next(s - 1, c);
	if (!(ret = malloc(sizeof(char*) * (nb_of_split + 1))))
		return (0);
	while (*s)
	{
		if (*s == c && *(s - 1) != c)
		{
			if (!free_if_wrong(ret, (char*)s, last_pos, i++))
				return (0);
			last_pos = advance_to_next(s, c);
		}
		s++;
	}
	if (*(s - 1) != c && !free_if_wrong(ret, (char*)s, last_pos, i++))
		return (0);
	ret[i] = 0;
	return (ret);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (0);
	if (*s == 0)
	{
		if (!(ret = malloc(sizeof(char*) * 1)))
			return (0);
		ret[0] = 0;
		return (ret);
	}
	ret = to_all(s, c);
	return (ret);
}
