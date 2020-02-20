/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:43:51 by javrodri          #+#    #+#             */
/*   Updated: 2020/02/14 13:45:02 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_sky(t_params *p)
{
	unsigned int	col;
	int				shift;
	int				i;
	int				j;

	i = 0;
	shift = (360 - s->dir.a) / 360 * 1024;
	while (i < s->win.x)
	{
		j = 0;
		if ((int)((double)i / ((s->win.y / 2) / 66)) + shift >= 1024)
			shift -= 1024;
		while (j < s->win.y / 2)
		{
			col = (int)((double)j / (s->win.y / 2) * 64) * 1024;
			col += (int)((double)i / ((s->win.y / 2) / 66)) + shift;
			s->img.adr[j * s->win.x + i] = s->tex.c[col];
			j++;
		}
		i++;
	}
}
