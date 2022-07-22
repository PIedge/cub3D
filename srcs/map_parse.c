/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 01:22:27 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/06 15:06:41 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

void		set_dir(t_cub *game, char dir)
{
	if (dir == 'N')
	{
		game->dir.y = -1;
		game->plane.x = 0.66;
	}
	else if (dir == 'S')
	{
		game->dir.y = 1;
		game->plane.x = -0.66;
	}
	else if (dir == 'W')
	{
		game->dir.x = -1;
		game->plane.y = -0.66;
	}
	else
	{
		game->dir.x = 1;
		game->plane.y = 0.66;
	}
}

int			spr_repare(t_cub *cub, int x, int y)
{
	if (cub->spr->pos.x == -1)
	{
		cub->spr->pos.x = x;
		cub->spr->pos.y = y;
		return (1);
	}
	if (!(cub->spr->next = malloc(sizeof(t_spr))))
		return (0);
	cub->spr->next->before = cub->spr;
	cub->spr = cub->spr->next;
	cub->spr->pos.x = x;
	cub->spr->pos.y = y;
	return (1);
}

void		map_transfer_chained_to_tab(t_cub *cub)
{
	t_map	*tmp;
	int		i;

	tmp = cub->map;
	i = 0;
	while (cub->map->next && *(cub->map->line) != 0)
		cub->map = cub->map->next;
	cub->map_size = cub->map->y;
	if (!(cub->map_tab = malloc(sizeof(char*) * (cub->map->prev->y + 1))))
		exit_cub(1, cub);
	while (i < cub->map->prev->y + 1)
		cub->map_tab[i++] = 0;
	cub->map = tmp;
	while (cub->map->y < cub->map_size)
		map_it(cub);
	if (!(check_line_map(cub, cub->map->y)))
		exit_cub(7, cub);
	cycle_backward(cub);
	tmp = cub->map;
	free_map_chain(cub);
}

static void	set_map(t_cub *cub, int fd, int *ret)
{
	t_map	*tmp;

	if (!(tmp = init_map()))
		exit_cub(1, cub);
	cub->map = tmp;
	*ret = get_next_line(fd, &tmp->line);
	while (*ret > 0 && *(tmp->line) == '\0')
	{
		free(tmp->line);
		*ret = get_next_line(fd, &tmp->line);
	}
	if (!*ret)
		exit_cub(5, cub);
	if (!(cub->map_size = set_tmp(cub, tmp, fd, ret)))
		exit_cub(10, cub);
}

int			map_parse(t_cub *game, int fd)
{
	int	ret;

	set_map(game, fd, &ret);
	map_transfer_chained_to_tab(game);
	return ((ret < 0 ? 0 : 1));
}
