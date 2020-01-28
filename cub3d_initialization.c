/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:45:32 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/28 19:18:53 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	params_init function initalizes necessary parameters from a t_params struct
*/
/*
void		params_init(t_params *p, char *map)
{
	p->win_width = 1640;
	p->win_height = 980;
	p->map_file = map;
	p->initial_pos = 0;
	p->map_width = 0;
	p->map_height = 0;
	p->tex_width = 64;
	p->tex_height = 64;
	p->posx = 22;
	p->posy = 11.5;
	p->movespeed = 0.06 * pow(1.0009, p->win_width);
	p->rotspeed = 0.06 * pow(1.0005, p->win_width);
	p->up = 0;
	p->down = 0;
	p->right_rot = 0;
	p->left_rot = 0;
	p->right_mov = 0;
	p->left_mov = 0;
	p->run = 0;
	p->ceiling_color = RGB_DARKBLUE;
	p->floor_color = RGB_DARKGRAY;
	p->tex_side = 0;
	p->sprite[1].x = 5.5;
	p->sprite[1].y = 5.5;
	p->life = 100;
}*/

/*
**	map_reader function uses get_next_line function to read map numbers
**	from a file with ".cub" extension.
**	it later transforms them from char to int in order to be compatible with
**	the rest of the algorythm.
**	This function obtains map_width and map_height, and stores all data
**	in a matrix called p->map (defined in a struct).
**	After this, it calls map_position and map_error_check.
*/

static void	map_reader_2(t_params *p, int fd)
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
	get_next_line(fd, &line);
	if (ft_strlen(line) > 0)
		close_failure("Error\nNo correct file format\n");
}

void		map_reader(t_params *p)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(p->map_file, O_RDONLY)) == -1)
		close_failure("Error\nmap file doesn't exist\n");
	map_reader_2(p, fd);
	while (get_next_line(fd, &line))
	{
		i = -1;
		line = ft_delete_spaces(line);
		if (!p->map_width)
			p->map_width = ft_strlen(line);
		while (line[++i])
			p->map[p->map_height][i] = line[i] - '0';
		p->map_height++;
	}
	i = -1;
	while (++i < p->map_width)
		p->map[p->map_height][i] = line[i] - '0';
	p->map_height++;
	free(line);
	map_position(p);
	map_error_check(p);
}

/*
**	map_position function locates the square in the grid where the player
**	will start, it places there the camera and the point of view depending
**	on the marker letter (N,S,E,W).
*/

void		map_position(t_params *p)
{
	int i;
	int j;

	i = -1;
	while (++i < p->map_height)
	{
		j = -1;
		while (++j < p->map_width)
		{
			if (p->map[i][j] == 'N' - '0' || p->map[i][j] == 'S' - '0' ||
				p->map[i][j] == 'E' - '0' || p->map[i][j] == 'W' - '0')
			{
				if (p->map[i][j] == 'N' - '0')
					orientation_n(p, i, j);
				else if (p->map[i][j] == 'S' - '0')
					orientation_s(p, i, j);
				else if (p->map[i][j] == 'E' - '0')
					orientation_e(p, i, j);
				else if (p->map[i][j] == 'W' - '0')
					orientation_w(p, i, j);
				p->map[i][j] = 0;
			}
		}
	}
}

/*
**	map_error_check function checks many different problems that may occur
**	if the map file is not well formated and exit the program if this happens.
*/

void		map_error_check(t_params *p)
{
	int i;

	if (p->map_height < 3 || p->map_width < 3)
		close_failure("Error\nThis map is too small\n");
	if (!p->initial_pos)
		close_failure("Error\nThere isn't an initial position\n");
	if (p->initial_pos > 1)
		close_failure("Error\nThere's more than one initial position\n");
	i = -1;
	while (++i < p->map_width)
		if (p->map[0][i] == 0 || p->map[p->map_height - 1][i] == 0)
			close_failure("Error\nThis map isn't completely walled\n");
	i = -1;
	while (++i < p->map_height)
		if (p->map[i][0] == 0 || p->map[i][p->map_width - 1] == 0)
			close_failure("Error\nThis map isn't completely walled\n");
}
