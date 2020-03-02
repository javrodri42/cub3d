/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 08:03:54 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/02 17:56:17 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(t_params *p)
{
	(void)p;
	system("leaks a.out");
	exit(EXIT_SUCCESS);
	return (0);
}

void	mlx_win_init(t_params *p)
{
	char	*title;

	title = ft_strjoin("Wolf3d : ", p->map_name);
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, p->win_width, p->win_height, title);
	ft_strdel(&title);
}

void	wolf3d_init(t_params *p)
{
	p->ms = 0.05;
	p->rs = 0.05;
	p->move_up = 0;
	p->move_down = 0;
	p->move_left = 0;
	p->move_right = 0;
	p->right_mov = 0;
	p->left_mov = 0;
	p->movespeed = 0.0001;
	p->x_text = 0;
	p->y_text = 0;
	p->map_width = 0;
	p->map_height = 0;
	p->initial_pos = 0;
	p->texture = 1;
	p->tex_width = 64;
	p->tex_height = 64;
	load_textures(p);
}

int		main(int ac, char **av)
{
	t_params p;

	if (ac != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	if (!(map_parser(&p, av)))
		return (0);
	mlx_win_init(&p);
	mlx_hook(p.win, 17, 0L, ft_close, &p);
	mlx_hook(p.win, 2, (1L << 0), key_press, &p);
	mlx_hook(p.win, 3, (1L << 1), key_release, &p);
	wolf3d_init(&p);
	if (ac == 3 && ft_strncmp("--save", av[2], 6) == 0)
		ray_casting_bmp(&p);
	else
	{
		if (!(p.spr_buffer = malloc(sizeof(double) * p.win_width)))
			close_failure("ERROR\nBuffer error");
		ray_casting(&p);
	}
	mlx_loop_hook(p.mlx, move, &p);
	mlx_loop(p.mlx);
}
