/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:14:49 by javrodri          #+#    #+#             */
/*   Updated: 2020/01/25 13:23:00 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     main(int argc, char **argv)
{
    t_params *p;
    int save_opt;
    
    save_opt = (argc >= 2 && !ft_strcmp(argv[1], "-save"));
    if (argc < (2 + save_opt))
		close_failure("Error:\nno map specified.\n");
    if (!(p = (t_params *)malloc(sizeof(t_params))))
        return (0);
    map_reader(&p);
    mlx_win_init(p);
    mlx_hook(p->win_ptr, 17, 1L << 0, close_success, &p);
    mlx_hook(p->win_ptr, 3, 0, key_release, &p);
    mlx_hook(p->win_ptr, 17, 1L << 0, close_success, &p);
    params_initialice(p, argv[1]);
    raycasting(p);
    mlx_loop_hook(p->mlx_ptr, ft_movement, p);
    mlx_loop(p->mlx_ptr);
}