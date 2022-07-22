/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:14:33 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/18 12:26:26 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	if (!(ret = malloc(sizeof(t_list*) * 1)))
		return (0);
	ret->content = content;
	return (ret);
}
