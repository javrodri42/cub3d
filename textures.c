/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:01:12 by javrodri          #+#    #+#             */
/*   Updated: 2020/01/28 19:43:01 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    load_textures(t_params *p)
{
        p->tex[1].img = mlx_xpm_file_to_image(p->mlx_ptr, "textures/barrel.xpm", 
                        &p->tex_width, &p->tex_height);
        p->tex[1].data = mlx_get_data_addr(p->tex[1].img, &p->tex[1].bpp,
			&p->tex[1].sizeline, &p->tex[1].endian);
        p->tex[2].img = mlx_xpm_file_to_image(p->mlx_ptr, "textures/barrel.xpm", 
                        &p->tex_width, &p->tex_height);
        p->tex[2].data = mlx_get_data_addr(p->tex[2].img, &p->tex[2].bpp,
			&p->tex[2].sizeline, &p->tex[2].endian);
        p->tex[3].img = mlx_xpm_file_to_image(p->mlx_ptr, "textures/barrel.xpm", 
                        &p->tex_width, &p->tex_height);
        p->tex[3].data = mlx_get_data_addr(p->tex[3].img, &p->tex[3].bpp,
			&p->tex[3].sizeline, &p->tex[3].endian);
}