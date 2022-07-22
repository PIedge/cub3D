/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 00:11:26 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/13 18:33:19 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	int		i;

	i = 0;
	len_needle = ft_strlen(needle);
	if (!len_needle)
		return ((char*)haystack);
	while (haystack[i] && len >= len_needle)
	{
		if (haystack[i] == needle[0])
			if (!(ft_strncmp(&haystack[i], needle, len_needle)))
				return ((char*)&haystack[i]);
		i++;
		len--;
	}
	return (NULL);
}
