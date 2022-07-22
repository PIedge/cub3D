/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_sec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:21:41 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/07 15:32:15 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

#include <stdio.h>

static void		space_check(t_cub *cub, char **map, int y, int *i)
{
	while (map[y][*i] == ' ')
		++(*i);
	if (map[y][*i] != '1')
		exit_cub(10, cub);
	while (map[y][*i] >= '0' && map[y][*i] <= '2')
	{
		if (map[y][*i] == '2')
		{
			if (!(cub->spr->next = new_spr(*i, y, cub->spr)))
				exit_cub(1, cub);
			cub->spr = cub->spr->next;
		}
		++(*i);
	}
	if ((map[y][*i] != ' ' && map[y][*i] != 0) ||
		map[y][*i - 1] != '1')
		exit_cub(10, cub);
	while (map[y][*i] == ' ')
	{
		if (!check_spa_wall(cub, map, y, *i))
			exit_cub(10, cub);
		++(*i);
	}
	if (map[y][*i] != '1' && map[y][*i])
		exit_cub(10, cub);
}

t_uint			check_line_map(t_cub *cub, int y)
{
	int		i;
	char	**map;

	map = cub->map_tab;
	y = cub->map_size - 1;
	while (y >= 0)
	{
		i = 0;
		while (map[y][i] == ' ')
			++i;
		if (y != 0 && y < cub->map_size - 1)
			while (map[y][i])
				space_check(cub, map, y, &i);
		else
		{
			other_side(cub, map, y, i);
		}
		--y;
	}
	return (1);
}

int				check_app(t_cub *game, t_map *map, int *yes)
{
	double	tmp;
	char	*line;

	tmp = -1;
	line = map->line;
	while (++tmp < map->length)
	{
		if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
		{
			if (*yes == 1)
				exit_cub(10, game);
			game->pos.x = tmp + 0.5;
			game->pos.y = (double)map->y + 0.5;
			set_dir(game, *line);
			*line = 48;
			*yes = 1;
			return (0);
		}
		++line;
	}
	return (1);
}

void			map_it(t_cub *cub)
{
	if (!(cub->map_tab[cub->map->y] =
		malloc(sizeof(char) * (cub->map->length + 1))))
		exit_cub(1, cub);
	ft_memcpy(cub->map_tab[cub->map->y], cub->map->line,
		cub->map->length + 1);
	cub->map = cub->map->next;
}
