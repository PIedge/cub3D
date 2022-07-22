/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:24:16 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/03 10:18:10 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

#include <stdio.h>

void	cycle_backward(t_cub *cub)
{
	while (cub->spr->before)
		cub->spr = cub->spr->before;
}

void	cycle_forward(t_cub *cub)
{
	while (cub->spr && cub->spr->pos.x != -1)
		cub->spr = cub->spr->next;
}

/*
**	We go forward first then backward
*/

t_spr	*find(t_spr *spr, int x, int y)
{
	while (spr->pos.x > 0 && spr->pos.x != x && spr->pos.y != y)
		spr = spr->next;
	if (spr->pos.x != -1)
		return (spr);
	while (spr->pos.x > 0 && spr->pos.x != x && spr->pos.y != y)
		spr = spr->next;
	return (spr);
}
