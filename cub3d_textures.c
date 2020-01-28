/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:45:32 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/13 17:04:02 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		screen_draw(int x, t_params *p)
{
	while (p->drawstart <= p->drawend)
	{
		p->tex_y = abs((((p->drawstart * 256 - p->win_height * 128 +
					p->lineheight * 128) * 64) / p->lineheight) / 256);
		ft_memcpy(p->img_data + 4 * p->win_width * p->drawstart + x * 4,
				&p->tex[p->tex_id].data[p->tex_y % p->tex_height *
				p->tex[p->tex_id].sizeline + p->tex_x % p->tex_width *
				p->tex[p->tex_id].bpp / 8], sizeof(int));
		p->drawstart++;
	}
}

/*
**	calculate value of wallx
**	where exactly the wall was hit
*/

void		textures_process(int x, t_params *p)
{
	p->tex_id = p->map[p->mapx][p->mapy] + p->tex_side;
	if (p->side == 0)
		p->wallx = p->posy + p->perpwalldist * p->raydiry;
	else
		p->wallx = p->posx + p->perpwalldist * p->raydirx;
	p->wallx -= floor(p->wallx);
	p->tex_x = abs((int)(p->wallx * (double)(64)));
}

/*
** Load sprites position
*/

static void	sprites_pos(t_params *p)
{
	p->sprite[1].tex = p->tex[8];
	p->sprite[2].x = 7.5;
	p->sprite[2].y = 7.5;
	p->sprite[2].tex = p->tex[10];
	p->sprite[3].x = 5;
	p->sprite[3].y = 5;
	p->sprite[3].tex = p->tex[10];
}

/*
**	Load textures images from files in ./textures folder
*/

static void	textures_2(t_params *p)
{
	p->tex[5].img = mlx_xpm_file_to_image(p->mlx_ptr, "sprites/pillar.xpm",
			&p->tex_width, &p->tex_height);
	p->tex[5].data = mlx_get_data_addr(p->tex[5].img, &p->tex[5].bpp,
			&p->tex[5].sizeline, &p->tex[5].endian);
	p->tex[6].img = mlx_xpm_file_to_image(p->mlx_ptr, "sprites/barrel.xpm",
			&p->tex_width, &p->tex_height);
	p->tex[6].data = mlx_get_data_addr(p->tex[6].img, &p->tex[6].bpp,
			&p->tex[6].sizeline, &p->tex[6].endian);
	p->tex[7].img = mlx_xpm_file_to_image(p->mlx_ptr, "sprites/light.xpm",
			&p->tex_width, &p->tex_height);
	p->tex[7].data = mlx_get_data_addr(p->tex[7].img, &p->tex[7].bpp,
			&p->tex[7].sizeline, &p->tex[7].endian);
	p->tex[8].img = mlx_xpm_file_to_image(p->mlx_ptr, "sprites/ghost.xpm",
			&p->tex_width, &p->tex_height);
	p->tex[8].data = mlx_get_data_addr(p->tex[8].img, &p->tex[8].bpp,
			&p->tex[8].sizeline, &p->tex[8].endian);
	p->tex[9].img = mlx_xpm_file_to_image(p->mlx_ptr, "sprites/ghostred.xpm",
			&p->tex_width, &p->tex_height);
	p->tex[9].data = mlx_get_data_addr(p->tex[9].img, &p->tex[9].bpp,
			&p->tex[9].sizeline, &p->tex[9].endian);
	sprites_pos(p);
}

void		textures_from_file(t_params *p)
{
	p->tex[10].img = mlx_xpm_file_to_image(p->mlx_ptr, "sprites/diamond.xpm",
			&p->tex_width, &p->tex_height);
	p->tex[10].data = mlx_get_data_addr(p->tex[10].img, &p->tex[10].bpp,
			&p->tex[10].sizeline, &p->tex[10].endian);
	p->tex[1].img = mlx_xpm_file_to_image(p->mlx_ptr, "textures/stone.xpm",
			&p->tex_width, &p->tex_height);
	p->tex[1].data = mlx_get_data_addr(p->tex[1].img, &p->tex[1].bpp,
			&p->tex[1].sizeline, &p->tex[1].endian);
	p->tex[2].img = mlx_xpm_file_to_image(p->mlx_ptr, "textures/mossy.xpm",
			&p->tex_width, &p->tex_height);
	p->tex[2].data = mlx_get_data_addr(p->tex[2].img, &p->tex[2].bpp,
			&p->tex[2].sizeline, &p->tex[2].endian);
	p->tex[3].img = mlx_xpm_file_to_image(p->mlx_ptr, "textures/redbrick.xpm",
			&p->tex_width, &p->tex_height);
	p->tex[3].data = mlx_get_data_addr(p->tex[3].img, &p->tex[3].bpp,
			&p->tex[3].sizeline, &p->tex[3].endian);
	p->tex[4].img = mlx_xpm_file_to_image(p->mlx_ptr, "textures/wood.xpm",
			&p->tex_width, &p->tex_height);
	p->tex[4].data = mlx_get_data_addr(p->tex[4].img, &p->tex[4].bpp,
			&p->tex[4].sizeline, &p->tex[4].endian);
	textures_2(p);
}
