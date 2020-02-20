/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 14:44:53 by tglandai          #+#    #+#             */
/*   Updated: 2020/02/20 18:21:05 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures(t_params *p)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	p->tex[0].img = mlx_xpm_file_to_image(p->mlx, "textures/wood.xpm", &a, &b);
	p->tex[0].data = mlx_get_data_addr(p->tex[0].img, &p->tex[0].bpp,
			&p->tex[0].sizeline, &p->tex[0].endian);
	p->tex[1].img = mlx_xpm_file_to_image(p->mlx, "textures/pixel-bricks.xpm", &a, &b);
	p->tex[1].data = mlx_get_data_addr(p->tex[1].img, &p->tex[1].bpp,
			&p->tex[1].sizeline, &p->tex[1].endian);
	p->tex[2].img = mlx_xpm_file_to_image(p->mlx, "textures/mossy.xpm", &a, &b);
	p->tex[2].data = mlx_get_data_addr(p->tex[2].img, &p->tex[2].bpp,
			&p->tex[2].sizeline, &p->tex[2].endian);
	p->tex[3].img = mlx_xpm_file_to_image(p->mlx,
			"textures/redbrick.xpm", &a, &b);
	p->tex[3].data = mlx_get_data_addr(p->tex[3].img, &p->tex[3].bpp,
			&p->tex[3].sizeline, &p->tex[3].endian);
	p->tex[4].img = mlx_xpm_file_to_image(p->mlx, "textures/wood.xpm", &a, &b);
	p->tex[4].data = mlx_get_data_addr(p->tex[4].img, &p->tex[4].bpp,
			&p->tex[4].sizeline, &p->tex[4].endian);
	if(!(load_textures2(p, a, b)))
		return(0);
	return(1);
}

int	load_textures2(t_params *p, int a, int b)
{
	p->tex[5].img = mlx_xpm_file_to_image(p->mlx, "textures/sand.xpm", &a, &b);
	p->tex[5].data = mlx_get_data_addr(p->tex[5].img, &p->tex[5].bpp,
			&p->tex[5].sizeline, &p->tex[5].endian);
	p->tex[7].img = mlx_xpm_file_to_image(p->mlx, "textures/pillar.xpm", &a, &b);
	p->tex[7].data = mlx_get_data_addr(p->tex[7].img, &p->tex[7].bpp,
			&p->tex[7].sizeline, &p->tex[7].endian);
	a = 512;
	b = 512;
	p->tex[6].img = mlx_xpm_file_to_image(p->mlx, "textures/pix_art_sky.xpm", &a, &b);
	p->tex[6].data = mlx_get_data_addr(p->tex[6].img, &p->tex[6].bpp,
			&p->tex[6].sizeline, &p->tex[6].endian);
	return(1);
}
