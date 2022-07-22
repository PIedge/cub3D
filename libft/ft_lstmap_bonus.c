/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:04:19 by tmerrien          #+#    #+#             */
/*   Updated: 2019/11/18 17:45:38 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include <stdlib.h>

static void		lstclear(t_list *lst, void (*del)(void*))
{
	t_list *tmp;

	if (!lst)
		return ;
	while (lst->next)
	{
		tmp = lst;
		lst = lst->next;
		(*del)(tmp->content);
		free(tmp);
	}
	(*del)(lst->content);
	free(lst);
	lst = 0;
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*tmp;

	if (!lst)
		return (0);
	if (!(ret = malloc(sizeof(t_list *) * ft_lstsize(lst))))
		return (0);
	tmp = ret;
	tmp->content = (*f)(lst->content);
	while (lst->next)
	{
		if (!(tmp->next = ft_lstnew((*f)(lst->next->content))))
		{
			lstclear(ret, del);
			return (0);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew((*f)(lst->content))))
	{
		lstclear(ret, del);
		return (0);
	}
	return (ret);
}
