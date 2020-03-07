/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:58:50 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/07 14:06:37 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_error_check(t_params *p)
{
	int i;

	if (p->nb_lines < 3 || p->lenline < 3)
		close_failure("Error\nThis map is too small\n");
	if (p->initial_pos == 0)
		close_failure("Error\nThere isn't an initial position\n");
	if (p->initial_pos > 1)
		close_failure("Error\nThere's more than one initial position\n");
}

void	parse_resolution(t_params *p, char *line)
{
	int i;

	i = 0;

	if (p->win_width || p->win_height)
		close_failure("Error\nMany resolution data\n");	
	if (line[i] == 'R' && line[++i] == ' ')
	{
		while (line[i] == ' ')
			i++;
		p->win_width = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
		p->win_height = ft_atoi(&line[i]);
	}
	if (p->win_height > 720 || p->win_width > 1080)
	{
		p->win_width = 1080;
		p->win_height = 720;
	}
}

void	map_config_check(t_params *p)
{
	if (!(p->so_tex))
		close_failure("\nError\nNo SO path in the .cub \n");
	if (!(p->no_tex))
		close_failure("\nError\nNo NO path in the .cub \n");
	if (!(p->ea_tex))
		close_failure("\nError\nNo EA path in the .cub \n");
	if (!(p->we_tex))
		close_failure("\nError\nNo WE path in the .cub \n");
	if (!(p->path_sprite))
		close_failure("\nError\nNo SPRITE path in the .cub \n");
	if (!(p->floor_color))
		close_failure("\nError\nNo FLOOR COLOR in the .cub \n");
	if (!(p->ceiling_color))
		close_failure("\nError\nNo CEILING COLOR in the .cub \n");
	if (!(p->win_width || p->win_height))
		close_failure("\nError\nNo RESOLUTION DATA in the .cub \n");
		

}

void	parse_color(t_params *p, char *line)
{
	int i;
	int j;

	i = 2;
	j = 0;
	while (line[i] != ',')
		p->char_red[j++] = line[i++];
	i++;
	j = 0;
	while (line[i] != ',')
		p->char_green[j++] = line[i++];
	i++;
	j = 0;
	while (line[i])
		p->char_blue[j++] = line[i++];
}

char	*parse_tex(char *line)
{
	int i;

	i = 0;
	while (line[i] == 'R' || line[i] == 'S' || line[i] == 'N' ||
			line[i] == 'W' || line[i] == 'E' || line[i] == 'F' ||
			line[i] == 'C' || line[i] == ' ' || line[i] == 'O' ||
			line[i] == 'A' || line[i] == '.' || line[i] == '/')
		i++;
	return (&line[i]);
}
