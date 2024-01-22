/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:25:33 by jules             #+#    #+#             */
/*   Updated: 2024/01/22 21:08:25 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(char *s)
{
	int		number;
	size_t	i;

	number = 0;
	i = 0;
	while (s[i])
	{
		if (!(('0' <= s[i]) && (s[i] <= '9')))
			return (0);
		number = number * 10 + (s[i] - '0');
		i++;
	}
	return (number);
}

double	ft_atod(char *s)
{
	double		number;
	double		sign;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	number = 0.;
	sign = 1.;
	if ((s[0] == '-') && (++i))
		sign *= -1;
	while (s[i] && (('0' <= s[i]) && (s[i] <= '9')))
		number = number * 10. + (double)(s[i++] - '0');
	if (s[i] && (s[i++] != '.'))
		return (0.);
	while (s[i + j] && (('0' <= s[i + j]) && (s[i + j] <= '9')))
		number = number * 10. + (double)(s[i + (j++)] - '0');
	while (j--)
		number = number / 10.;
	return (sign * number);
}

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (write(1, s, i));
}
