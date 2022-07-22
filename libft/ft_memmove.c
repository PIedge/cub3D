/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:53:36 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/07 19:10:46 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buff;
	unsigned char	*tmp;

	buff = (unsigned char*)dst;
	tmp = (unsigned char*)src;
	if (!dst && !src)
		return (0);
	if (buff < tmp)
		while (len--)
			*(buff++) = *(tmp++);
	else
	{
		while (len--)
			*(buff + len) = *(tmp + len);
	}
	return (dst);
}
