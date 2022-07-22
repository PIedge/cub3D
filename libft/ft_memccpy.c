/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:56:05 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/10 18:18:03 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	dst_tmp = (unsigned char*)dst;
	src_tmp = (unsigned char*)src;
	while (n && (*src_tmp != (unsigned char)c))
	{
		*dst_tmp = *src_tmp;
		dst_tmp++;
		src_tmp++;
		n--;
	}
	if (n)
	{
		*dst_tmp = *src_tmp;
		dst_tmp++;
		return ((void*)dst_tmp);
	}
	return (NULL);
}
