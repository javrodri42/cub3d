/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_bmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:49:48 by javrodri          #+#    #+#             */
/*   Updated: 2020/02/21 19:59:58 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_casting_bmp(t_params *p)
{
	p->x = -1;
	p->img = mlx_new_image(p->mlx, WINX, WINY);
	p->img_ptr = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->endian);
	draw_sky(p);
	while (++p->x < WINX)
	{
		ray_casting_init(p, p->x);
		p->lineheight = (int)(WINY / p->walldist);
		p->start = -p->lineheight / 2 + WINY / 2;
		if (p->start < 0)
			p->start = 0;
		p->end = p->lineheight / 2 + WINY / 2;
		if (p->end >= WINY)
			p->end = WINY - 1;
		if (p->side == 1)
			p->color = 0xdd8800;
		else
			p->color = 0x00FF00;
		draw_wall(p->x, p->start - 1, p->end, p);
		floor_and_ceiling(p, p->x);
	}
	save_bmp(p);
	ft_close(p);
}