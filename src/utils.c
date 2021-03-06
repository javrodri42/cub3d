/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:36:10 by javrodri          #+#    #+#             */
/*   Updated: 2020/03/07 13:42:17 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	if (dst || src)
	{
		while (n-- > 0)
			*(ptr++) = *(ptr2++);
		return (dst);
	}
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, ssize_t len)
{
	char	*ptr;
	char	*ret;
	char	*cpy_ret;

	if (!s || !(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (start >= ft_strlen(s))
		ret[0] = '\0';
	else
	{
		ptr = (char*)s + start;
		cpy_ret = ret;
		while (*ptr != '\0' && len-- > 0)
			*cpy_ret++ = *ptr++;
		*cpy_ret = '\0';
	}
	return (ret);
}

int		close_success(t_params *p)
{
	(void)p;

	ft_close(p);
	return (0);
}

int		close_failure(char *message)
{
	t_params *p;

	ft_putstr(message);
	ft_close(p);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
