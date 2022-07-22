/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 12:12:19 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/01 22:42:48 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <math.h>
#include <limits.h>

static void	init(t_ray *ray, t_cub *cub)
{
	ray->camera = 2 * ray->x / (double)cub->win.x - 1;
	ray->dir.x = cub->dir.x + cub->plane.x * ray->camera;
	ray->dir.y = cub->dir.y + cub->plane.y * ray->camera;
	ray->map.x = (int)cub->pos.x;
	ray->map.y = (int)cub->pos.y;
	ray->del_dist.x = fabs(1 / ray->dir.x);
	ray->del_dist.y = fabs(1 / ray->dir.y);
	if (ray->dir.x < 0 && (ray->step.x = -1))
		ray->side_dist.x = (cub->pos.x - ray->map.x) * ray->del_dist.x;
	else
		ray->side_dist.x = (ray->map.x + 1 - cub->pos.x) * ray->del_dist.x;
	if (ray->dir.y < 0 && (ray->step.y = -1))
		ray->side_dist.y = (cub->pos.y - ray->map.y) * ray->del_dist.y;
	else
		ray->side_dist.y = (ray->map.y + 1 - cub->pos.y) * ray->del_dist.y;
}

void		dist_calc(t_ray *ray, t_cub *cub)
{
	if (!ray->side)
		ray->perp_dist = (ray->map.x - cub->pos.x + (1 - ray->step.x) / 2)
			/ ray->dir.x;
	else
		ray->perp_dist = (ray->map.y - cub->pos.y + (1 - ray->step.y) / 2)
			/ ray->dir.y;
	cub->z_buff[ray->x] = ray->perp_dist;
}

void		dda_algo(t_ray *ray, t_cub *cub)
{
	ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->del_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->del_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (cub->map_tab[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
		else if (cub->map_tab[ray->map.y][ray->map.x] == '2')
			found_spr(cub, ray);
	}
}

static void	set_start_end_n_tex(t_cub *cub, t_ray *ray, int line_h,
	int *n_tex)
{
	if ((ray->start = -line_h / 2 + (int)cub->win.y / 2) < 0)
		ray->start = 0;
	if ((ray->end = line_h / 2 + (int)cub->win.y / 2) >= (int)cub->win.y)
		ray->end = (int)cub->win.y - 1;
	if (!ray->side && ray->step.x == -1)
		*n_tex = 3;
	else if (!ray->side)
		*n_tex = 1;
	if (ray->side && ray->step.y == -1)
		*n_tex = 0;
	else if (ray->side)
		*n_tex = 2;
}

void		rays_try(t_cub *cub)
{
	t_ray	ray;
	int		line_h;
	int		n_tex;

	ray.x = 0;
	while (ray.x < cub->win.x)
	{
		ray.step.x = 1;
		ray.step.y = 1;
		init(&ray, cub);
		dda_algo(&ray, cub);
		dist_calc(&ray, cub);
		line_h = (int)(cub->win.y / ray.perp_dist);
		set_start_end_n_tex(cub, &ray, line_h, &n_tex);
		draw_texture_line(cub, &ray, &cub->tex[n_tex], line_h);
		++ray.x;
	}
	sprite_opening(cub);
	reset_spr(cub);
}
