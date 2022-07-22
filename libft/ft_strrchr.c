/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 23:07:04 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/10 19:36:42 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)s;
	while (*tmp)
		tmp++;
	while ((*tmp != (unsigned char)c) && (tmp != (unsigned char*)s))
		tmp--;
	if (*tmp == c)
		return ((char*)tmp);
	return (0);
}
