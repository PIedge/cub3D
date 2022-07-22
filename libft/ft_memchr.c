/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:05 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/12 16:05:43 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buff;

	buff = (unsigned char*)s;
	while (n && (*buff != (unsigned char)c))
	{
		buff++;
		n--;
	}
	if (n)
		return ((void*)buff);
	return (NULL);
}
