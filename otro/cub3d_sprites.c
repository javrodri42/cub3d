/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:26:08 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/13 18:47:31 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	loop through every vertical stripe of the sprite on screen
**	the conditions in the if are:
**	1) it's in front of camera plane so you don't see things behind you
**	2) it's on the screen (left)
**	3) it's on the screen (right)
**	4) ZBuffer, with perpendicular distance
*/

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
					ft_memcpy(p->img_data + 4 * p->win_width * y + p->stripe *
					4, &p->sprite[i].tex.data[p->sprtexy % p->tex_height *
					p->sprite[i].tex.sizeline + p->sprtexx % p->tex_width *
					p->sprite[i].tex.bpp / 8], sizeof(int));
				y++;
			}
		p->stripe++;
	}
}

/*
**	Enemy movement, walking towards player.
**	color changing if it's close enough.
*/

static void	enemy_movement(t_params *p, double x, double y, int i)
{
	p->enem_stepx = (p->posx - x) / 700;
	p->enem_stepy = (p->posy - y) / 700;
	p->sprite[1].x = p->sprite[1].x + p->enem_stepx;
	p->sprite[1].y = p->sprite[1].y + p->enem_stepy;
	if ((p->posx - x) < 0.8 && (p->posy - y) < 0.8 && i == 1)
	{
		if (p->life == 100)
			system("say -v Monica ay que daño");
		p->life -= 0.9;
		p->sprite[1].tex = p->tex[9];
	}
	else
		p->sprite[1].tex = p->tex[8];
	if (i > 1 && (p->posx - x) < 0.8 && (p->posy - y) < 0.8)
	{
		p->score += 100;
		p->sprite[i].x = 0;
		p->sprite[i].y = 0;
	}
}

/*
**	SPRITE CASTING
**	transform sprite with the inverse camera matrix
**	[ planex   dirx ] -1                                    [ diry      -dirx ]
**	[               ]    =  1/(planex*diry-dirx*planey) *   [                 ]
**	[ planey   diry ]                                       [ -planey  planex ]
*/

static void	sprite_casting_2(t_params *p, int i)
{
	p->spritex = p->sprite[i].x - p->posx;
	p->spritey = p->sprite[i].y - p->posy;
	p->invdet = 1.0 / (p->planex * p->diry - p->dirx * p->planey);
	p->transformx = p->invdet * (p->diry * p->spritex - p->dirx *
		p->spritey);
	p->transformy = p->invdet * (-p->planey * p->spritex + p->planex
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
		enemy_movement(p, p->sprite[1].x, p->sprite[1].y, i);
		sprite_drawing(p, i);
		i++;
	}
}
