/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:49:39 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/06 15:47:04 by javrodri         ###   ########.fr       */
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
		if (p->map[p->x_map][p->y_map] == 1)
			p->hit = 1;
		if (p->map[p->x_map][p->y_map] == 2)
		{
			p->sprite_posx = p->x_map;
			p->sprite_posy = p->y_map;
		}
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

void	ray_casting_init_2(t_params *p)
{
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
}

void	ray_casting(t_params *p)
{
	p->x = 0;
	p->img = mlx_new_image(p->mlx, p->win_width, p->win_height);
	p->img_ptr = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->endian);
	if (p->texture == 1)
		draw_sky(p);
	orientation_tex_walls(p);
	while (p->x < p->win_width)
	{
		ray_casting_init(p, p->x);
		ray_casting_init_2(p);
		draw_wall(p->x, p->start - 1, p->end, p);
		floor_and_ceiling(p, p->x);
		p->spr_buffer[p->x] = p->walldist;
		p->x++;
	}
	draw_sprites(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
