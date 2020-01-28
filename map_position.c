/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:46:47 by javrodri          #+#    #+#             */
/*   Updated: 2020/01/28 11:39:08 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        orientation_n(t_params *p, int i, int j)
{
    p->posX = i;
    p->posY = j;
}

void        orientation_s(t_params *p, int i, int j)
{
    p->posX = i;
    p->posY = j;
}

void        orientation_e(t_params *p, int i, int j)
{
    p->posX = i;
    p->posY = j;
}

void        orientation_w(t_params *p, int i, int j)
{
    p->posX = i;
    p->posY = j;
}

void		map_position(t_params *p)
{
	int i;
	int j;

	i = -1;
	while (++i < p->map_height)
	{
		j = -1;
		while (++j < p->map_width)
		{
			if (p->map[i][j] == 'N' - '0' || p->map[i][j] == 'S' - '0' ||
				p->map[i][j] == 'E' - '0' || p->map[i][j] == 'W' - '0')
			{
				if (p->map[i][j] == 'N' - '0')
					orientation_n(p, i, j);
				else if (p->map[i][j] == 'S' - '0')
					orientation_s(p, i, j);
				else if (p->map[i][j] == 'E' - '0')
					orientation_e(p, i, j);
				else if (p->map[i][j] == 'W' - '0')
					orientation_w(p, i, j);
				p->map[i][j] = 0;
			}
		}
	}
}