/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 10:08:11 by javrodri          #+#    #+#             */
/*   Updated: 2020/02/20 19:42:32 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "cub3d.h"

void draw_sprites(t_params *p)
{
    t_sprites       *s;
    double          inv_det;

    inv_det = 1.0 / ((p->x_plane * p->y_dir) - (p->y_plane * p->x_dir));
    s->transformX = inv_det * (p->y_dir * s->spriteX - p->x_dir * s->spriteY);
    s->transformY = inv_det * (-p->y_plane * s->spriteX + p->x_plane * s->spriteY);
    s->sprite_screenX = ((p->win_width / 2) * (1 + s->transformX / s->transformY));
    s->sprite_height = fabs(p->win_height / s->transformY);
    s->draw_startY = -s->sprite_height / 2 + p->win_height / 2;
    if(s->draw_startY < 0)
        s->draw_startY = 0;
    s->draw_endY = s->sprite_height / 2 + p->win_height / 2;
    if(s->draw_endY >= p->win_height)
        s->draw_endY = p->win_height - 1;
     
    s->sprite_width = fabs(p->win_height / s->transformY);
    s->draw_startX = -s->sprite_width / 2 + s->sprite_screenX;
    if(s->draw_startX < 0)
        s->draw_startX = 0;
    s->draw_endX = s->sprite_width / 2 + s->sprite_screenX;
    if(s->draw_endX >= p->win_width)
        s->draw_endX = p->win_width - 1;

    s->stripe = s->draw_startX;
    while(s->stripe < s->draw_endX)
    {
        s->texX = ((256 * (s->stripe - ( -s->sprite_width / 2 + s->sprite_screenX)) * 64 / s->sprite_width) / 256);
        if(s->transformY > 0 && s->stripe > 0 && s->stripe <  )
        {
            while ()
        }
        s->stripe++;
    }*/
}
