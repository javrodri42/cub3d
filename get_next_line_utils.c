/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:21:10 by fvega-tr          #+#    #+#             */
/*   Updated: 2020/02/26 17:21:13 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

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

char *ft_strchr(char *str, int c)
{
    unsigned int i = 0, leng;
    if (!str)
        return (NULL);
    leng = ft_strlen(str);
    while (*str && *str != c)
    {
        i++;
        str++;
    }
    if (*str != c && i == leng)
        return (NULL);
    return (str);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    int i = 0;
    char *dest;
    if (!(dest = malloc(ft_strlen(s1)+ ft_strlen(s2) + 1)))
        return (NULL);
    while (*s1 != '\0')
        dest[i++] = *s1++;
    while (*s2 != '\0')
        dest[i++] = *s2++;
    dest[i] = '\0';
    return (dest);
}

char    *ft_strdup(const char *str)
{
    int i = 0;
    char *dest;
    if (!(dest = malloc(ft_strlen(str) + 1)))
        return (NULL);
    while (str[i] != '\0')
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
