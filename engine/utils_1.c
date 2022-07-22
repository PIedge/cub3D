/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:05:31 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/03 09:44:56 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		set_tmp(t_cub *cub, t_map *tmp, int fd, int *ret)
{
	int	y;
	int	yes;

	yes = 0;
	y = 0;
	while (1)
	{
		tmp->length = gnl_strlen(tmp->line);
		tmp->y = y++;
		check_app(cub, tmp, &yes);
		if (!(tmp->next = malloc(sizeof(t_map))))
			return (0);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		tmp->line = 0;
		tmp->y = -1;
		tmp->length = 0;
		tmp->next = 0;
		if (*ret == 0)
			break ;
		*ret = get_next_line(fd, &tmp->line);
	}
	tmp->y = y;
	return (y);
}

void	set_pos(t_pos *set, double x, double y)
{
	set->x = x;
	set->y = y;
}

void	set_pos_int(t_pos_int *set, int x, int y)
{
	set->x = x;
	set->y = y;
}

int		spr_d_calc(t_cub *cub, t_calc_spr *calc, int y)
{
	calc->f = (y) * 256 - cub->win.y * 128 + calc->spr_hw.y * 128;
	calc->tex.y = ((calc->f * cub->sprite.y_max) / calc->spr_hw.y) / 256;
	return (*(cub->sprite.img_data + (cub->sprite.x_max *
		calc->tex.y + calc->tex.x)));
}

void	calc_spr(t_spr *spr, t_cub *cub, t_calc_spr *calc)
{
	set_pos(&(calc->sprite), (spr->pos.x + 0.5) - cub->pos.x,
		(spr->pos.y + 0.5) - cub->pos.y);
	calc->invdet = 1 / ((cub->plane.x * cub->dir.y) - (cub->dir.x *
		cub->plane.y));
	set_pos(&(calc->transform), calc->invdet * (cub->dir.y * calc->sprite.x -
		cub->dir.x * calc->sprite.y), calc->invdet * (-cub->plane.y
			* calc->sprite.x + cub->plane.x * calc->sprite.y));
}
