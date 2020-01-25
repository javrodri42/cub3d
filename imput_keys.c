/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:40:12 by javrodri          #+#    #+#             */
/*   Updated: 2020/01/22 12:57:06 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_press(int key, t_params *p)
{
    if (key == UP || key  == W)
        p->flag_front = 1;
    if (key == DOWN || key == S)
        p->flag_back = 1;
    if (key == A)
        p->flag_left = 1;
    if (key == D)
        p->flag_right = 1;
    if (key == ESC)
        close_success(p);
    if (key == LEFT)
        p->flag_rotate_left = 1;
    if (key == RIGHT)
        p->flag_rotate_right = 1;
    if (key == VIEW_UP)
        p->flag_view_up = 1;
    return (0);
}

int    key_release(int key, t_params *p)
{
    if (key == UP || key  == W)
        p->flag_front = 0;
    if (key == DOWN || key == S)
        p->flag_back = 0;
    if (key == A)
        p->flag_left = 0;
    if (key == D)
        p->flag_right = 0;
    if (key == LEFT)
        p->flag_rotate_left = 0;
    if (key == RIGHT)
        p->flag_rotate_right = 0;
    if (key == VIEW_UP)
        p->flag_view_up = 0;
    return (0);
}