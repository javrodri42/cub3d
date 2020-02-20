/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:43:29 by javrodri          #+#    #+#             */
/*   Updated: 2020/02/12 10:16:38 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *game, t_window *w, t_pos *start, t_pos *end)
{
	int			i;
	int			j;
	int			color;

	i = 0;
	while (i < game->config.rows)
	{
		j = 0;
		while (j < game->config.columns)
		{
			if ((color = case_color(game, j, i)) >= 0)
			{
				set_pos(start,
					w->size.x - (game->config.columns * 5) - 5 + (j * 5),
					w->size.y - (game->config.rows * 5) - 5 + (i * 5));
				set_pos(end,
					w->size.x - (game->config.columns * 5) + (j * 5),
					w->size.y - (game->config.rows * 5) + (i * 5));
				draw_rectangle(w, start, end, color);
			}
			j++;
		}
		i++;
	}
}