/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:24:37 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/12 16:19:14 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ts1;
	unsigned char	*ts2;

	ts1 = (unsigned char*)s1;
	ts2 = (unsigned char*)s2;
	while (n)
	{
		if (*ts1 != *ts2)
			return (*ts1 - *ts2);
		ts1++;
		ts2++;
		n--;
	}
	return (0);
}
