/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 08:05:12 by javrodri          #+#    #+#             */
/*   Updated: 2020/02/20 19:41:41 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <time.h>


# define WINX 1080
# define WINY 720
# define USAGE "usage: wolf3d \"map\"\n"
# define BUFF_SIZE 100

typedef struct	s_tex
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_tex;
/*
typedef struct	s_sprites
{
  double		x;
  double		y;
  double		spriteX;
  double		spriteY;
  double		transformX;
  double		transformY;
  t_tex			tex;
  int			sprite_height;
  int			sprite_width;
  int			draw_startX;
  int			draw_startY;
  int			draw_endX;	
  int			draw_endY;
  int			sprite_screenX;
  int			fact;
  int			draw_y_org;
  int			stripe;
  int			texX;
}				t_sprites;
*/

typedef struct	s_wolf3d
{
	t_tex		tex[9];
	char		*map_name;
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			**map;
    int         win_width;
    int         win_height;
    int         map_width;
    int         map_height;
	int			nb_lines;
	int			lenline;
	int			bpp;
	int			endian;
	int			sl;
	int			x_map;
	int			y_map;
	int			x_step;
	int			y_step;
	int			hit;
	int			side;
	int			lineheight;
	int			start;
	int			end;
	int			color;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			help;
	int			x_text;
	int			y_text;
	int			id;
	int			texture;
	int			x_floortext;
	int			y_floortext;
	int			x;
	int			y;
	int			initial_pos;
	int			right_mov;
	int			left_mov;
	double		movespeed;
	double		x_pos;
	double		y_pos;
	double		x_dir;
	double		y_dir;
	double		x_plane;
	double		y_plane;
	double		x_cam;
	double		x_raypos;
	double		y_raypos;
	double		x_raydir;
	double		y_raydir;
	double		x_sidedist;
	double		y_sidedist;
	double		x_deltadist;
	double		y_deltadist;
	double		walldist;
	double		x_olddir;
	double		x_oldplane;
	double		ms;
	double		rs;
	double		x_wall;
	double		x_floor;
	double		y_floor;
	double		x_curfloortext;
	double		y_curfloortext;
	double		curdist;
	double		weight;
}				t_params;

void			draw_sky(t_params *p);
void			draw_floor(t_params *p);
void			draw_wall(int x, int start, int end, t_params *p);
void			put_pxl_to_img(t_params *p, int x, int y, int color);

int				key_press2(int keycode, t_params *p);
int				key_press(int keycode, t_params *p);
int				key_release(int keycode, t_params *p);
void			move_side(t_params *p);
int				move(t_params *p);

void			help_text(t_params *p);

int 			load_textures(t_params *p);
int 			load_textures2(t_params *p, int a, int b);

int				ft_close(t_params *p);
void			mlx_win_init(t_params *p);
void			wolf3d_init(t_params *p);

int				check_map(char *buff, t_params *p);
int				map_parser(t_params *p, char **av);
int				parser2(t_params *p, char **av);
void			map_config_reader(t_params *p, int fd);

void			ray_casting(t_params *p);
void			ray_casting_init(t_params *p, int x);
void			floor_and_ceiling(t_params *p, int x);
void			dda(t_params *p);
void			dda_init(t_params *p);

void	        *ft_memcpy(void *dst, const void *src, size_t n);
char	        *ft_substr(char *s, unsigned int start, ssize_t len);
int		        close_success(t_params *p);
int		        close_failure(char *message);
void	        ft_putchar(char c);
int	            ft_strcmp(char *s1, char *s2);
void	        ft_strdel(char **as);
size_t	        ft_linelen(const char *s);
int		        ft_countlines(char *str);
char	        *ft_strnew(size_t size);
void	        *ft_memset(void *b, int c, size_t len);
int			    get_next_line(const int fd, char **line);
int	        	ft_strlen(char *s);
char	        *ft_strjoin(char  *s1, char  *s2);
char	        *ft_strchr(char *str, int c);
char	        *ft_strdup(char *s1);
void	        ft_putstr(const char *str);
int			    ft_atoi(const char *str);
char		    *ft_itoa(int n);
void        	orientation_n(t_params *p, int i, int j);
void       		orientation_s(t_params *p, int i, int j);
void       		orientation_e(t_params *p, int i, int j);
void        	orientation_w(t_params *p, int i, int j);
void			map_position(t_params *p);
void			map_reader(t_params *p, char *map);
void			ft_bzero(void *s, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			map_reader_check(t_params *p, char *line);
void			move_right_left(t_params *p);
void			ray_casting_bmp(t_params *p);
int		        save_bmp(t_params *cub);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

void 			draw_sprites(t_params *p);
void			wall_orientation(t_params *p);
int				ft_spaceskip(char *line, int *i);

#endif
