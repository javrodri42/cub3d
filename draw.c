/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 08:20:56 by javrodri          #+#    #+#             */
/*   Updated: 2020/01/28 09:21:49 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_wall(int x, int start, int end, t_params *p)
{
    if (p->texture == 1)
    {
        p->id = p->map[p->mapX][p->mapY];
        if (p->side == 0)
            p->wallX = p->posY + p->perpWallDist * p->rayDirY;
        else      
            p->wallX = p->posX + p->perpWallDist * p->rayDirX;
        p->texX = (int)(p->wallX * (double)(64));
        if (p->side == 0 && p->posX > 0)
            p->texX = 64 - p->texX - 1;
        if (p->side == 1 && p->posY < 0)
            p->texX = 64 - p->texX - 1;;
        p->texX = abs(p->texX);           
    }
    while (++p->drawStart <= p->drawEnd)
        put_pxl_to_img(p, x, start, p->color);
}

void    floor_roof(t_params *p, int x)
{
    if (p->texture == 0)
    {
        if (p->drawStart > 0)
        {
            p->color = 0x66CCFF;
            p->y = -1;
            if (x < screenWidth && p->y < screenHeight)
                while (++p->y < p->drawStart)
                {
                    ft_memcpy(p->img_ptr + 4 * screenWidth * p->y + x * 4, &p->color, sizeof(int));
                }
        }
    }
    if (p->drawEnd > 0)
    {
        p->color = 0x333333;
        p->y = p->drawEnd - 1;
        if (x < screenWidth && p->y > screenHeight)
            while (++p->y < screenHeight)
                ft_memcpy(p->img_ptr + 4 * screenWidth * p->y + x * 4, &p->color, sizeof(int));
                
    }
}

void    put_pxl_to_img(t_params *p, int x, int y, int color)
{
    if (p->texture == 1 && x < screenWidth && y < screenHeight)
    {
        p->texY = abs((((y * 256 - screenHeight *128 + p->lineHeight * 128) * 64) / p->lineHeight) / 256);
        ft_memcpy(p->img_ptr + 4 * screenWidth * y + x * 4,
                &p->tex[p->id].data[p->texY % 64 * p->tex[p->id].sizeline + 
                p->texX % 64 * p->tex[p->id].bpp / 8], sizeof(int));
    }
    else if (x < screenWidth && y < screenHeight)
        ft_memcpy(p->img_ptr + 4 * screenWidth * y + x * 4,
        &color, sizeof(int));
}
