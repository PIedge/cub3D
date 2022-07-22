/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:52:52 by tmerrien          #+#    #+#             */
/*   Updated: 2020/07/17 23:48:12 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dst;

	len = ft_strlen(s1);
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memcpy((void*)dst, (const void *)s1, len);
	dst[len] = 0;
	return (dst);
}
