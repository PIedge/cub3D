/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:53:54 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/12 17:40:03 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	ret;
	int	s;

	ret = 0;
	s = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 43)
		str++;
	else if (*str == 45)
	{
		s = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		ret *= 10;
		ret += (*str - 48);
		str++;
	}
	ret *= s;
	return (ret);
}
