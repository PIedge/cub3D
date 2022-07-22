/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 23:31:24 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/03 12:52:45 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"
#include "includes/mlx.h"
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

#include <stdio.h>

static void	init_rest(t_cub *cub)
{
	int	i;

	i = 0;
	cub->map_tab = 0;
	cub->map = 0;
	cub->sprite.path = 0;
	cub->sprite.tex_ptr = 0;
	cub->screen.tex_ptr = 0;
	cub->z_buff = 0;
	set_pos(&cub->plane, 0, 0);
	set_pos(&cub->dir, 0, 0);
	while (i < 4)
	{
		cub->tex[i].tex_ptr = 0;
		cub->tex[i++].path = 0;
	}
}

void		initialize(t_cub *info)
{
	set_pos(&info->pos, 0, 0);
	info->keymap.down = S;
	info->keymap.left = A;
	info->keymap.right = D;
	info->keymap.up = W;
	info->keymap.rotate_left = LEFT_KEY;
	info->keymap.rotate_right = RIGHT_KEY;
	info->player.rot = 0;
	set_pos(&info->player.mov, 0, 0);
	info->win.x = 0;
	info->win.y = 0;
	info->h_sprite = 0;
	init_rest(info);
	if (!(info->spr = new_spr(-1, -1, 0)))
		exit_cub(1, info);
}

int			destroy(t_cub *cub)
{
	free_img(cub);
	free_map_tab(cub);
	free(cub->z_buff);
	free_spr(cub);
	free_map_chain(cub);
	mlx_terminate(cub->mlx.mlx_ptr);
	exit(0);
}

int			main(int ac, char **av)
{
	t_cub	info;

	info.snd_arg = av[1];
	if (!(info.mlx.mlx_ptr = mlx_init()))
		exit_cub(0, &info);
	initialize(&info);
	if (ac == 1 || !valid_name(av[1]) || ac > 3)
		exit_cub(3, &info);
	pare_singe(&info);
	wall_init(&info);
	if (ac == 3 && !ft_strncmp(SAVE, av[2], sizeof(SAVE) / sizeof(char)))
	{
		rays_try(&info);
		bmp_conv(info.screen);
		exit(0);
	}
	info.mlx.win_ptr = mlx_new_window(info.mlx.mlx_ptr, info.win.x,
		info.win.y, "Cub3D");
	mlx_hook(info.mlx.win_ptr, 2, 1L << 0, &key_press, &info);
	mlx_hook(info.mlx.win_ptr, 3, 1L << 1, &key_released, &info);
	mlx_loop_hook(info.mlx.mlx_ptr, &loop_cub, &info);
	mlx_loop(info.mlx.mlx_ptr);
	destroy(&info);
	return (1);
}
