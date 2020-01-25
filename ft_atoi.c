/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javrodri <javrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:51:33 by javrodri          #+#    #+#             */
/*   Updated: 2019/11/12 14:55:08 by javrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MIN_INT -2147483648
#define MAX_INT 2147483647

static int	check(const char **str)
{
	int is_negative;

	while (**str == ' ' || **str == '\t' || **str == '\n'
			|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
	is_negative = 0;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			is_negative = 1;
		(*str)++;
	}
	return (is_negative);
}

int			ft_atoi(const char *str)
{
	unsigned int	nb;
	int				i;
	int				is_negative;

	is_negative = check(&str);
	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (!is_negative && nb > (unsigned int)MAX_INT)
			return (-1);
		else if (nb > (unsigned int)MIN_INT)
			return (0);
		nb = nb * 10 + (*str - 48);
		++str;
	}
	return (((int)is_negative ? -nb : nb));
}
