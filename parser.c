/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:35:38 by tglandai          #+#    #+#             */
/*   Updated: 2020/02/25 18:48:30 by javrodri         ###   ########.fr       */
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
}
/*
static void	map_reader_2(t_params *p, int fd)
{
	char *line;
	
	get_next_line(fd, &line);
	if (line[0] != 'R' || line[1] != ' ')
		close_failure("Error\nNo resolution defined 1\n");
	if (!(p->win_width = ft_atoi(line + 2)))
		close_failure("Error\nNo resolution defined 2\n");
	line += ft_strlen(ft_itoa(p->win_width)) + 3;
	if (!(p->win_height = ft_atoi(line)))
		close_failure("Error\nNo resolution defined 3\n");
	
	free(line);
	printf("Win_height:%i\n", p->win_height);
	printf("Win_width:%i\n", p->win_width);

}*/

int		check_map(char *buff, t_params *p)
{
	int		i;
	int		len;
	char 	*temp;


	len = 0;
	i = 0;

	
	p->lenline = ft_linelen(buff);
	p->nb_lines = ft_countlines(buff);
	p->lenline = 24;
	p->nb_lines = 24;
	printf("Lenline:%i\n", p->lenline);
	printf("NB_line:%i\n", p->nb_lines);

	return (1);
}

void	parse_resolution(t_params *p, char *line)
{
	if (!(p->win_width = ft_atoi(line + 2)))
		close_failure("Error\nNo resolution defined 2\n");
	line += ft_strlen(ft_itoa(p->win_width)) + 3;
	if (!(p->win_height = ft_atoi(line)))
		close_failure("Error\nNo resolution defined 3\n");
	//printf("Win_width:%i\n", p->win_width);
	//printf("Win_height:%i\n", p->win_height);
}

void	south_texture(t_params *p, char *line)
{
	int i;

	i = 0;
	if (line[i++] == '.')
	{
------------------------------------------>>>>>>>>>>		ft_strcmp("./textures", line);
	}	
} 

 void	parse_map_config(t_params *p, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		parse_resolution(p, line);
	else if (line[0] == 'S')
		south_texture(p, line);
	/*else if (line[0] == 'N' && line[1] == 'O')
		north_texture(p, line);
	else if (line[0] == 'W' && line[1] == 'E')
		west_texture(p, line);
	else if (line[0] == 'E' && line[1] == 'A')
		east_texture(p, line);
	else if (line[0] == 'F')
		floor_color(p, line);
	else if (line[0] == 'C')
		sky_color(p, line);*/	
}


int		parser2(t_params *p, char **av)
{
	int		i;
	int		j;
	int		k;
	int		fd;
	char	*line;
	char	*aux;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd,&line) > 0)
	{
		j = -1;
		k = 0;
		if (line[0] == 'R' || line[0] == 'S' || line[0] == 'N' || line[0] == 'W' || 
			line[0] == 'E' || line[0] == 'F' || line[0] == 'C')
			parse_map_config(p, line);
		if (line[0] == '1')
		{
			if (!(p->map[i] = (int *)malloc(sizeof(int) * (p->lenline) + 1)))
				return (0);
			{
				while (++j < p->lenline)
				{
					if (line[k] == ' ')
						k++;
					p->map[i][j] = (line[k]) - '0';
					k++;
				}
				j++;
				p->map[i][j] = '\n';
				i++;
				printf("%s\n", line);
			}
		}
		free(line);
	}
	free(line);
	return (1);
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
	//map_reader_2(p,fd);
	if (!(check_map(buff, p)))
		close_failure("Error\nCheck map error\n");
	free(buff);
	p->map_name = av[1];
	close(fd);
	while (get_next_line(fd, &buff) > 0)
	{
		
	}
	if (!(p->map = (int **)malloc(sizeof(int *) * 50)) || !(parser2(p, av)))
		return (0);
	map_position(p);
	map_error_check(p);
	//print_map(p);
	if (!(check_side(p)))
			close_failure("Error\nCheck map side error\n");
	print_map(p);
	return (1);
}

void	print_map(t_params *p)
{
	int i;
	int j;
	
	i = 0;
	while (i < p->nb_lines)
	{
		j = 0;
		while(j < p->lenline)
		{
			write(1, &p->map[i][j], 1);
			j++;
		}
		i++;
	}
}