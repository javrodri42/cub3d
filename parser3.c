/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:59:44 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/02 19:00:10 by javrodri         ###   ########.fr       */
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
		p->floor_color = translate_color(ft_atoi(p->char_red), ft_atoi(p->char_green), ft_atoi(p->char_blue));
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		parse_color(p, line);
		p->ceiling_color = translate_color(ft_atoi(p->char_red), ft_atoi(p->char_green), ft_atoi(p->char_blue));
	}
}

void	map_size(t_params *p, char **av)
{
	
	int		fd;
	char	*line;
	char	*aux;

	p->nb_lines = 0;	
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd,&line) > 0)
	{
		if (line[0] == '1')
		{
			p->lenline = ft_strlen_digits(line);
			p->nb_lines++;
			
		}
		free(line);
	}
	free(line);
}