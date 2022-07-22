/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:29:26 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/19 12:13:13 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		find_exp(int n, int *len)
{
	int	exp;

	*len = 1;
	exp = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		exp *= 10;
		(*len)++;
	}
	return (exp);
}

static void		worst_case(char *str, int *n, int *exp)
{
	*str = '2';
	*n %= 1000000000;
	*exp /= 10;
}

char			*ft_itoa(int n)
{
	char	*ret;
	char	*tmp;
	int		exp;
	int		len;

	exp = find_exp(n, &len);
	tmp = malloc((sizeof(char) * (len + 1) + (n < 0 ? sizeof(char) : 0)));
	ret = tmp;
	if (!tmp)
		return (0);
	if (n < 0)
	{
		*(tmp++) = '-';
		if (n == -2147483648)
			worst_case(tmp++, &n, &exp);
		n *= -1;
	}
	while (exp)
	{
		*(tmp++) = (n / exp) + 48;
		n %= exp;
		exp /= 10;
	}
	*tmp = 0;
	return (ret);
}
