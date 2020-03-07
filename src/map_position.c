/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:46:47 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/06 19:20:56 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	orientation_n(t_params *p, int i, int j)
{
	p->x_pos = i + 0.5;
	p->y_pos = j + 0.5;
	p->x_dir = -1;
	p->y_dir = 0;
	p->x_plane = 0;
	p->y_plane = 0.66;
}

void	orientation_s(t_params *p, int i, int j)
{
	p->x_pos = i + 0.5;
	p->y_pos = j + 0.5;
	p->x_dir = 1;
	p->x_plane = 0;
	p->y_plane = -0.66;
}

void	orientation_e(t_params *p, int i, int j)
{
	p->x_pos = i + 0.5;
	p->y_pos = j + 0.5;
	p->x_dir = 0;
	p->y_dir = 1;
	p->x_plane = 0.66;
	p->y_plane = 0;
}

void	orientation_w(t_params *p, int i, int j)
{
	p->x_pos = i + 0.5;
	p->y_pos = j + 0.5;
	p->x_dir = 0;
	p->y_dir = -1;
	p->x_plane = -0.66;
	p->y_plane = 0;
}

void	map_position(t_params *p)
{
	int i;
	int j;

	p->initial_pos = 0;
	i = -1;
	while (++i < p->nb_lines)
	{
		j = -1;
		while (++j < p->lenline)
		{
			if (p->map[i][j] == 'N' - '0' || p->map[i][j] == 'S' - '0' ||
				p->map[i][j] == 'E' - '0' || p->map[i][j] == 'W' - '0')
				check_orientations(p, i, j);
		}
	}
}
