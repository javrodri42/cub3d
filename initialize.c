/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:43:16 by javrodri          #+#    #+#             */
/*   Updated: 2020/01/25 14:21:25 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    params_initialice(t_params *p, char *map)
{
    p->posX = 3;
    p->posY = 3;
    p->win_height  = 980;
    p->win_width = 1640;
    p->time = 0;
    p->oldtime = 0;
    p->dirX = -1;
    p->dirY = 0;
    p->planeX = 0;
    p->planeY = 0.66;
    p->flag_front = 0;
    p->flag_back = 0;
    p->flag_left = 0;
    p->flag_right = 0;
    p->flag_rotate_left = 0;
    p->flag_rotate_right = 0;
    p->moveSpeed = 0.0001;
    p->rotSpeed = 0.00005;
    p->map_width = 0;
    p->map_height = 0;
    p->map_file = map;
    p->initial_pos  = 0;
    p->tex_height = 64;
    p->tex_width = 64;
    p->color_sky = RGB_BLUESKY;
    p->color_floor = RGB_DARKGRAY;
    load_textures(p);
}

void    mlx_win_init(t_params *p)
{
    char    *title;

    title = ft_strjoin("Cube3d : ", p->map_name);
    p->mlx_ptr = mlx_init();
    p->mlx_ptr = mlx_new_window(p->mlx_ptr, screenWidth, screenHeight, title);
    ft_strdel(&title);
}

void		map_error_check(t_params *p)
{
	int i;

	if (p->map_height < 3 || p->map_width < 3)
		close_failure("Error\nThis map is too small\n");
	if (!p->initial_pos)
		close_failure("Error\nThere isn't an initial position\n");
	if (p->initial_pos > 1)
		close_failure("Error\nThere's more than one initial position\n");
	i = -1;
	while (++i < p->map_width)
		if (p->map[0][i] == 0 || p->map[p->map_height - 1][i] == 0)
			close_failure("Error\nThis map isn't completely walled\n");
	i = -1;
	while (++i < p->map_height)
		if (p->map[i][0] == 0 || p->map[i][p->map_width - 1] == 0)
			close_failure("Error\nThis map isn't completely walled\n");
}

void    raycasting_init(t_params *p, int x)
{
    p->cameraX = 2 * x / (double)p->win_width - 1;
    p->rayDirX = p->dirX + p->planeX * p->cameraX;
    p->rayDirY = p->dirY + p->planeY * p->cameraX;
    p->mapX = (int)p->posX;
    p->mapY = (int)p->posY;
    dda_init(p);
    dda(p);
    if (p->side == 0)
        p->perpWallDist = (p->mapX - p->posX + (1 - p->stepX) / 2) / p->rayDirX;
    else
        p->perpWallDist = (p->mapY - p->posY + (1 - p->stepY) / 2) / p->rayDirY;   
}

void    dda_init(t_params *p)
{
    p->deltaDistX = fabs(1 / p->rayDirX);
    p->deltaDistY = fabs(1 / p->rayDirY);
    
    if (p->rayDirX < 0)
    {
        p->stepX = -1;
        p->sideDistX = (p->posX - p->mapX) * p->deltaDistX;
    }
    else
    {
        p->stepX = 1;
        p->sideDistX = (p->mapX + 1.0 - p->posX) * p->deltaDistX;
    }
    if (p->rayDirY < 0)
    {
        p->stepY = -1;
        p->sideDistY = (p->posY - p->mapY) * p->deltaDistY;
    }
    else
    {
        p->stepY = 1;
        p->sideDistY = (p->mapY + 1 - p->posY) * p->deltaDistY;
    }
}