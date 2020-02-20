/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:35:38 by tglandai          #+#    #+#             */
/*   Updated: 2020/02/20 19:39:14 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_error_check(t_params *p)
{
	int i;
	if (p->nb_lines < 3 || p->lenline < 3)
		close_failure("Error\nThis map is too small\n");
	if (!p->initial_pos)
		close_failure("Error\nThere isn't an initial position\n");
	if (p->initial_pos > 1)
		close_failure("Error\nThere's more than one initial position\n");
	i = -1;
	while (++i < p->lenline)
		if (p->map[0][i] == 0 || p->map[p->nb_lines - 1][i] == 0)
			close_failure("Error\nThis map isn't completely walled\n");
	i = -1;
	while (++i < p->nb_lines)
		if (p->map[i][0] == 0 || p->map[i][p->lenline - 1] == 0)
			close_failure("Error\nThis map isn't completely walled\n");
}

void	map_config_reader(t_params *p, int fd)
{
	char *line;

	get_next_line(fd, &line);
	if (line[0] != 'R' || line[1] != ' ')
		close_failure("Error\nNo resolution defined\n");
	if (!(p->win_width = ft_atoi(line + 2)))
		close_failure("Error\nNo resolution defined\n");
	line += ft_strlen(ft_itoa(p->win_width)) + 3;
	if (!(p->win_height = ft_atoi(line)))
		close_failure("Error\nNo resolution defined\n");
	if (p->win_height > 720 || p->win_width > 1080)
	{
		p->win_height = 1080;
		p->win_width = 720;
	}
	get_next_line(fd, &line);
	if (ft_strlen(line) > 0)
		close_failure("Error\nNo correct file format\n");
	printf("p->win_height: %i\n", p->win_height);
	printf("p->win_width: %i\n", p->win_width);

}

int		check_map(char *buff, t_params *p)
{
	int		i;
	int		len;
	char	*temp;

	len = 0;
	i = 0;
	if(!(temp = malloc(ft_strlen(buff) + 1)))
		close_failure("Error\nUndefined\n");
	temp = buff;

	p->lenline = ft_linelen(temp);
	p->nb_lines = ft_countlines(temp);
	printf("Nb_lines: %i\n", p->nb_lines);
	printf("Lenline: %i\n", p->lenline);
	return (1);
}

int		parser2(t_params *p, char **av)
{
	int		i;
	int		j;
	int		k;
	int		fd;
	char	*str;

	i = 0;
	fd = open(av[1], O_RDONLY);
	//map_config_reader(p, fd);
	while (get_next_line(fd, &str) > 0)
	{
		j = -1;
		k = 0;
		if (!(p->map[i] = (int *)malloc(sizeof(int) * p->lenline)))
			return (0);
		while (++j < p->lenline)
		{
			if (str[k] == ' ')
				k++;
			if (str[k] == '1')
			{
				p->map[i][j] = (str[k]) - '0';
				printf("%i", p->map[i][j]);
				k++;
			}
		}
		i++;
		printf("\n");
		//printf("[%s]\n", str);
		free(str);

	}
	free(str);

	return (1);
}

int		check_side(t_params *p)
{
	int		i;

	i = 0;
	while (i < p->lenline)
	{
		if (p->map[0][i] == 0)
			write(1, "\n", 1);
			return (0);
		if (p->map[p->nb_lines - 1][i] == 0)
			write(1, "\n", 1);
			return (0);
		i++;
	}
	i = 0;
	while (i < p->nb_lines)
	{
		if (p->map[i][0] == 0)
			write(1, "\n", 1);
			return (0);
		if (p->map[i][p->lenline - 1] == 0)
			write(1, "\n", 1);
			return (0);
		i++;
	}
	write(1, "\n", 1);
	return (1);
}

int		map_parser(t_params *p, char **av)
{
	int		fd;
	char	*buff;
	int		i;

	i = 0;
	buff = ft_strnew(65536);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || (read(fd, buff, 65536)) < 1)
		close_failure("Error\nNo such file\n");
	if (!(check_map(buff, p)))
		close_failure("Error\nCheck map\n");
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		if (buff[i] == ' ')
			p->lenline--;
		i++;
	}
	ft_strdel(&buff);
	p->map_name = av[1];
	close(fd);
	if (!(p->map = (int **)malloc(sizeof(int *) * p->nb_lines + 1)) || !(parser2(p, av)))
		return (0);
	//map_position(p);
	printf("Nb_lines: %i\n", p->nb_lines);
	printf("Lenline: %i\n", p->lenline);

	//map_reader_check(p, fd);
	//map_error_check(p);
	if (check_side(p))
			close_failure("Error\nCheck side failure\n");
	return (1);
}