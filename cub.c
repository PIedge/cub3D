/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 23:13:06 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/03 10:01:00 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mlx.h"
#include "includes/cub.h"
#include <math.h>

static void		strafe_ini(t_cub *i, t_pos *dir, t_pos *pos)
{
	dir->x = i->dir.x;
	dir->y = i->dir.y;
	pos->x = i->pos.x;
	pos->y = i->pos.y;
}

void			strafe(t_player *p, t_cub *i)
{
	char	**buff;
	t_pos	dir;
	t_pos	pos;

	strafe_ini(i, &dir, &pos);
	if ((buff = i->map_tab) && p->mov.y != 0)
	{
		if (buff[(int)pos.y][(int)(pos.x + p->mov.y *
			(dir.x * ((double)M_SPEED * 8)))] != '1')
			i->pos.x += p->mov.y * (dir.x * (double)M_SPEED);
		if (buff[(int)(pos.y + p->mov.y * (dir.y *
			((double)M_SPEED * 8)))][(int)i->pos.x] != '1')
			i->pos.y += p->mov.y * (dir.y * (double)M_SPEED);
	}
	if (p->mov.x != 0)
	{
		if (buff[(int)i->pos.y][(int)(i->pos.x + -p->mov.x *
			(dir.y * ((double)M_SPEED * 8)))] != '1')
			i->pos.x += -p->mov.x * (dir.y * (double)M_SPEED);
		if (buff[(int)(pos.y + p->mov.x * (dir.x *
			((double)M_SPEED * 8)))][(int)i->pos.x] != '1')
			i->pos.y += p->mov.x * (dir.x * (double)M_SPEED);
	}
}

void			rotate(t_player *player, t_cub *info)
{
	t_pos	buff;
	double	val;

	val = 0;
	if (player->rot == 1)
		val = R_SPEED;
	else if (player->rot == -1)
		val = -R_SPEED;
	if (val != 0)
	{
		buff.x = info->dir.x;
		info->dir.x = buff.x * cos(val) - info->dir.y * sin(val);
		info->dir.y = buff.x * sin(val) + info->dir.y * cos(val);
		buff.x = info->plane.x;
		info->plane.x = buff.x * cos(val) - info->plane.y * sin(val);
		info->plane.y = buff.x * sin(val) + info->plane.y * cos(val);
	}
}

int				loop_cub(t_cub *info)
{
	strafe(&info->player, info);
	rotate(&info->player, info);
	rays_try(info);
	mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win_ptr,
		info->screen.tex_ptr, 0, 0);
	mlx_do_sync(info->mlx.mlx_ptr);
	return (0);
}
