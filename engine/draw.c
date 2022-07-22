/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 22:42:22 by tmerrien          #+#    #+#             */
/*   Updated: 2020/11/28 08:55:13 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/cub.h"
#include <math.h>
#include <limits.h>

t_draw		calcul_draw(t_cub *cub, t_ray *ray, t_image *tex, int line_h)
{
	t_draw	i;

	i.step = (double)tex->y_max / (double)line_h;
	i.wall_x = (!ray->side ? cub->pos.y + ray->perp_dist * ray->dir.y :
		cub->pos.x + ray->perp_dist * ray->dir.x);
	i.wall_x -= floor(i.wall_x);
	tex->x_dis = (int)(i.wall_x * (double)tex->x_max);
	if ((!ray->side && ray->dir.x > 0) ||
		(ray->side && ray->dir.y < 0))
		tex->x_dis = tex->x_max - tex->x_dis - 1;
	i.tex_pos = (ray->start - cub->win.y / 2 + line_h / 2) * i.step;
	return (i);
}

static void	draw_sprite_line_finale(t_cub *cub, t_calc_spr *calc, int str)
{
	int	y;
	int	color;

	y = calc->draw_start.y - 1;
	while (++y < calc->draw_end.y)
	{
		calc->f = (y) * 256 - cub->win.y * 128 + calc->spr_hw.y * 128;
		calc->tex.y = ((calc->f * cub->sprite.y_max)
			/ calc->spr_hw.y) / 256;
		color = *(cub->sprite.img_data +
			(cub->sprite.x_max * calc->tex.y + calc->tex.x));
		if (color != 0)
			*(cub->screen.img_data + (cub->screen.x_max * y + str)) =
				color;
	}
}

void		draw_sprite_line(t_spr *spr, t_cub *cub, t_calc_spr *calc)
{
	int	str;

	str = calc->draw_start.x - 1;
	while (++str <= spr->x_end && str < calc->draw_end.x)
	{
		calc->tex.x = (int)(256 * (str - (-calc->spr_hw.x / 2 + calc->x)) *
			cub->sprite.x_max / calc->spr_hw.x) / 256;
		if (calc->transform.y > 0 && calc->transform.y < cub->z_buff[str])
			draw_sprite_line_finale(cub, calc, str);
	}
}

void		draw_texture_line(t_cub *cub, t_ray *ray, t_image *tex, int line_h)
{
	t_draw	calc;
	int		i;

	i = 0;
	calc = calcul_draw(cub, ray, tex, line_h);
	while (i <= ray->start)
		draw_pixel(&cub->screen, i++, cub->ceil, ray->x);
	while (i <= ray->end)
	{
		ray->y = (int)calc.tex_pos & (tex->y_max - 1);
		calc.tex_pos += calc.step;
		draw_pixel(&cub->screen, i++,
			tex->img_data[tex->y_max * ray->y + tex->x_dis], ray->x);
	}
	while (i <= cub->win.y)
		draw_pixel(&cub->screen, i++, cub->floor, ray->x);
}

void		draw_pixel(t_image *s, int height, int color, int start)
{
	*((int*)s->img_data + start + (s->x_max * height)) = color;
}
