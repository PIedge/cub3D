/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:53:16 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/03 09:38:08 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx_int.h"
#include <X11/Xlib.h>
#include <unistd.h>

#include <stdio.h>

void		free_map_surplus(t_map *tmp)
{
	free(tmp->line);
	if (*(tmp->prev->line) == 0)
	{
		free(tmp->prev->line);
		tmp = tmp->prev;
		free(tmp->next);
		tmp = tmp->prev;
		free(tmp->next);
		tmp->next = 0;
	}
}

void		free_map_tab(t_cub *cub)
{
	while (cub->map_tab != 0 && cub->map_size > 0)
		free(cub->map_tab[--(cub->map_size)]);
	free(cub->map_tab);
	cub->map_tab = 0;
}

void		mlx_terminate(void *mlxptr)
{
	struct s_xvar	*xvar;

	xvar = mlxptr;
	if (xvar->private_cmap)
		XFreeColormap(xvar->display, (Colormap)xvar->private_cmap);
	XCloseDisplay(xvar->display);
	free(xvar);
}
