/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:04:20 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/06 19:20:34 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen_digits(const char *s)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
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

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		tmp[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	check_orientations(t_params *p, int i, int j)
{
	p->initial_pos++;
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
