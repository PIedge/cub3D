/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:36:32 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/12 20:14:50 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		isset(char c, const char *set)
{
	while (*set)
		if (c == *(set++))
			return (1);
	return (0);
}

static int		find_start(const char *str, const char *set)
{
	int	ret;

	ret = 0;
	while (str[ret] && isset(str[ret], set))
		++ret;
	return (ret);
}

static int		find_end(const char *str, const char *set)
{
	int ret;

	ret = ft_strlen(str) - 1;
	while (str[ret] && isset(str[ret], set))
		--ret;
	return (ret + 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		start;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	start = find_start(s1, set);
	if (!s1[start])
		return (ft_strdup(""));
	end = find_end(s1, set);
	if (!(new = malloc(sizeof(char) * (end - start + 1))))
		return (0);
	ft_memcpy(new, &s1[start], end - start);
	new[end - start] = 0;
	return (new);
}
