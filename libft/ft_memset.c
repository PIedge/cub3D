/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:11:18 by tmerrien          #+#    #+#             */
/*   Updated: 2020/08/06 17:45:25 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*buff;
	unsigned long long	line;
	int					i;

	i = sizeof(unsigned long long);
	buff = (unsigned char*)b;
	line = 0;
	while (i--)
	{
		line <<= 8;
		line |= (unsigned char)c;
	}
	while (len >= sizeof(unsigned long long))
	{
		*((unsigned long long*)buff) = line;
		buff += sizeof(unsigned long long);
		len -= sizeof(unsigned long long);
	}
	while (len--)
	{
		*buff = (unsigned char)c;
		++buff;
	}
	return (b);
}
