/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:05:59 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/07 13:02:26 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(t_params *p)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	if (!(p->tex[0].img = mlx_xpm_file_to_image(p->mlx, p->so_tex, &a, &b)))
		close_failure("\nError\nThe SO path is incorrect\n");
	if (!(p->tex[0].data = mlx_get_data_addr(p->tex[0].img, &p->tex[0].bpp,
			&p->tex[0].sizeline, &p->tex[0].endian)))
		close_failure("\nError\nThe SO path is incorrect\n");
	if (!(p->tex[1].img = mlx_xpm_file_to_image(p->mlx, p->no_tex, &a, &b)))
		close_failure("\nError\nThe NO path is incorrect\n");
	if (!(p->tex[1].data = mlx_get_data_addr(p->tex[1].img, &p->tex[1].bpp,
			&p->tex[1].sizeline, &p->tex[1].endian)))
		close_failure("\nError\nThe NO path is incorrect\n");
	if (!(p->tex[2].img = mlx_xpm_file_to_image(p->mlx, p->ea_tex, &a, &b)))
		close_failure("\nError\nThe EA path is incorrect\n");
	if (!(p->tex[2].data = mlx_get_data_addr(p->tex[2].img, &p->tex[2].bpp,
			&p->tex[2].sizeline, &p->tex[2].endian)))
		close_failure("\nError\nThe EA path is incorrect\n");
	if (!(p->tex[3].img = mlx_xpm_file_to_image(p->mlx,
			p->we_tex, &a, &b)))
		close_failure("\nError\nThe WE path is incorrect\n");
	load_textures2(p, a, b);
}

void	load_textures2(t_params *p, int a, int b)
{
	if (!(p->tex[3].data = mlx_get_data_addr(p->tex[3].img, &p->tex[3].bpp,
			&p->tex[3].sizeline, &p->tex[3].endian)))
		close_failure("\nError\nThe WE path is incorrect\n");
	if (!(p->tex[4].img = mlx_xpm_file_to_image(p->mlx, p->ea_tex, &a, &b)))
		close_failure("\nError\nThe path is incorrect\n");
	if (!(p->tex[4].data = mlx_get_data_addr(p->tex[4].img, &p->tex[4].bpp,
			&p->tex[4].sizeline, &p->tex[4].endian)))
		close_failure("\nError\nThe path is incorrect\n");
	p->tex[5].img = mlx_xpm_file_to_image(p->mlx, "textures/sand.xpm",
			&a, &b);
	p->tex[5].data = mlx_get_data_addr(p->tex[5].img, &p->tex[5].bpp,
			&p->tex[5].sizeline, &p->tex[5].endian);
	a = 512;
	b = 512;
	p->tex[6].img = mlx_xpm_file_to_image(p->mlx, "textures/pix_art_sky.xpm",
			&a, &b);
	p->tex[6].data = mlx_get_data_addr(p->tex[6].img, &p->tex[6].bpp,
			&p->tex[6].sizeline, &p->tex[6].endian);
	if (!(p->tex[20].img = mlx_xpm_file_to_image(p->mlx, p->path_sprite,
			&a, &b)))
		close_failure("\nError\nThe SPRITE path is incorrect\n");
	if (!(p->tex[20].data = mlx_get_data_addr(p->tex[20].img, &p->tex[20].bpp,
			&p->tex[20].sizeline, &p->tex[20].endian)))
		close_failure("\nError\nThe SPRITE path is incorrect\n");
}

void	orientation_tex_walls(t_params *p)
{
	if (p->side == 0 && p->x_raydir > 0)
		p->id = 0;
	else if (p->side == 0 && p->x_raydir < 0)
		p->id = 1;
	else if (p->side == 1 && p->y_raydir > 0)
		p->id = 4;
	else if (p->side == 1 && p->y_raydir < 0)
		p->id = 3;
}
