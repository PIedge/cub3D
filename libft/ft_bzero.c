/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:13:27 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/05 23:28:43 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	while (n >= sizeof(unsigned long long))
	{
		*((unsigned long long*)s) = 0;
		s += sizeof(unsigned long long);
		n -= sizeof(unsigned long long);
	}
	while (n--)
	{
		*((unsigned char*)s) = 0;
		s += sizeof(unsigned char);
	}
}
