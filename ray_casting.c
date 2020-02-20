/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:49:39 by tglandai          #+#    #+#             */
/*   Updated: 2020/02/20 16:56:00 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda_init(t_params *p)
{
	p->x_deltadist = sqrt(1 + (p->y_raydir * p->y_raydir)
			/ (p->x_raydir * p->x_raydir));
	p->y_deltadist = sqrt(1 + (p->x_raydir * p->x_raydir)
			/ (p->y_raydir * p->y_raydir));
	if (p->x_raydir < 0)
	{
		p->x_step = -1;
		p->x_sidedist = (p->x_raypos - p->x_map) * p->x_deltadist;
	}
	else
	{
		p->x_step = 1;
		p->x_sidedist = (p->x_map + 1.0 - p->x_raypos) * p->x_deltadist;
	}
	if (p->y_raydir < 0)
	{
		p->y_step = -1;
		p->y_sidedist = (p->y_raypos - p->y_map) * p->y_deltadist;
	}
	else
	{
		p->y_step = 1;
		p->y_sidedist = (p->y_map + 1.0 - p->y_raypos) * p->y_deltadist;
	}
}

void	dda(t_params *p)
{
	p->hit = 0;
	while (p->hit == 0)
	{
		if (p->x_sidedist < p->y_sidedist)
		{
			p->x_sidedist += p->x_deltadist;
			p->x_map += p->x_step;
			p->side = 0;
		}
		else
		{
			p->y_sidedist += p->y_deltadist;
			p->y_map += p->y_step;
			p->side = 1;
		}
		if (p->map[p->x_map][p->y_map] > 0)
			p->hit = 1;
	}
}

void	ray_casting_init(t_params *p, int x)
{
	p->x_cam = 2 * x / (double)(p->win_width) - 1;
	p->x_raypos = p->x_pos;
	p->y_raypos = p->y_pos;
	p->x_raydir = p->x_dir + p->x_plane * p->x_cam;
	p->y_raydir = p->y_dir + p->y_plane * p->x_cam;
	p->x_map = (int)p->x_raypos;
	p->y_map = (int)p->y_raypos;
	dda_init(p);
	dda(p);
	if (p->side == 0)
		p->walldist = (p->x_map - p->x_raypos +
				(1 - p->x_step) / 2) / p->x_raydir;
	else
		p->walldist = (p->y_map - p->y_raypos +
				(1 - p->y_step) / 2) / p->y_raydir;
}

void	floor_and_ceiling(t_params *p, int x)
{
	if(p->texture == 1)
	{
		if (p->start > 0)
		{
			p->color = 0x66CCFF;
			p->y = -1;
			if (x < p->win_width && p->y < p->win_height)
				while (++p->y < p->start)
				{
					ft_memcpy(p->img_ptr + 4 * p->win_width * p->y + x * 4,
							&p->color, sizeof(int));
				}
		}
	}

	if (p->end > 0)
	{
		p->color = 0x333333;
		p->y = p->end - 1;
		if (x < p->win_width && p->y < p->win_height)
			while (++p->y < p->win_height)
				ft_memcpy(p->img_ptr + 4 * p->win_width * p->y + x * 4,
						&p->color, sizeof(int));
	}
}

void	ray_casting(t_params *p)
{
	p->x = -1;
	p->img = mlx_new_image(p->mlx, p->win_width, p->win_height);
	p->img_ptr = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->endian);
	draw_sky(p);
	while (++p->x < p->win_width)
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
		wall_orientation(p);
		draw_wall(p->x, p->start - 1, p->end, p);
		floor_and_ceiling(p, p->x);
	}
	//draw_minimap(p);
	//draw_sprites(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
}
