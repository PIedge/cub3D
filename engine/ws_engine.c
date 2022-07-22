/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 16:10:58 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/01 16:05:05 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/cub.h"
#include <unistd.h>

int		wall_init(t_cub *info)
{
	info->z_buff = malloc(sizeof(double) * info->win.x);
	info->screen.tex_ptr = mlx_new_image(info->mlx.mlx_ptr, info->win.x,
		info->win.y);
	info->screen.x_max = info->win.x;
	info->screen.y_max = info->win.y;
	info->screen.img_data = (int*)mlx_get_data_addr(info->screen.tex_ptr,
		&info->screen.bpp, &info->screen.size_line, &info->screen.endian);
	return (1);
}

void	sprite_opening(t_cub *cub)
{
	t_spr	*to_draw;

	while ((to_draw = find_spr_to_draw(cub->spr)))
	{
		draw_spr(to_draw, cub);
		to_draw->dist = -1;
		to_draw->x_end = -1;
		to_draw->x_start = -1;
	}
}
