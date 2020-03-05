/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:59:44 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/05 18:49:41 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map_config(t_params *p, char *line)
{
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
	else if (line[0] == 'F' && line[1] == ' ')
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

void	check_walled(t_params *p)
{
	int i;
	int j;

	i = 0;
	while (p->map[i][j])
	{
		j = 0;
		while (p->map[i][j] != '\n')
		{
			printf("%i", p->map[i][j]);
			if (p->map[i][j] == 0 ||  p->map[i][j] == 2)
			{
				if (p->map[i - 1][j - 1] == 9 || 
					p->map[i - 1][j] == 9 ||
					p->map[i - 1][j + 1] == 9 ||
					p->map[i][j - 1] == 9 ||
					p->map[i][j + 1] == 9 ||
					p->map[i + 1][j - 1] == 9 ||
					p->map[i - 1][j] == 9 ||
					p->map[i + 1][j + 1] == 9) 
					close_failure("Error\nThe map isnt completly walled\n");
			}
			j++;
		}
		printf("\n");
		i++;
	write(1, "a", 1);
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