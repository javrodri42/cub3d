/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:59:44 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/07 14:07:06 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map_config(t_params *p, char *line)
{
	p->count_map_config++;
	if (p->count_map_config > 8)
		close_failure("\nError\nThere are more settings than allowed\n");
	if (line[0] == 'R' && line[1] == ' ')
		parse_resolution(p, line);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		p->so_tex = ft_strdup(parse_tex(line));
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		p->no_tex = ft_strdup(parse_tex(line));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		p->we_tex = ft_strdup(parse_tex(line));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		p->ea_tex = ft_strdup(parse_tex(line));
	else if (line[0] == 'S' && line[1] == ' ')
		p->path_sprite = ft_strdup(parse_tex(line));
	parse_map_color(p, line);
}

void	parse_map_color(t_params *p, char *line)
{
	if (line[0] == 'F' && line[1] == ' ')
	{
		parse_color(p, line);
		p->floor_color = translate_color(ft_atoi(p->char_red),
			ft_atoi(p->char_green), ft_atoi(p->char_blue));
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		parse_color(p, line);
		p->ceiling_color = translate_color(ft_atoi(p->char_red),
			ft_atoi(p->char_green), ft_atoi(p->char_blue));
	}
}

void	check_extrm_walled(t_params *p)
{
	int j;

	j = 0;
	while (p->map[0][j] != '\n')
	{
		if (p->map[0][j] == 0)
			close_failure("\nError\nThe map is not valid\n");
		j++;
	}
	j = 0;
	while (p->map[p->nb_lines - 1][j] != '\n')
	{
		if (p->map[p->nb_lines - 1][j] == 0)
			close_failure("\nError\nThe map is not valid\n");
		j++;
	}
}

void	check_walled(t_params *p)
{
	int i;
	int j;

	i = 0;
	while (p->map[i] != '\0')
	{
		j = 0;
		while (p->map[i][j++] != '\n')
		{
			if (p->map[i][j] == 0 || p->map[i][j] == 2)
			{
				if (ft_isspace(p->map[i - 1][j - 1])
				|| ft_isspace(p->map[i - 1][j])
				|| ft_isspace(p->map[i - 1][j + 1])
				|| ft_isspace(p->map[i][j - 1])
				|| ft_isspace(p->map[i][j + 1])
				|| ft_isspace(p->map[i + 1][j - 1])
				|| ft_isspace(p->map[i + 1][j])
				|| ft_isspace(p->map[i + 1][j + 1]))
					close_failure("\nError\nThe map isnt completly walled\n");
			}
		}
		i++;
	}
}

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}
