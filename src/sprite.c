/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 10:08:11 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/02 11:38:40 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_sprites(t_params *p)
{
	p->invdet = 1.0 / (p->x_plane * p->y_dir - p->x_dir * p->y_plane);
	p->transformx = p->invdet * (p->y_dir * p->spritex -
		p->x_dir * p->spritey);
	p->transformy = p->invdet * (-p->y_plane *
		p->spritex + p->x_plane * p->spritey);
	p->spritescreenx = (int)((p->win_width / 2) *
		(1 + p->transformx / p->transformy));
	p->spriteheight = abs((int)(p->win_height / p->transformy));
	p->drawstarty = -p->spriteheight / 2 + p->win_height / 2;
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
}

static void	ft_sprites(t_params *p, int y, int x)
{
	p->y_text = abs((((y * 256 - p->win_height * 128 +
		p->spriteheight * 128) * p->tex_height) / p->spriteheight) / 256);
	if ((p->tex[20].data[p->y_text % 64 * p->tex[20].sizeline
		+ p->x_text % 64 * p->tex[20].bpp / 8] != 0))
	{
		ft_memcpy(p->img_ptr + 4 * p->win_width * y + x * 4,
			&p->tex[20].data[p->y_text % 64 * p->tex[20].sizeline +
			p->x_text % 64 * p->tex[20].bpp / 8], sizeof(int));
	}
}

void		draw_sprites(t_params *p)
{
	int y;
	int x;

	p->spritex = (double)p->sprite_posx - p->x_pos;
	p->spritey = (double)p->sprite_posy - p->y_pos;
	calculate_sprites(p);
	x = p->drawstartx - 1;
	while (++x < p->drawendx)
	{
		p->x_text = (int)(256 * (x - (-p->spritewidth / 2 +
		p->spritescreenx)) * p->tex_width / p->spritewidth) / 256;
		y = p->drawstarty;
		if (p->transformy > 0 && x > 0 && x < p->win_width
			&& p->transformy < p->spr_buffer[x])
		{
			while (y < p->drawendy)
			{
				ft_sprites(p, y, x);
				y++;
			}
		}
	}
}
