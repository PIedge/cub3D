/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:01:39 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/12 18:08:39 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s2 = ft_strlen(s2);
	len_s1 = ft_strlen(s1);
	len = len_s1 + len_s2;
	if (!(new = malloc((sizeof(char) * len) + 1)))
		return (0);
	ft_memcpy((void*)new, (void*)s1, len_s1);
	ft_memcpy((void*)(new + len_s1), (void*)s2, len_s2);
	new[len] = 0;
	return (new);
}
