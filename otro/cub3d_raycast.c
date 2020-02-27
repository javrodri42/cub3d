/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:52:34 by amaza-va          #+#    #+#             */
/*   Updated: 2020/02/27 09:28:44 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Calculate distance projected on camera direction
**	(Euclidean distance will give fisheye effect!).
**	Calculate height of line to draw on screen.
**	Calculate lowest and highest pixel to fill in current stripe.
**	1 subtracted from texture number so that texture 0 can be used.
*/

static void	raycasting_4(t_params *p)
{
	if (p->side == 0)
		p->perpwalldist = (p->mapx - p->posx + (1 - p->stepx) / 2) / p->raydirx;
	else
		p->perpwalldist = (p->mapy - p->posy + (1 - p->stepy) / 2) / p->raydiry;
	p->lineheight = (int)(p->win_height / p->perpwalldist);
	p->drawstart = -p->lineheight / 2 + p->win_height / 2;
	if (p->drawstart < 0)
		p->drawstart = 0;
	p->drawend = p->lineheight / 2 + p->win_height / 2;
	if (p->drawend >= p->win_height)
		p->drawend = p->win_height - 1;
	p->texnum = p->map[p->mapx][p->mapy] - 1;
}

/*
**	perform DDA.
**	Jump to next map square, OR in x-direction, OR in y-direction.
**	Check if ray has hit a wall.
*/

static void	dda(t_params *p)
{
	p->hit = 0;
	while (p->hit == 0)
	{
		if (p->sidedistx < p->sidedisty)
		{
			p->sidedistx += p->deltadistx;
			p->mapx += p->stepx;
			p->side = 0;
		}
		else
		{
			p->sidedisty += p->deltadisty;
			p->mapy += p->stepy;
			p->side = 1;
		}
		if (p->map[p->mapx][p->mapy] > 0)
			p->hit = 1;
	}
}

/*
** 	calculate step and initial sideDist
*/

static void	raycasting_3(t_params *p)
{
	if (p->raydirx < 0)
	{
		p->stepx = -1;
		p->sidedistx = (p->posx - p->mapx) * p->deltadistx;
	}
	else
	{
		p->stepx = 1;
		p->sidedistx = (p->mapx + 1.0 - p->posx) * p->deltadistx;
	}
	if (p->raydiry < 0)
	{
		p->stepy = -1;
		p->sidedisty = (p->posy - p->mapy) * p->deltadisty;
	}
	else
	{
		p->stepy = 1;
		p->sidedisty = (p->mapy + 1.0 - p->posy) * p->deltadisty;
	}
}

/*
**	calculate ray position and direction, which box of the map we're in,
**	length of ray from one x or y-side to next x or y-side,
**	what direction to step in x or y-direction (either +1 or -1),
**	was there a wall hit?
*/

static void	raycasting_2(t_params *p, int x)
{
	p->camerax = 2 * x / (double)p->win_width - 1;
	p->raydirx = p->dirx + p->planex * p->camerax;
	p->raydiry = p->diry + p->planey * p->camerax;
	p->mapx = (int)p->posx;
	p->mapy = (int)p->posy;
	p->deltadistx = fabs((1 / p->raydirx));
	p->deltadisty = fabs((1 / p->raydiry));
	p->hit = 0;
}

/*
**	Performs raycasting
*/

int			raycasting(t_params *p)
{
	int x;
	int aux;

	x = 0;
	movement(p);
	p->img_ptr = mlx_new_image(p->mlx_ptr, p->win_width, p->win_height);
	p->img_data = mlx_get_data_addr(p->img_ptr, &p->bpp, &p->size_line,
		&p->endian);
	while (x < p->win_width)
	{
		raycasting_2(p, x);
		raycasting_3(p);
		dda(p);
		raycasting_4(p);
		textures_process(x, p);
		floor_casting(p, x);
		screen_draw(x, p);
		p->spr_buffer[x] = p->perpwalldist;
		x++;
	}
	sprite_casting(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	hud(p);
	return (0);
}
