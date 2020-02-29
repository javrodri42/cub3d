/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 10:08:11 by javrodri          #+#    #+#             */
/*   Updated: 2020/02/29 18:16:59 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
static void	sprite_drawing(t_params *p, int i)
{
	int y;
	p->stripe = p->drawstartx;
	while (p->stripe < p->drawendx)
	{
		y = p->drawstarty;
		p->sprtexx = (int)(256 * (p->stripe - (-p->spritewidth /
		2 + p->spritescreenx)) * p->tex_width / p->spritewidth) / 256;
		if (p->transformy > 0 && p->stripe > 0 && p->stripe < p->win_width &&
		p->transformy < p->spr_buffer[p->stripe])
            while (y < p->drawendy)
            {
                p->d = (y) * 256 - p->win_height * 128 + p->spriteheight * 128;
                p->sprtexy = ((p->d * p->tex_height) / p->spriteheight) / 256;
                if (++y < p->win_height && p->sprite[i].tex.data[p->sprtexy %
                p->tex_height * p->sprite[i].tex.sizeline + p->sprtexx %
                p->tex_width * p->sprite[i].tex.bpp / 8])
                    ft_memcpy(p->img_ptr + 4 * p->win_width * y + p->stripe *
                    4, &p->sprite[i].tex.data[p->sprtexy % p->tex_height *
                    p->sprite[i].tex.sizeline + p->sprtexx % p->tex_width *
                    p->sprite[i].tex.bpp / 8], sizeof(int));
                y++;
            }
		p->stripe++;
	}
}

static void	sprite_casting_2(t_params *p, int i)
{
	p->spritex = p->sprite[i].x - p->x_pos;
	p->spritey = p->sprite[i].y - p->y_pos;
	p->invdet = 1.0 / (p->x_plane * p->y_dir - p->x_dir * p->y_plane);
	p->transformx = p->invdet * (p->y_dir * p->spritex - p->x_dir *
		p->spritey);
	p->transformy = p->invdet * (-p->y_plane * p->spritex + p->x_plane
		* p->spritey);
	p->spritescreenx = (int)((p->win_width / 2) * (1 + p->transformx /
		p->transformy));
	p->spriteheight = abs((int)(p->win_height / (p->transformy)));
	p->drawstarty = -p->spriteheight / 2 + p->win_height / 2;
}

void		sprite_casting(t_params *p)
{
	int i;

	i = 0;
	while (i < NUMSPRITES)
	{		
		sprite_casting_2(p, i);
		if (p->drawstarty < 0)
			p->drawstarty = 0;
		p->drawendy = p->spriteheight / 2 + p->win_height / 2;
		if (p->drawendy >= p->win_height)
			p->drawendy = p->win_height - 1;
		p->spritewidth = abs((int)(p->win_height / (p->transformy)));
		p->drawstartx = -p->spritewidth / 2 + p->spritescreenx;
		if (p->drawstartx < 0)
			p->drawstartx = 0;
		p->drawendx = p->spritewidth / 2 + p->spritescreenx;
		if (p->drawendx >= p->win_width)
			p->drawendx = p->win_width - 1;
		sprite_drawing(p, i);
		i++;
	}
}*/


void    draw_sprites(t_params *p)
{
    int y;
    int x;

    p->spritex = (double)p->sprite_posx - p->x_pos;
    p->spritey = (double)p->sprite_posy - p->y_pos;

    p->invdet = 1.0 / (p->x_plane * p->y_dir - p->x_dir * p->y_plane);
    p->transformx = p->invdet * (p->y_dir * p->spritex - p->x_dir * p->spritey);
    p->transformy = p->invdet * (-p->y_plane * p->spritex + p->x_plane * p->spritey);
	p->spritescreenx = (int)((p->win_width / 2) * (1 + p->transformx / p->transformy));
	p->spriteheight = abs((int)(p->win_height / p->transformy));
	p->drawstarty = -p->spriteheight / 2 + p->spritescreenx;
	if (p->drawstarty < 0)
		p->drawstarty = 0;
	p->drawendy = p->spriteheight / 2 + p->win_height / 2;
	if (p->drawendy >= p->win_height)
		p->drawendy = p->win_height - 1;
	p->spritewidth = abs((int)(p->win_height / p->transformy));
	p->drawstartx = -p->spritewidth / 2 + p->spritescreenx;
	if (p->drawstartx < 0)
		p->drawstartx = 0;
	p->drawendx = p->spritewidth / 2 + p->spritescreenx;
	if (p->drawendx >= p->win_width)
		p->drawendx = p->win_width - 1;
	x = p->drawstartx - 1;

	printf("sprite_posx:%i\n", p->sprite_posx);
	printf("sprite_posY:%i\n", p->sprite_posy);
	printf("x_pos:%i\n", p->x_pos);
	printf("y_pos:%i\n", p->y_pos);
	//printf("invdet:%f\n", p->invdet);
	//printf("invdet:%f\n", p->invdet);
	printf("invdet:%f\n", p->invdet);
	printf("transformX:%f\n", p->transformx);
	printf("trasnformY:%f\n", p->transformy);
	printf("spriteheight:%i\n", p->spriteheight);
	printf("spritewidth: %i\n", p->spritewidth);
	printf("drawstart:%i\n", p->drawstartx);
	printf("x:        %i\n", x);
	printf("drawend:  %i\n", p->drawendx);
	printf("\n");
	//system("clear");
	while (++x < p->drawendx)
	{
		printf("aqui");
		p->x_text = (int)(256 * (x - (-p->spritewidth / 2 + 
		p->spritescreenx)) * p->tex_width / p->spritewidth) / 256;	
		y = p->drawstarty;
		if (p->transformy > 0 && x > 0 && x < p->win_width 
			&& p->transformy < p->spr_buffer[x])
		{
			while (y < p->drawendy)
			{
				p->y_text = abs((((y * 256 - p->win_height * 128 + 
					p->spriteheight * 128) * p->tex_height) / p->spriteheight) / 256);
				if ((p->tex[20].data[p->y_text % 64 * p->tex[20].sizeline + p->x_text % 64 * p->tex[20].bpp / 8] != 0))
				{
					ft_memcpy(p->img_ptr + 4 * p->map_width * y + x *4, &p->tex[20].data[p->x_text % 64 * p->tex[20].sizeline + p->x_text % 64 * p->tex[20].bpp / 8], sizeof(int));
				}
				y++;
			}
			
		}
	}
	
}