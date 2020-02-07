/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:35:38 by tglandai          #+#    #+#             */
/*   Updated: 2020/02/07 14:00:46 by javrodri         ###   ########.fr       */
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

int		check_map(char *buff, t_params *p)
{
	int		i;
	int		len;
	//int		fd;
	//char	*str;

	len = 0;
	i = 0;
	p->lenline = ft_linelen(buff);
	p->nb_lines = ft_countlines(buff);
	/*
	//fd = open(av[1], O_RDONLY);
	//while (get_next_line(fd, &str) > 0)
	if (p->nb_lines < 3 || p->lenline < 3)
		close_failure("Error\nThis map is too small\n");
	if (!p->initial_pos)
		printf("Initial pos: %i\n", p->initial_pos);
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
	while (buff[i] && buff[i] != '\0')
	{
		if ((buff[i] < 48 || buff[i] > 57) && buff[i] != ' ' && buff[i] != '\n')
			return (0);
		len++;
		
		if (buff[i] == '\n')
		{
			if (len - 1 != p->lenline)
				return (0);
			len = 0;
		}
		i++;
	}*/
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
			p->map[i][j] = (str[k]) - '0';
			k++;
		}
		i++;
		printf("%s\n", str);
		free(str);
	}
	return (1);
}

int		check_side(t_params *p)
{
	int		i;

	i = 0;
	while (i < p->lenline)
	{
		if (p->map[0][i] == 0)
			write(1, "p->map[0][%i]\n", i);
			return (0);
		if (p->map[p->nb_lines - 1][i] == 0)
			write(1, "p->map[1][%i]\n", i);
			return (0);
		i++;
	}
	i = 0;
	while (i < p->nb_lines)
	{
		if (p->map[i][0] == 0)
			write(1, "p->map[0][%i]\n", i);
			return (0);
		if (p->map[i][p->lenline - 1] == 0)
			write(1, "p->map[1][%i]\n", i);
			return (0);
		i++;
	}
	write(1, "p->map[0][%i]\n", i);
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
	{
		ft_putstr("wolf3d: ");
		ft_putstr(av[1]);
		ft_putstr(": No such file\n");
		return (0);
	}
	if (!(check_map(buff, p)))
	{
		ft_putstr("Map error (check_map)\n");
		return (0);
	}
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		if (buff[i] == ' ')
			p->lenline--;
		i++;
	}
	ft_strdel(&buff);
	p->map_name = av[1];
	close(fd);
	//parser2(p, av);
	if (!(p->map = (int **)malloc(sizeof(int *) * p->nb_lines)) || !(parser2(p, av)))
		return (0);
	map_position(p);
	map_error_check(p);
	if (check_side(p))
	{
		ft_putstr("Map error(check_side)\n");
		return (0);
	}
	//free(p->map);
	return (1);
}