/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:41:29 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/02 11:51:45 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iswhitespace(unsigned char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
