/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:20:51 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/07 15:31:15 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

#include <stdio.h>

int		check_spa_wall(t_cub *cub, char **map, int y, int i)
{
	if (y != 0)
		if (map[y - 1][i] != '1' && map[y - 1][i] != ' ')
			return (0);
	if (y + 1 != cub->map_size)
		if (map[y + 1][i] != '1' && map[y + 1][i] != ' ')
			return (0);
	return (1);
}

void	other_side(t_cub *cub, char **map, int y, int i)
{
	while (map[y][i] && (map[y][i] == '1' || map[y][i] == ' '))
	{
		if (map[y][i] && map[y][i] == ' ' &&
			!check_spa_wall(cub, map, y, i))
			exit_cub(10, cub);
		++i;
	}
	if (map[y][i])
		exit_cub(10, cub);
}

void	cub_memcpy(char *to, char const *from, int max)
{
	char *tmp;

	tmp = to;
	while ((max > 0 && *(from) != 0) && *from == ' ')
	{
		*(to++) = *(from++);
		--max;
	}
	while (max-- > 0 && *(from) != 0)
	{
		if (*from != ' ')
			*(to++) = *(from);
		++from;
	}
	*to = 0;
}

double	cub_sqr(double thing)
{
	return (thing * thing);
}

t_map	*init_map(void)
{
	t_map *ret;

	if (!(ret = malloc(sizeof(t_map))))
		return (0);
	ret->next = 0;
	ret->prev = 0;
	return (ret);
}
