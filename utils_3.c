/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:04:20 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/02 17:52:54 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t ft_strlen_digits(const char *s)
{
    size_t i = 0;
    size_t j = 0;

    while (s[j] != '\0')
    {
        if (s[j] >= '0' && s[j] <= '9')
            i++;
        j++;
    }
    return (i);
}

int		key_press2(int keycode, t_params *p)
{
	if (p->texture == 0)
			p->texture = 1;
		else
			p->texture = 0;
	return (0);
}