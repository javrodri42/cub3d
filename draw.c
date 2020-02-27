/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 20:41:03 by tglandai          #+#    #+#             */
/*   Updated: 2020/02/27 12:19:54 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pxl_to_img(t_params *p, int x, int y, int color)
{
	if (p->texture == 1 && x < p->win_width && y < p->win_height)
	{
		p->y_text = abs((((y * 256 - p->win_height * 128 + p->lineheight * 128) * 64)
					/ p->lineheight) / 256);
		ft_memcpy(p->img_ptr + 4 * p->win_width * y + x * 4,
				&p->tex[p->id].data[p->y_text % 64 * p->tex[p->id].sizeline +
				p->x_text % 64 * p->tex[p->id].bpp / 8], sizeof(int));
	}
	else if (x < p->win_width && y < p->win_height)
		ft_memcpy(p->img_ptr + 4 * p->win_width * y + x * 4,
				&color, sizeof(int));
}

void	draw_wall(int x, int start, int end, t_params *p)
{
	if (p->texture == 1)
	{
		p->id = p->map[p->x_map][p->y_map];
		orientation_tex_walls(p);
		if (p->side == 0)
			p->x_wall = p->y_raypos + p->walldist * p->y_raydir;
		else
			p->x_wall = p->x_raypos + p->walldist * p->x_raydir;
		p->x_text = (int)(p->x_wall * (double)(64));
		if (p->side == 0 && p->x_raydir > 0)
			p->x_text = 64 - p->x_text - 1;
		if (p->side == 1 && p->y_raydir < 0)
			p->x_text = 64 - p->x_text - 1;
		p->x_text = abs(p->x_text);
	}
	while (++start <= end)
		put_pxl_to_img(p, x, start, p->color);
}

void	draw_sky(t_params *p)
{
	p->x_text = 0;
	while (p->x_text < p->win_width)
	{
		p->y_text = 0;
		while (p->y_text < p->win_height / 2)
		{
			ft_memcpy(p->img_ptr + 4 * p->win_width * p->y_text + p->x_text * 4,
					&p->tex[6].data[p->y_text % 512 * p->tex[6].sizeline +
					p->x_text % 512 * p->tex[6].bpp / 8], sizeof(int));
			p->y_text++;
		}
		p->x_text++;
	}
}

void	draw_floor(t_params *p)
{
	p->x_text = 0;
	while (p->x_text < p->win_width)
	{
		p->y_text = p->win_height / 2;
		while (p->y_text < p->win_height)
		{
			ft_memcpy(p->img_ptr + 4 * p->win_width * p->y_text + p->x_text * 4,
					&p->tex[5].data[p->y_text % 64 * p->tex[5].sizeline +
					p->x_text % 64 * p->tex[5].bpp / 8], sizeof(int));
			p->y_text++;
		}
		p->x_text++;
	}
}
