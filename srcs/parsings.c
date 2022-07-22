/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:06:01 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/03 13:02:39 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <fcntl.h>
#include <unistd.h>

int				valid_name(char *s)
{
	int		len;
	int		ext_len;
	char	*ext;

	len = gnl_strlen(s) - 1;
	ext_len = 3;
	ext = EXTENS;
	while (*(ext + ext_len--) == *(s + len))
		--len;
	if (ext_len >= -1)
		return (0);
	return (1);
}

static void		check_elem(t_cub *cub, char *line, t_uint *total)
{
	if (*line == 'R')
		*total += element_r(cub, line + 1);
	else if (*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
		*total += element_t_s(cub, line + 1, &cub->tex[NORTH]);
	else if (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
		*total += element_t_s(cub, line + 1, &cub->tex[EAST]);
	else if (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
		*total += element_t_s(cub, line + 1, &cub->tex[WEST]);
	else if (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
		*total += element_t_s(cub, line + 1, &cub->tex[SOUTH]);
	else if (*line == 'F')
		*total += element_f_c(&cub->floor, line + 1, cub);
	else if (*line == 'C')
		*total += element_f_c(&cub->ceil, line + 1, cub);
	else if (*line == 'S' && *(line + 1) == ' ')
		*total += element_t_s(cub, line + 1, &cub->sprite);
	free(line);
}

static void		before_map(t_cub *cub, int fd)
{
	char			*line;
	t_uint			total;

	total = 0;
	while (total != (t_uint)(1 + (2 * 5) + (3 * 2)) &&
		get_next_line(fd, &line))
		check_elem(cub, line, &total);
	if (total != (t_uint)(1 + (2 * 5) + (3 * 2)))
		exit_cub(5, cub);
}

int				pare_singe(t_cub *info)
{
	int	fd;

	fd = open(info->snd_arg, O_RDONLY);
	if (fd < 0)
		exit_cub(2, info);
	before_map(info, fd);
	map_parse(info, fd);
	cycle_backward(info);
	close(fd);
	return (1);
}
