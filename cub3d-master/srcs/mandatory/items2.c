/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:15:49 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/18 15:16:13 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bonus(t_env *env)
{
	env->lives = 3;
	env->sprite_count--;
}