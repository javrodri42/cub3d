/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:35:38 by tglandai          #+#    #+#             */
/*   Updated: 2020/02/27 16:54:49 by javrodri         ###   ########.fr       */
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

int		check_map(char *buff, t_params *p)
{
	int		i;
	int		len;
	char 	*temp;


	len = 0;
	i = 0;

	
	/*p->lenline = ft_linelen(buff);
	p->nb_lines = ft_countlines(buff);
	p->lenline = 24;
	p->nb_lines = 24;*/
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
}

int		translate_color(int r, int g, int b)
{
	int	rgb;
	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 16) + b;
	return (rgb);
}

void		parse_color(t_params *p, char *line)
{
	int i;
	int j;
	
	i = 2;
	j = 0;
	while (line[i] != ',')
	{
		p->char_red[j] = line[i];
		i++;
		j++;
	}
	i++;
	j = 0;
	while (line[i] != ',')
	{
		p->char_green[j] = line[i];
		i++;
		j++;
	}
	i++;
	j = 0;
	while (line[i])
	{
		p->char_blue[j] = line[i];
		i++;
		j++;
	}
}

char 	*parse_tex(char *line)
{
	int i;

	i = 0;
	while (line[i] == 'R' || line[i] == 'S' || line[i] == 'N' || line[i] == 'W' || 
			line[i] == 'E' || line[i] == 'F' || line[i] == 'C' || line[i] == ' ' ||
			line[i] == 'O' || line[i] == 'A' || line[i] == '.' || line[i] == '/' || line[i] == 'T')
			i++;
	return(&line[i]);
}

 void	parse_map_config(t_params *p, char *line)
{

	if (line[0] == 'R' && line[1] == ' ')
		parse_resolution(p, line);
	else if (line[0] == 'S' && line[1] == 'O')
		p->so_tex = ft_strdup(parse_tex(line));
	else if (line[0] == 'N' && line[1] == 'O')
		p->no_tex = ft_strdup(parse_tex(line));
	else if (line[0] == 'W' && line[1] == 'E')
		p->we_tex = ft_strdup(parse_tex(line));
	else if (line[0] == 'E' && line[1] == 'A')
		p->ea_tex = ft_strdup(parse_tex(line));
	else if (line[0] == 'S')
		p->path_sprite = ft_strdup(parse_tex(line));
	else if (line[0] == 'F')
	{
		parse_color(p, line);
		p->floor_color = translate_color(ft_atoi(p->char_red), ft_atoi(p->char_green), ft_atoi(p->char_blue));
	}
	else if (line[0] == 'C')
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
			line[0] == 'E' || line[0] == 'F' || line[0] == 'C'|| line[0] == 'T')
			parse_map_config(p, line);
		if (line[0] == '1')
		{
			print_map(p, line);
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
	map_size(p, av);
	if (!(check_map(buff, p)))
		close_failure("Error\nCheck map error\n");
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
