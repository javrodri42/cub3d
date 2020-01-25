/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:38:34 by javrodri          #+#    #+#             */
/*   Updated: 2020/01/25 14:16:12 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

#include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_textures
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_textures;

typedef struct  s_params
{
    void        *mlx_ptr;
    void        *win_ptr;
    void        *img_ptr;
	void		*img;
    void        *img_data;
    int         win_width;
    int         win_height;
    char        *map_name;
    double      posX;
    double      posY;
    double      dirX;
    double      dirY;
    double      time;
    double      oldtime;
    int         hit;
    int         side;
    int         color;
    double      planeX;
    double      planeY;
    int         drawStart;
    int         drawEnd;
    int         bpp;
    int         size_line;
    int         endian;
    double      sideDistX;
    double      sideDistY;
    double	    deltaDistX;
	double	    deltaDistY;
    double      rayDirX;
    double      rayDirY;
    int         stepX;
    int         stepY;
    int         lineHeight;
    double      perpWallDist;
    double      frametime;
    double      rotSpeed;
    double      moveSpeed;
    int         mapX;
    int         mapY;
    int         key;
    int         flag_front;
    int         flag_back;
    int         flag_right;
    int         flag_left;
    int         flag_rotate_right;
    int         flag_rotate_left;
    int         flag_view_up;
    double      cameraX;
    double      cameraY;
    double      olddirX;
    double      oldplaneX;
    int         color_sky;
    int         color_floor;
    int         tex_y;
    int         fd;
    int         map[1000][1000];
    char        *map_file;
    int         map_width;
    int         map_height;
    int		    initial_pos;
    t_textures  tex[10];
    int         tex_width;
    int         tex_height;
    int         texNum;
    double      wallX;
    int         texX;
    int         y;
    int         x;
    int         texture;
   
}               t_params;


#define mapWidth 24
#define mapHeight 24
#define screenWidth 1280
#define screenHeight 960
#define BUFFER_SIZE 100

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
# define RGB_BLUESKY 0x87FFFA

/*
** Define keys
*/

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ESC 53
# define A 0
# define W 13
# define S 1
# define D 2
# define VIEW_UP 30

/*
** Get_next_line functions
*/ 

int				get_next_line(int fd, char **line);

/*
** Initialize
*/

void            dda_init(t_params *p);
void            raycasting_init(t_params *p, int x);
void            params_initialice(t_params *p, char *map);
void	        mlx_win_init(t_params *t);

/*
** Utils
*/ 

size_t	        ft_strlen(const char *str);
void	        *ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_substr(char const *s, unsigned int start, ssize_t len);
int		        close_success(t_params *p);
int		        close_failure(char *message);
void        	ft_putstr(const char *str);
int		       	ft_atoi(const char *str);
char	    	*ft_itoa(int n);
void	        ft_putchar(char c);
char	        *ft_strjoin(char const *s1, char const *s2);
char	        *ft_strdup(const char *src);
char	        *ft_strchr(const char *s, int c);
int             ft_strcmp(char *s1, char *s2);
void        	ft_strdel(char **as);

/*
** Map Position
*/

void            orientation_n(t_params *p, int i, int j);
void            orientation_s(t_params *p, int i, int j);
void            orientation_e(t_params *p, int i, int j);
void            orientation_w(t_params *p, int i, int j);

/*
** Textures
*/

void            load_textures(t_params *p);

int             main(int argc, char **argv);
int             loop_draw(t_params *p);
int             ft_movement(t_params *p);
void            walk_front(t_params *p);
void            walk_back(t_params *p);
void            walk_left(t_params *p);
void            walk_right(t_params *p);
int             close_success(t_params *p);
int             key_press(int key, t_params *p);
int             key_release(int key, t_params *p);
void            rotation(t_params *p);
void            screen_draw(int x, t_params *p);
void            map_reader(t_params *p);
void		    map_position(t_params *p);
void		    map_error_check(t_params *p);


/*
int map[mapWidth][mapHeight] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

*/
#endif