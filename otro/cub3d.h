/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:31:20 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/13 20:08:57 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

/*
** Define sizes
*/

# define SCREENWIDTH 4000
# define NUMSPRITES 10

/*
** Define colors
*/

# define RGB_WHITE 0xFFFFFF
# define RGB_BLACK 0x000000
# define RGB_RED 0xFF0000
# define RGB_GREEN 0x00FF00
# define RGB_BLUE 0x0000FF
# define RGB_YELLOW 0xFFFF00
# define RGB_CHOCOLATE 0xD2691E
# define RGB_GRAY 0x808080
# define RGB_DARKGRAY 0x2F4F4F
# define RGB_INDIGO 0x4B0082
# define RGB_TOMATO 0xFF6347
# define RGB_DARKBLUE 0x00008B

/*
** Define floor and ceiling
*/

# define CEILING_COLOR RGB_DARKBLUE
# define FLOOR_COLOR RGB_DARKGRAY

/*
** Define keys
*/

# define A 0
# define S 1
# define D 2
# define F 3
# define H 4
# define G 5
# define Z 6
# define X 7
# define C 8
# define V 9
# define B 11
# define Q 12
# define W 13
# define E 14
# define R 15
# define Y 16
# define T 17
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21
# define SIX 22
# define FIVE 23
# define NINE 25
# define SEVEN 26
# define EIGHT 28
# define ZERO 29
# define KEY_BRACE_R 30
# define O 31
# define U 32
# define KEY_BRACE_L 33
# define I 34
# define P 35
# define L 37
# define J 38
# define K 40
# define KEY_SEMI 41
# define N 45
# define M 46
# define TAB 48
# define SPACE 49
# define ESC 53
# define KEY_PLUS 69
# define KEY_MINUS 78
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define SHIFT_L 257
# define SHIFT_R 258

typedef struct		s_textures
{
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_textures;

typedef struct		s_sprites
{
	double			x;
	double			y;
	t_textures		tex;
}					t_sprites;

typedef struct		s_params
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_width;
	int				win_height;
	int				map_width;
	int				map_height;
	int				tex_width;
	int				tex_height;
	int				map[1000][1000];
	char			*map_file;
	int				initial_pos;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	unsigned int	color;
	unsigned int	ceiling_color;
	unsigned int	floor_color;
	double			movespeed;
	double			rotspeed;
	double			olddirx;
	double			oldplanex;
	int				up;
	int				down;
	int				right_rot;
	int				left_rot;
	int				right_mov;
	int				left_mov;
	int				run;
	int				texnum;
	double			wallx;
	void			*img_ptr;
	char			*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				*xpmw;
	int				*xpmh;
	t_textures		tex[12];
	int				tex_id;
	int				tex_x;
	int				tex_y;
	int				tex_side;
	double			floorxwall;
	double			floorywall;
	double			distwall;
	double			distplayer;
	double			currentdist;
	double			weight;
	double			currentfloorx;
	double			currentfloory;
	int				floortexx;
	int				floortexy;
	t_sprites		sprite[10];
	double			spr_buffer[SCREENWIDTH];
	int				spr_order[10];
	double			spr_dist[10];
	int				sprtexx;
	int				sprtexy;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				stripe;
	int				d;
	double			enem_stepx;
	double			enem_stepy;
	double			life;
	int				score;
}					t_params;

/*
** main.c
*/

int					close_success(t_params *p);
int					close_failure(char *message);

/*
** cub3d_raycast.c
*/

int					raycasting(t_params *p);

/*
** cub3d_initialization.c
*/

void				params_init(t_params *p, char *map);
void				map_reader(t_params *p);
void				map_error_check(t_params *p);
void				map_position(t_params *p);

/*
** cub3d_init_orientation.c
*/

void				orientation_n(t_params *p, int i, int j);
void				orientation_s(t_params *p, int i, int j);
void				orientation_e(t_params *p, int i, int j);
void				orientation_w(t_params *p, int i, int j);

/*
** cub3d_textures.c
*/

void				screen_draw(int x, t_params *p);
void				textures_from_file(t_params *p);
void				textures_process(int x, t_params *p);

/*
** cub3d_sprites.c
*/

void				sprite_casting(t_params *p);

/*
** cub3d_movement.c
*/

int					movement(t_params *p);
void				move_right_left(t_params *p);
void				rotation(t_params *p);
int					key_press(int key, t_params *p);
int					key_release(int key, t_params *p);

/*
** cub3d_floor_ceiling.c
*/

void				floor_casting(t_params *p, int x);

/*
** cub3d_utils.c
*/

void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_putstr(char *s);
char				*ft_delete_spaces(char *str);
char				*ft_itoa(int n);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** get_next_line
*/

int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);

/*
** cub3d_hud.c
*/

void				hud(t_params *p);

/*
** cub3d_screensave.c
*/

int					save_bmp(t_params *p);
int					raycastingbmp(t_params *p);

#endif