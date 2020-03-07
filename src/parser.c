/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:35:38 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/07 13:38:31 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parser2(t_params *p, char **av)
{
	int		j;
	int		k;
	int		fd;
	char	*line;
	char	*aux;

	p->i = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		p->lenline = ft_strlen(line);
		j = 0;
		if (line[0] == 'R' || line[0] == 'S' || line[0] == 'N' ||
			line[0] == 'W' || line[0] == 'E' || line[0] == 'F' ||
			line[0] == 'C' || line[0] == 'T')
			parse_map_config(p, line);
		else if (line[j] == ' ' || line[j] == '1')
			matrix_map(line, p);
		free(line);
	}
	free(line);
	return (1);
}

void	copy_map(char *line, t_params *p)
{
	int		j;
	int		k;

	j = -1;
	k = 0;
	while (++j < p->lenline)
	{
		if (line[k] == ' ')
			p->map[p->i][j] = (line[k]);
		else
			p->map[p->i][j] = (line[k]) - 48;
		k++;
	}
	p->map[p->i][j] = '\n';
	j++;
	p->i++;
}

int		map_parser(t_params *p, char **av)
{
	int		fd;
	char	*buff;
	int		i;

	i = 0;
	if (!(fd = open(av[1], O_RDONLY)))
		close_failure("ERROR\n No such file");
	p->map_name = av[1];
	close(fd);
	p->count_map_config = 0;
	if (!(p->map = (int **)malloc(sizeof(int *) * 50)) || !(parser2(p, av)))
		return (0);
	map_config_check(p);
	map_position(p);
	map_error_check(p);
	check_extrm_walled(p);
	check_walled(p);
	return (1);
}

void	matrix_map(char *line, t_params *p)
{
	p->nb_lines++;
	print_map(p, line);
	if (!(p->map[p->i] = (int *)malloc(sizeof(int) * (p->lenline) + 1)))
		close_failure("ERROR\n");
	copy_map(line, p);
}
