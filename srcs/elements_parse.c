/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:27:43 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/07 14:52:36 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"

#include <stdio.h>

t_uint	element_f_c(int *col, char *str, t_cub *cub)
{
	int		i;
	int		integer;

	i = -1;
	*col = 0;
	while (*str == 32)
		str++;
	while (++i < 3)
	{
		integer = 0;
		while (*str >= 48 && *str <= 57)
		{
			integer *= 10;
			integer += (*str - 48);
			++str;
		}
		if (integer > 255 || *str == '-')
			exit_cub(5, cub);
		*col = *col << 8;
		*col = *col | integer;
		if (*str != 0 && *str != ',')
			exit_cub(5, cub);
		++str;
	}
	return (P_F_C);
}

t_uint	element_t_s(t_cub *cub, char *str, t_image *tex)
{
	while (*(++str) == 32)
		;
	if (!(tex->path = ft_strdup(str)))
		exit_cub(1, cub);
	if (!(tex->tex_ptr = mlx_xpm_file_to_image(cub->mlx.mlx_ptr,
		tex->path, &(tex->x_max), &(tex->y_max))))
		exit_cub(5, cub);
	tex->img_data = (int*)mlx_get_data_addr(tex->tex_ptr,
		&tex->bpp, &tex->size_line, &tex->endian);
	return (P_T);
}

void	check_screen_size(t_cub *cub)
{
	int	sizex;
	int	sizey;

	mlx_get_screen_size(cub->mlx.mlx_ptr, &sizex, &sizey);
	if (sizex < cub->win.x)
		cub->win.x = sizex;
	if (sizey < cub->win.y)
		cub->win.y = sizey;
}

t_uint	element_r(t_cub *cub, char *str)
{
	while (*str == 32)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		cub->win.x *= 10;
		cub->win.x += (*str - 48);
		str++;
	}
	while (*str == 32)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		cub->win.y *= 10;
		cub->win.y += (*str - 48);
		str++;
	}
	check_screen_size(cub);
	if (cub->win.x <= 0 || cub->win.y <= 0)
		exit_cub(5, cub);
	return (P_R);
}
