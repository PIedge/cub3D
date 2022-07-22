/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:56:47 by tmerrien          #+#    #+#             */
/*   Updated: 2020/02/27 13:33:22 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*buff;
	unsigned char	*tmp;

	tmp = (unsigned char*)src;
	buff = (unsigned char*)dst;
	if (!tmp && !buff)
		return (0);
	while (n--)
	{
		*buff = *tmp;
		buff++;
		tmp++;
	}
	return (dst);
}
