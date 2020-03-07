/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:05:39 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/06 17:05:41 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int keycode, t_params *p)
{
	if (keycode == 13 || keycode == 126)
		p->move_up = 1;
	else if (keycode == 1 || keycode == 125)
		p->move_down = 1;
	else if (keycode == 124)
		p->move_right = 1;
	else if (keycode == 0)
		p->left_mov = 1;
	else if (keycode == 2)
		p->right_mov = 1;
	else if (keycode == 123)
		p->move_left = 1;
	else if (keycode == 257 || keycode == 258)
		p->ms = 0.1;
	else if (keycode == 53)
		ft_close(p);
	else if (keycode == 117)
		wolf3d_init(p);
	else
		key_press2(keycode, p);
	return (0);
}

int		key_release(int keycode, t_params *p)
{
	if (keycode == 13 || keycode == 126)
		p->move_up = 0;
	else if (keycode == 1 || keycode == 125)
		p->move_down = 0;
	else if (keycode == 124)
		p->move_right = 0;
	else if (keycode == 123)
		p->move_left = 0;
	else if (keycode == 0)
		p->left_mov = 0;
	else if (keycode == 2)
		p->right_mov = 0;
	else if (keycode == 257 || keycode == 258)
		p->ms = 0.05;
	return (0);
}

void	move_right_left(t_params *p)
{
	if (p->right_mov)
	{
		if (!p->map[(int)(p->x_pos + p->y_dir * p->ms)][(int)(p->y_pos)])
			p->x_pos += p->y_dir * p->ms;
		if (!p->map[(int)(p->x_pos)][(int)(p->y_pos - p->x_dir * p->ms)])
			p->y_pos -= p->x_dir * p->ms;
	}
	if (p->left_mov)
	{
		if (!p->map[(int)(p->x_pos - p->y_dir * p->ms)][(int)(p->y_pos)])
			p->x_pos -= p->y_dir * p->ms;
		if (!p->map[(int)(p->x_pos)][(int)(p->y_pos + p->x_dir * p->ms)])
			p->y_pos += p->x_dir * p->ms;
	}
}

void	move_side(t_params *p)
{
	if (p->move_right == 1)
	{
		p->x_olddir = p->x_dir;
		p->x_dir = p->x_dir * cos(-p->rs) - p->y_dir * sin(-p->rs);
		p->y_dir = p->x_olddir * sin(-p->rs) + p->y_dir * cos(-p->rs);
		p->x_oldplane = p->x_plane;
		p->x_plane = p->x_plane * cos(-p->rs) - p->y_plane * sin(-p->rs);
		p->y_plane = p->x_oldplane * sin(-p->rs) + p->y_plane * cos(-p->rs);
	}
	if (p->move_left == 1)
	{
		p->x_olddir = p->x_dir;
		p->x_dir = p->x_dir * cos(p->rs) - p->y_dir * sin(p->rs);
		p->y_dir = p->x_olddir * sin(p->rs) + p->y_dir * cos(p->rs);
		p->x_oldplane = p->x_plane;
		p->x_plane = p->x_plane * cos(p->rs) - p->y_plane * sin(p->rs);
		p->y_plane = p->x_oldplane * sin(p->rs) + p->y_plane * cos(p->rs);
	}
}

int		move(t_params *p)
{
	if (p->move_up == 1)
	{
		if (p->map[(int)(p->x_pos + p->x_dir * p->ms)][(int)(p->y_pos)] == 0)
			p->x_pos += p->x_dir * p->ms;
		if (p->map[(int)(p->x_pos)][(int)(p->y_pos + p->y_dir * p->ms)] == 0)
			p->y_pos += p->y_dir * p->ms;
	}
	if (p->move_down == 1)
	{
		if (p->map[(int)(p->x_pos - p->x_dir * p->ms)][(int)(p->y_pos)] == 0)
			p->x_pos -= p->x_dir * p->ms;
		if (p->map[(int)(p->x_pos)][(int)(p->y_pos - p->y_dir * p->ms)] == 0)
			p->y_pos -= p->y_dir * p->ms;
	}
	move_side(p);
	move_right_left(p);
	ray_casting(p);
	return (0);
}
