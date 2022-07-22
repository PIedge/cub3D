/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 12:04:47 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/01 15:57:05 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

#include <stdio.h>
#include <math.h>

t_spr		*new_spr(int x, int y, t_spr *before)
{
	t_spr	*tmp;

	if (!(tmp = malloc(sizeof(t_spr))))
		return (0);
	if (before)
		before->next = tmp;
	tmp->pos.x = x;
	tmp->pos.y = y;
	tmp->dist = -1;
	tmp->before = before;
	tmp->next = NULL;
	tmp->x_end = -1;
	tmp->x_start = -1;
	return (tmp);
}

void		reset_spr(t_cub *cub)
{
	t_spr	*tmp;

	cycle_backward(cub);
	tmp = cub->spr;
	while (tmp)
	{
		tmp->dist = -1;
		tmp->x_start = -1;
		tmp->x_end = -1;
		tmp = tmp->next;
	}
}

int			found_spr(t_cub *cub, t_ray *ray)
{
	t_spr	*tmp;

	tmp = cub->spr;
	while ((tmp = tmp->next))
	{
		if (tmp->pos.y == ray->map.y && tmp->pos.x == ray->map.x)
			break ;
	}
	if (!tmp)
		return (0);
	if (tmp->pos.x != ray->map.x && tmp->pos.y != ray->map.y)
		return (0);
	if (tmp->dist == -1)
		tmp->dist = cub_sqr(cub->pos.x - tmp->pos.x)
			+ cub_sqr(cub->pos.y - tmp->pos.y);
	if (tmp->x_start == -1)
		tmp->x_start = ray->x;
	tmp->x_end = ray->x;
	return (1);
}

t_spr		*find_spr_to_draw(t_spr *spr)
{
	t_spr	*tmp;
	t_spr	*highest;

	if ((spr->next) == NULL)
		return (0);
	tmp = spr;
	highest = tmp;
	while (tmp)
	{
		if (highest->dist < tmp->dist)
			highest = tmp;
		tmp = tmp->next;
	}
	if (tmp && highest->dist < tmp->dist)
		highest = tmp;
	if (highest->dist == -1)
		return (0);
	return (highest);
}

void		draw_spr(t_spr *spr, t_cub *cub)
{
	t_calc_spr	calc;

	set_pos(&calc.sprite, (spr->pos.x + 0.5) - cub->pos.x,
		(spr->pos.y + 0.5) - cub->pos.y);
	calc.invdet = 1 / ((cub->plane.x * cub->dir.y) - (cub->dir.x *
		cub->plane.y));
	set_pos(&calc.transform, calc.invdet * (cub->dir.y * calc.sprite.x -
		cub->dir.x * calc.sprite.y),
		calc.invdet * (-cub->plane.y * calc.sprite.x + cub->plane.x *
			calc.sprite.y));
	calc.x = (int)((cub->win.x / 2.) * (1. + calc.transform.x /
		calc.transform.y));
	set_pos_int(&calc.spr_hw, abs((int)(cub->win.y / (calc.transform.y))),
		abs((int)(cub->win.y / (calc.transform.y))));
	calc.draw_start.x = (-calc.spr_hw.x / 2 + calc.x < 0 ? 0 :
		-calc.spr_hw.x / 2 + calc.x);
	calc.draw_end.x = (calc.spr_hw.x / 2 + calc.x > cub->win.x ?
		cub->win.x : calc.spr_hw.x / 2 + calc.x);
	calc.draw_start.y = (-calc.spr_hw.y / 2 + cub->win.y / 2 < 0 ?
		0 : -calc.spr_hw.y / 2 + cub->win.y / 2);
	calc.draw_end.y = (calc.spr_hw.y / 2 + cub->win.y / 2 > cub->win.y ?
		cub->win.y : calc.spr_hw.y / 2 + cub->win.y / 2);
	draw_sprite_line(spr, cub, &calc);
}
