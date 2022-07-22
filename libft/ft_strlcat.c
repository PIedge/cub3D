/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 23:59:18 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/13 16:00:53 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strnlen(const char *str, size_t lim)
{
	const char	*rep;

	rep = str;
	while (lim-- && *rep)
		rep++;
	return (rep - str);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		ini;
	size_t		t_src;
	size_t		i;

	ini = ft_strnlen((char*)dst, dstsize);
	t_src = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (ini + t_src);
	while ((i + ini) < (dstsize - 1) && src[i] != 0)
	{
		dst[i + ini] = src[i];
		i++;
	}
	if ((i + ini) <= (dstsize - 1))
		dst[i + ini] = 0;
	return (ini + t_src);
}
