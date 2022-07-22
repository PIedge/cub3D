/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 00:43:05 by tmerrien          #+#    #+#             */
/*   Updated: 2020/12/07 15:30:50 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define EXTENS ".cub"
# define MSG_E_MALLOC "Malloc didn't work accordingly.\n"
# define MSG_E_EXTENS "Wrong file name or wrong path.\n"
# define MSG_E_ARGS "No arg or too much args were passed, pass only one.\n"
# define MSG_E_N_MAP "Where the fuck is your map bro ?!"
# define MSG_E_ELE "Missing or bogus element/s in description file.\n"
# define MSG_E_MAP "Your map is wrong.\n"
# define BUFFER_SIZE 32
# define P_R 1
# define P_T 2
# define P_F_C 3
# define Z 122
# define Q 113
# define D 100
# define S 115
# define W 119
# define A 97
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define ESC_KEY 65307
# define M_SPEED 0.01
# define R_SPEED 0.01
# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3
# define SAVE "--save"
# define M_PI 3.14159265358979323846
# include <stdlib.h>
# include "../libft/libft.h"

typedef unsigned int	t_uint;

typedef struct		s_keymap
{
	int				up;
	int				left;
	int				right;
	int				down;
	int				rotate_right;
	int				rotate_left;
}					t_keymap;

typedef	struct		s_image
{
	int				bpp;
	int				size_line;
	int				endian;
	int				x_max;
	int				y_max;
	void			*tex_ptr;
	int				*img_data;
	char			*path;
	int				x_dis;
}					t_image;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_player
{
	int				rot;
	t_pos			mov;
}					t_player;

typedef struct		s_win
{
	double			x;
	double			y;
}					t_win;

typedef	struct		s_pos_int
{
	int				x;
	int				y;
}					t_pos_int;

typedef	struct		s_map
{
	char			*line;
	long			length;
	struct s_map	*next;
	struct s_map	*prev;
	int				y;
}					t_map;

typedef struct		s_spr
{
	t_pos_int		pos;
	double			dist;
	int				x_start;
	int				x_end;
	struct s_spr	*next;
	struct s_spr	*before;
}					t_spr;

typedef struct		s_spr_draw
{
	t_pos			sprite;
	t_pos			transform;
	double			invdet;
	int				hei_wid;
	t_pos_int		draw_start;
	t_pos_int		draw_end;
	int				spr_scr_x;
}					t_spr_draw;

typedef	struct		s_calc_spr
{
	t_pos			sprite;
	t_pos			transform;
	t_pos_int		spr_hw;
	t_pos_int		draw_start;
	t_pos_int		draw_end;
	double			invdet;
	int				x;
	t_pos_int		tex;
	int				f;
}					t_calc_spr;

typedef struct		s_cub
{
	int				map_size;
	char			*snd_arg;
	t_map			*map;
	char			**map_tab;
	t_image			tex[4];
	t_image			sprite;
	double			*z_buff;
	t_spr			*spr;
	int				h_sprite;
	int				floor;
	int				ceil;
	t_image			screen;
	t_win			win;
	t_player		player;
	t_pos			pos;
	t_pos			map_pos;
	t_pos			dir;
	t_pos			plane;
	double			*buff;
	t_mlx			mlx;
	t_keymap		keymap;
}					t_cub;

typedef	struct		s_draw
{
	double			wall_x;
	double			step;
	double			tex_pos;
}					t_draw;

typedef	struct		s_ray
{
	t_pos			side_dist;
	t_pos			del_dist;
	t_pos			dir;
	t_pos_int		map;
	t_pos_int		step;
	double			camera;
	int				start_pixel;
	int				height;
	t_image			tex;
	int				x;
	int				y;
	int				hit;
	double			perp_dist;
	int				start;
	int				end;
	int				side;
}					t_ray;

typedef struct		s_fdlist
{
	int				fd;
	char			*rest;
	struct s_fdlist	*next;
}					t_fd;

int					get_next_line(int fd, char **line);
int					line_nav_n_search(char *rest, char **line, int *ret_read,
							int fd);
int					search_end_line(char *s);
int					create_new(t_fd **last, t_fd **current, int fd, int mode);
size_t				gnl_strlen(char const *s);
void				gnl_memcpy(char *to, char const *from, int max);
char				*gnl_strnjoin(char const *s1, char const *s2, int n);
void				ft_charcpy(char *s, int n, char c);
double				cub_sqr(double thing);
int					valid_name(char *s);
int					map_parse(t_cub *game, int fd);
t_map				*init_map();
int					pare_singe(t_cub *info);
t_uint				element_r(t_cub *cub, char *str);
t_uint				element_t_s(t_cub *cub, char *str, t_image *tex);
t_uint				element_f_c(int *col, char *str, t_cub *cub);
t_uint				check_line_map(t_cub *cub, int y);
t_uint				check_walls(char **map, int y);
int					set_tmp(t_cub *cub, t_map *tmp, int fd,
	int *ret);
void				cub_memcpy(char *to, char const *from, int max);
int					loop_cub(t_cub *info);
int					key_press(int keycode, t_cub *cub);
int					key_released(int keycode, t_cub *cub);
void				update_game(t_cub *game);
void				dda_algo(t_ray *ray, t_cub *cub);
void				dist_calc(t_ray *ray, t_cub *cub);
int					wall_init(t_cub *info);
void				draw_pixel(t_image *s, int height, int color, int start);
int					draw_line(t_image *s, t_pos *pos, int length,
							t_image *tex);
int					check_map_hit(int x, int y, const t_map *map);
void				rays_try(t_cub *game);
t_draw				calcul_draw(t_cub *cub, t_ray *ray, t_image *tex,
						int line_h);
void				draw_sprite_line(t_spr *spr, t_cub *cub, t_calc_spr *calc);
void				draw_pixel(t_image *s, int height, int color, int start);
void				draw_untextured_line(t_image *s, int color, t_ray ray);
void				draw_texture_line(t_cub *cub, t_ray *ray,
t_image *tex, int line_h);
void				player_and_sprite_init(t_player *player);
int					found_spr(t_cub *cub, t_ray *ray);
void				reset_spr(t_cub *cub);
t_spr				*find_spr_to_draw(t_spr *spr);
void				draw_spr(t_spr *spr, t_cub *cub);
t_spr				*new_spr(int x, int y, t_spr *before);
void				cycle_backward(t_cub *cub);
void				cycle_forward(t_cub *cub);
t_spr				*find(t_spr *spr, int x, int y);
void				set_pos(t_pos *set, double x, double y);
void				set_pos_int(t_pos_int *set, int x, int y);
int					spr_d_calc(t_cub *cub, t_calc_spr *cacl, int y);
void				calc_spr(t_spr *spr, t_cub *cub, t_calc_spr *calc);
void				sprite_opening(t_cub *cub);
int					bmp_conv(t_image img);
int					destroy(t_cub *cub);
void				free_img(t_cub *cub);
void				free_spr(t_cub *cub);
void				exit_cub(t_uint exit_code, t_cub *i);
void				free_all(t_cub *i);
void				free_map_chain(t_cub *i);
void				free_map_tab(t_cub *cub);
void				mlx_terminate(void *mlxptr);
void				map_it(t_cub *cub);
void				set_dir(t_cub *game, char dir);
void				free_map_surplus(t_map *tmp);
int					check_app(t_cub *game, t_map *map, int *yes);
int					check_spa_wall(t_cub *cub, char **map, int y, int i);
void				other_side(t_cub *cub, char **map, int y, int i);
#endif
