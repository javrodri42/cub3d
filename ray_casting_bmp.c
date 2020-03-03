/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_bmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:49:48 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/03 08:46:45 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	 ray_casting_bmp(t_params *p)
{
	p->x = 0;
	p->img = mlx_new_image(p->mlx, p->win_width, p->win_height);
	p->img_ptr = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->endian);
	if (p->texture ==1)
		draw_sky(p);
	draw_floor(p);
	orientation_tex_walls(p);
	while (p->x < p->win_width)
	{
		ray_casting_init(p, p->x);
		p->lineheight = (int)(p->win_height / p->walldist);
		p->start = -p->lineheight / 2 + p->win_height / 2;
		if (p->start < 0)
			p->start = 0;
		p->end = p->lineheight / 2 + p->win_height / 2;
		if (p->end >= p->win_height)
			p->end = p->win_height - 1;
		if (p->side == 1)
			p->color = 0xdd8800;
		else
			p->color = 0x00FF00;
		draw_wall(p->x, p->start - 1, p->end, p);
		floor_and_ceiling(p, p->x);
		p->spr_buffer[p->x] = p->walldist;
		p->x++;
	}
	draw_sprites(p);
	save_bmp(p);
	ft_close(p);
 }
 