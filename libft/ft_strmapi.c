/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:24:30 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/13 12:49:29 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		i;

	i = -1;
	if (s == 0 || f == 0)
		return (0);
	if (!(ret = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (s[++i])
		ret[i] = (*f)(i, s[i]);
	ret[i] = 0;
	return (ret);
}
