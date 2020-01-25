/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:43:59 by javrodri          #+#    #+#             */
/*   Updated: 2020/01/25 13:19:22 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void walk_front(t_params *p)
{
    if (p->map[(int)(p->posX + p->dirX * p->moveSpeed)][(int)(p->posY)] == 0)
        p->posX += p->dirX * p->moveSpeed;
    if (p->map[(int)(p->posX)][(int)(p->posY + p->dirY * p->moveSpeed)] == 0)
        p->posY += p->dirY * p->moveSpeed;
}

void walk_back(t_params *p)
{
    if (!p->map[(int)(p->posX - p->dirX * p->moveSpeed)][(int)p->posY])
        p->posX -= p->dirX * p->moveSpeed;
    if (!p->map[(int)p->posX][(int)(p->posY - p->dirY * p->moveSpeed)])
        p->posY -= p->dirY * p->moveSpeed; 
}

void walk_left(t_params *p)
{
    if (!p->map[(int)(p->posX - p->dirY * p->moveSpeed)][(int)(p->posY)])
        p->posX -= p->dirY * p->moveSpeed;
    if (!p->map[(int)(p->posX)][(int)(p->posY + p->dirX * p->moveSpeed)])
        p->posY += p->dirX * p->moveSpeed;
}

void walk_right(t_params *p)
{
    if (!p->map[(int)(p->posX + p->dirY * p->moveSpeed)][(int)(p->posY)])
        p->posX += p->dirY * p->moveSpeed;
    if (!p->map[(int)(p->posX)][(int)(p->posY - p->dirX * p->moveSpeed)])
        p->posY -= p->dirX * p->moveSpeed;
}

void rotation(t_params *p)
{
    p->olddirX = p->dirX;
    if (p->flag_rotate_left)
    {
        p->dirX = p->dirX * cos(p->rotSpeed) - p->dirY * sin(p->rotSpeed);
        p->dirY = p->olddirX * sin(p->rotSpeed) + p->dirY * cos(p->rotSpeed);
        p->oldplaneX = p->planeX;
        p->planeX = p->planeX * cos(p->rotSpeed) - p->planeY * sin(p->rotSpeed);
        p->planeY = p->oldplaneX * sin(p->rotSpeed) + p->planeY * cos(p->rotSpeed);
    }
    if (p->flag_rotate_right)
    {
        p->dirX = p->dirX * cos(-p->rotSpeed) - p->dirY * sin(-p->rotSpeed);
		p->dirY = p->olddirX * sin(-p->rotSpeed) + p->dirY * cos(-p->rotSpeed);
		p->oldplaneX = p->planeX;
		p->planeX = p->planeX * cos(-p->rotSpeed) - p->planeY * sin(-p->rotSpeed);
		p->planeY = p->oldplaneX * sin(-p->rotSpeed) + p->planeY * cos(-p->rotSpeed);   
    }
    //p->moveSpeed = 0.0006 * pow(1.0009, p->win_width);
}

int ft_movement(t_params *p)
{
    if (p->flag_front)
        walk_front(p);
    if (p->flag_back)
        walk_back(p);
    if (p->flag_left)
        walk_left(p);
    if (p->flag_right)
        walk_right(p);
    if (p->flag_rotate_left || p->flag_rotate_right)
        rotation(p);
    raycasting(p);
    return (0);
}