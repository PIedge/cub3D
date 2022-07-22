/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:35:54 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/18 15:54:49 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;

	if (!lst)
		return ;
	while ((*lst)->next)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		(*del)(tmp->content);
		free(tmp);
	}
	(*del)((*lst)->content);
	free(*lst);
	*lst = 0;
}
