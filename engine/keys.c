/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 13:16:20 by user42            #+#    #+#             */
/*   Updated: 2020/12/01 15:32:38 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/mlx.h"
#include <math.h>

int	key_released(int keycode, t_cub *cub)
{
	if (keycode == cub->keymap.up)
		cub->player.mov.y -= 1;
	else if (keycode == cub->keymap.down)
		cub->player.mov.y -= -1;
	else if (keycode == cub->keymap.right)
		cub->player.mov.x -= 1;
	else if (keycode == cub->keymap.left)
		cub->player.mov.x -= -1;
	else if (keycode == cub->keymap.rotate_left)
		cub->player.rot -= -1;
	else if (keycode == cub->keymap.rotate_right)
		cub->player.rot -= 1;
	return (0);
}

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(cub->mlx.mlx_ptr, cub->mlx.win_ptr);
		destroy(cub);
	}
	if (keycode == cub->keymap.up)
		cub->player.mov.y += 1;
	else if (keycode == cub->keymap.down)
		cub->player.mov.y += -1;
	else if (keycode == cub->keymap.right)
		cub->player.mov.x += 1;
	else if (keycode == cub->keymap.left)
		cub->player.mov.x += -1;
	else if (keycode == cub->keymap.rotate_left)
		cub->player.rot += -1;
	else if (keycode == cub->keymap.rotate_right)
		cub->player.rot += 1;
	return (0);
}
