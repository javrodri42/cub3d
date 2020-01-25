/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:38:23 by javrodri          #+#    #+#             */
/*   Updated: 2020/01/25 14:25:36 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int loop_draw(t_params *p)
{
     
    int x;
    
    x = 0;
    p->img_ptr = mlx_new_image(p->mlx_ptr, p->win_width, p->win_height);
    p->img_data = mlx_get_data_addr(p->img_ptr, &p->bpp, &p->size_line, &p->endian);
    while (x < p->win_width)
    {   
        ft_movement(p);
        p->cameraX = 2 * x / (double)p->win_width - 1;
        p->rayDirX = p->dirX + p->planeX * p->cameraX;
        p->rayDirY = p->dirY + p->planeY * p->cameraX;
        p->mapX = (int)p->posX;
        p->mapY = (int)p->posY; 
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
        p->hit = 0;
        while (p->hit == 0)
        {
            if (p->sideDistX < p->sideDistY)
            {
                p->sideDistX += p->deltaDistX;
                p->mapX += p->stepX;
                p->side = 0;
            }
            else
            {
                p->sideDistY += p->deltaDistY;
                p->mapY += p->stepY;
                p->side = 1;
            }
            if (p->map[p->mapX][p->mapY] > 0)
                p->hit = 1;
        }
        if (p->side == 0)
            p->perpWallDist = (p->mapX - p->posX + (1 - p->stepX) / 2) / p->rayDirX;
        else
            p->perpWallDist = (p->mapY - p->posY + (1 - p->stepY) / 2) / p->rayDirY;
            
        p->lineHeight = (int)p->win_height / p->perpWallDist;
        p->drawStart = -p->lineHeight / 2 + p->win_height / 2;
        if (p->drawStart < 0)
            p->drawStart = 0;
        p->drawEnd = p->lineHeight / 2 + p->win_height / 2;
        if (p->drawEnd >= p->win_height)
            p->drawEnd = p->win_height - 1;

        if (p->map[p->mapX][p->mapY] == 1)
            p->color = RGB_RED;
        else if (p->map[p->mapX][p->mapY] == 2)
            p->color = RGB_GREEN;
        else if (p->map[p->mapX][p->mapY] == 3)
            p->color = RGB_BLUE;      
        else if (p->map[p->mapX][p->mapY] == 4)
            p->color = RGB_WHITE;
        else 
            p->color = RGB_YELLOW;
        if (p->side == 1)
            p->color = p->color / 2;
/*
        p->texNum = p->map[p->mapX][p->mapY];
        if(p->side == 0)
            p->wallX = p->posY + p->perpWallDist * p->rayDirY;
        else
            p->wallX = p->posX + p->perpWallDist * p->rayDirX;
        p->wallX -=floor((p->wallX));
        
        p->texX = (int)(p->wallX * p->tex_width);
        if (p->side == 0 && p->rayDirX > 0)
            p->texX = p->tex_width - p->texX - 1;
        else if (p->side == 1 && p->rayDirY < 0)
            p->texX = p->tex_width - p->texX - 1;
*/
    //if (p->texture == 0){
        if (p->drawStart > 0)
        {
            p->color = 0x66CCFF;
            p->y = -1;
            if (x < p->win_width && p->y < p->win_height)
                while (++p->y < p->drawStart)
                {
                    ft_memcpy(p->img_ptr + 4 * p->win_width * p->y + x * 4,
                            &p->color, sizeof(int));
                }
        }

        if (p->drawEnd > 0)
        {
            p->color = 0x333333;
            p->y = p->drawEnd - 1;
            if (x < p->win_width && p->y < p->win_height)
                while (++p->y < p->win_height)
                    ft_memcpy(p->img_ptr + 4 * p->win_width * p->y + x * 4,
                            &p->color, sizeof(int));
        }

        
/*
        int r = p->drawEnd;
        while (r < screenHeight)
        {
            ft_memcpy(p->img_data + 4 * p->win_width * p->drawStart + x * 4, &p->color_sky, sizeof(int));
            r++;
        }
        if (p->flag_view_up)
        {
            while (p->drawEnd < screenHeight)
            {
                ft_memcpy(p->img_data + 4 * p->win_width * p->drawStart + x * 4, &p->color_floor, sizeof(int));
                p->drawEnd++;
            }
        }
 */      
        screen_draw(x, p);
        p->hit = 0;

        //p->moveSpeed = p->frametime * 5.0;
        //p->rotSpeed = p->frametime * 3.0;
        //printf("%i\n", &p->tex);
        //printf("[%i][%i][%i][%i][%i][%i]\n", p->flag_front, p->flag_back, p->flag_right, p->flag_left, p->flag_rotate_right, p->flag_rotate_left);
        //printf("%i\n", p->flag_back);
        //printf("map[%f][%f]\n", p->posX, p->posY);
        //printf("drawstart: %d\n", p->drawStart);
		//printf("end: %d\n", p->drawEnd);
		//printf("lineheight: %d\n", p->lineHeight);
        
		x++;
    }
    mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
    return (0);
}

void        screen_draw(int x, t_params *p)
{
    while (p->drawStart <= p->drawEnd)
    {
        ft_memcpy(p->img_data + 4 * p->win_width * p->drawStart + x * 4, &p->color, sizeof(int));
        p->drawStart++;
    }
}


void raycasting(t_params *p)
{
    p->x = -1;
    p->img = mlx_new_image(p->mlx_ptr, screenHeight, screenHeight);
    p->img_ptr = mlx_get_data_addr(p->img, &p->bpp, &p->size_line, &p->endian);
    if (p->texture == 1)
//PENDIENTE        draw_sky(p); 
    while (++p->x < screenHeight)
    {
        raycasting_init(p, p->x);
        p->lineHeight = (int)screenHeight / p->perpWallDist;
        p->drawStart = -p->lineHeight / 2 + screenHeight / 2;
        if (p->drawStart < 0)
            p->drawStart = 0;
        p->drawEnd = p->lineHeight / 2 + screenHeight / 2;
        if (p->drawEnd >= screenHeight)
            p->drawEnd = screenHeight - 1;
        if (p->side == 1)
            p->color = p->color / 2;
        draw_wall(p->x, p->drawStart - 1, p->drawEnd, p);
    }
}

void        dda(t_params *p)
{
    p->hit = 0;
    while (p->hit == 0)
    {
        if (p->sideDistX < p->sideDistY)
        {
            p->sideDistX += p->deltaDistX;
            p->mapX += p->stepX;
            p->side = 0;
        }
        else
        {
            p->sideDistY += p->deltaDistY;
            p->mapY += p->stepY;
            p->side = 1;
        }
        if (p->map[p->mapX][p->mapY] > 0)
            p->hit = 1;
    }
}