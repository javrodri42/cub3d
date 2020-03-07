/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 08:53:30 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/04 10:13:36 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_line(char **mem, char **line, int ret)
{
	char	*aux1;
	char	*aux2;

	if (!*mem && !ret)
	{
		*line = ft_strdup("");
		free(*mem);
		return (0);
	}
	else if ((aux1 = ft_strchr(*mem, '\n')))
	{
		*aux1 = 0;
		*line = ft_strdup(*mem);
		aux2 = ft_strdup(++aux1);
		free(*mem);
		*mem = aux2;
	}
	else
	{
		*line = ft_strdup(*mem);
		free(*mem);
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*mem[4096];
	int			ret;
	char		*aux;
	char		buffer[129];

	ret = 0;
	while ((ft_strchr(mem[fd], '\n')) == NULL)
	{
		ret = read(fd, buffer, 128);
		if (ret < 0)
			return (-1);
		if (ret == 0)
			break ;
		buffer[ret] = 0;
		if (!mem[fd])
			mem[fd] = ft_strdup(buffer);
		else
		{
			aux = ft_strjoin(mem[fd], buffer);
			free(mem[fd]);
			mem[fd] = aux;
		}
	}
	return (get_line(&mem[fd], line, ret));
}
