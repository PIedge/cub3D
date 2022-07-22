/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 13:15:41 by tmerrien          #+#    #+#             */
/*   Updated: 2020/11/28 07:05:24 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

/*
**	those define will be put in cub.h later
*/

void	int_to_char(unsigned char *str, int value, unsigned int nb)
{
	unsigned int	i;

	i = 0;
	while (nb-- > 0)
	{
		*(str + i++) = (unsigned char)value;
		value >>= 8;
	}
}

void	cub_bmp_pixel_data_conv(int *dst, int *src, size_t n, int size_line)
{
	unsigned int	i;
	int				tmp_size;

	i = 0;
	tmp_size = (size_line /= 4);
	while (n > 0)
	{
		while (size_line > 0)
			*(dst + n - size_line--) = *(src + i++);
		size_line = tmp_size;
		n -= size_line;
	}
}

/*
**	This is a scrap version, Need to put it good once on main pc.
**
**	BMP FORMAT
**
**	BMP and DIB Header are considered as 'header' for simplification purposes
**
**	BMP Header
**
**	2 bytes "BM" | 0
**	4 bytes unsigned int of the file size | 2
**	4 bytes to initialized to 0 for image processing app (don't touch) | 6
**	4 bytes unsigned integer pointing the start of PixelData '54' | 10
**
**	DIB Header
**
**	4 bytes DIB header size '40' | 14
**	4 bytes Image Width (X) | 18
**	4 bytes Image Height (Y) | 22
**	2 bytes Planes | 26
**	2 bytes Bits per Pixel | 28
**	4 bytes Compression | 30
**	4 bytes Image size | 34
**	4 bytes Xpixels per meter | 38
**	4 bytes Ypixels per meter | 42
**	4 bytes Total Colors | 46
**	4 bytes Important Colors | 50
**
**	header[0] = (unsigned char)'B';
**	header[1] = (unsigned char)'M';
**
**	File Data
**
**	[...]
*/

int		bmp_conv(t_image img)
{
	int				fd;
	unsigned char	header[55];
	char			*str;

	if ((fd = open("cub.bmp", O_CREAT | O_RDWR, 0666)) < 0)
		return (0);
	if (!(str = malloc(sizeof(char) * ((img.x_max * img.y_max * 4) + 55))))
		return (0);
	ft_memset(header, 0, 54);
	ft_memcpy(header, "BM", 2);
	int_to_char(header + 2, (img.x_max * img.y_max * 4) + 54, 4);
	int_to_char(header + 10, 54, 4);
	int_to_char(header + 14, 40, 4);
	int_to_char(header + 18, img.x_max, 4);
	int_to_char(header + 22, img.y_max, 4);
	int_to_char(header + 26, 1, 2);
	int_to_char(header + 28, img.bpp, 2);
	ft_memcpy(str, header, 54);
	cub_bmp_pixel_data_conv((int*)(str + 54), img.img_data,
		(img.x_max * img.y_max), img.size_line);
	str[(img.x_max * img.y_max * 4) + 54] = 0;
	write(fd, str, (img.x_max * img.y_max * 4) + 54);
	free(str);
	close(fd);
	return (1);
}
