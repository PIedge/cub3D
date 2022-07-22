/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 02:20:36 by user42            #+#    #+#             */
/*   Updated: 2020/12/03 12:58:42 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"
#include <unistd.h>

#include <stdio.h>

void	free_map_chain(t_cub *i)
{
	t_map	*tmp;

	if (!i->map)
		return ;
	while (i->map->prev)
		i->map = i->map->prev;
	while (i->map->next)
	{
		free(i->map->line);
		tmp = i->map;
		i->map = i->map->next;
		free(tmp);
	}
	free(i->map->line);
	free(i->map);
	i->map = 0;
}

void	free_img(t_cub *cub)
{
	int	i;

	i = -1;
	if (cub->screen.tex_ptr != 0)
		mlx_destroy_image(cub->mlx.mlx_ptr, cub->screen.tex_ptr);
	if (cub->sprite.path != 0)
	{
		free(cub->sprite.path);
		if (cub->sprite.tex_ptr)
			mlx_destroy_image(cub->mlx.mlx_ptr, cub->sprite.tex_ptr);
	}
	while (++i < 4)
	{
		if (cub->tex[i].path != 0)
			free(cub->tex[i].path);
		if (cub->tex[i].tex_ptr)
			mlx_destroy_image(cub->mlx.mlx_ptr, cub->tex[i].tex_ptr);
	}
}

void	test_cycle(t_spr *spr)
{
	while (spr->next)
		spr = spr->next;
}

void	free_spr(t_cub *cub)
{
	while (cub->spr->next)
	{
		cub->spr = cub->spr->next;
		free(cub->spr->before);
		cub->spr->before = 0;
	}
	free(cub->spr);
	cub->spr = 0;
}

void	exit_cub(t_uint exit_code, t_cub *i)
{
	if (exit_code == 1)
		write(1, MSG_E_MALLOC, sizeof(MSG_E_MALLOC) / sizeof(char));
	else if (exit_code == 2)
		write(1, MSG_E_EXTENS, sizeof(MSG_E_EXTENS) / sizeof(char));
	else if (exit_code == 3)
		write(1, MSG_E_ARGS, sizeof(MSG_E_ARGS) / sizeof(char));
	else if (exit_code == 4)
		write(1, MSG_E_N_MAP, sizeof(MSG_E_N_MAP) / sizeof(char));
	else if (exit_code == 5)
		write(1, MSG_E_ELE, sizeof(MSG_E_ELE) / sizeof(char));
	else if (exit_code == 10)
		write(1, MSG_E_MAP, sizeof(MSG_E_MAP) / sizeof(char));
	write(1, "Error\n", 6);
	cycle_backward(i);
	destroy(i);
	exit(0);
}
