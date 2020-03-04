/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:35:38 by tglandai          #+#    #+#             */
/*   Updated: 2020/03/04 08:06:47 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parser2(t_params *p, char **av)
{
	int		k;
	int		fd;
	char	*line;
	char	*aux;

	p->i = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'R' || line[0] == 'S' || line[0] == 'N' ||
			line[0] == 'W' || line[0] == 'E' || line[0] == 'F' ||
			line[0] == 'C' || line[0] == 'T')
			parse_map_config(p, line);
		if (line[0] == '1')
		{
			print_map(p, line);
			if (!(p->map[p->i] = (int *)malloc(sizeof(int) * (p->lenline) + 1)))
				return (0);
			copy_map(line, p);
		}
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
			k++;
		p->map[p->i][j] = (line[k]) - '0';
		k++;
	}
	j++;
	p->map[p->i][j] = '\n';
	p->i++;
}

int		check_side(t_params *p)
{
	int	i;

	i = 0;
	while (i < p->lenline - 1)
	{
		if (p->map[0][i] == 0)
			return (0);
		if (p->map[p->nb_lines - 1][i] == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < p->nb_lines)
	{
		if (p->map[i][0] == 0)
			return (0);
		if (p->map[i][p->lenline - 1] == 0)
			return (0);
		i++;
	}
	return (1);
}

int		map_parser(t_params *p, char **av)
{
	int		fd;
	char	*buff;
	int		i;

	i = 0;
	buff = ft_strnew(65536);
	if (!(fd = open(av[1], O_RDONLY)))
		close_failure("ERROR\n No such file");
	map_size(p, av);
	free(buff);
	p->map_name = av[1];
	close(fd);
	if (!(p->map = (int **)malloc(sizeof(int *) * 50)) || !(parser2(p, av)))
		return (0);
	map_position(p);
	map_error_check(p);
	if (!(check_side(p)))
		close_failure("Error\nCheck map side error\n");
	return (1);
}

void	print_map(t_params *p, char *line)
{
	write(1, line, p->lenline);
	write(1, "\n", 1);
}
