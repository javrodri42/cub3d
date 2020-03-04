/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:58:50 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/04 08:28:17 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_error_check(t_params *p)
{
	int i;

	if (p->nb_lines < 3 || p->lenline < 3)
		close_failure("Error\nThis map is too small\n");
	if (!p->initial_pos)
		close_failure("Error\nThere isn't an initial position\n");
	if (p->initial_pos > 1)
		close_failure("Error\nThere's more than one initial position\n");
}

void	parse_resolution(t_params *p, char *line)
{
	if (!(p->win_width = ft_atoi(line + 2)))
		close_failure("Error\nNo resolution defined 2\n");
	line += ft_strlen(ft_itoa(p->win_width)) + 3;
	if (!(p->win_height = ft_atoi(line)))
		close_failure("Error\nNo resolution defined 3\n");
}

int		translate_color(int r, int g, int b)
{
	int	rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 16) + b;
	return (rgb);
}

void	parse_color(t_params *p, char *line)
{
	int i;
	int j;

	i = 2;
	j = 0;
	while (line[i] != ',')
		p->char_red[j++] = line[i]++;
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
