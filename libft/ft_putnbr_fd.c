/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:34:42 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/13 13:15:39 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int		find_exp(int n)
{
	int	exp;

	exp = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		exp *= 10;
	}
	return (exp);
}

void			ft_putnbr_fd(int n, int fd)
{
	int	exp;

	exp = find_exp(n);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			n %= 1000000000;
			exp /= 10;
		}
		n *= -1;
	}
	while (exp)
	{
		ft_putchar_fd((n / exp) + 48, fd);
		n %= exp;
		exp /= 10;
	}
}
