/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:13:35 by javrodri          #+#    #+#             */
/*   Updated: 2020/02/20 17:40:02 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_reader_check(t_params *p, char *line)
{
	int i;
	
	i = 0;
	if (line[0] != 'R' || line[1] != ' ')
		//printf("%c\n", line[0]);
		close_failure("Error\nNo resolution defined 1\n");
	if (!(p->win_width = ft_atoi(line + 2)))
		close_failure("Error\nNo resolution defined 2\n");
	line += ft_strlen(ft_itoa(p->win_width)) + 3;
	if (!(p->win_height = ft_atoi(line)))
		close_failure("Error\nNo resolution defined 3\n");
	//get_next_line(fd, &line);
	if (ft_strlen(line) > 0)
		close_failure("Error\nNo correct file format\n");
}

void		map_reader(t_params *p, char *map)
{
	int		fd;
	char	*line;
	int		i;
	if ((fd = open(map, O_RDONLY)) == -1)
		close_failure("Error\nCan not open file\n");
	//map_reader_check(p, line);
	while (get_next_line(fd, &line))
	{
		i = -1;
		//line = ft_delete_spaces(line, i);
		if (!p->lenline)
			p->lenline = ft_strlen(line);
		while (line[++i])
			p->map[p->nb_lines][i] = line[i] - '0';
		p->nb_lines++;
	}
	i = -1;
	while (++i < p->lenline)
		p->map[p->nb_lines][i] = line[i] - '0';
	p->nb_lines++;
	free(line);
	//map_position(p);
}
