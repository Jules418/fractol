/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:09:38 by jules             #+#    #+#             */
/*   Updated: 2024/01/22 14:53:41 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_digit(char c)
{
	return (('0' <= c) && (c <= '9'));
}

int	ft_atoi(char *s)
{
	int		number;
	size_t	i;

	number = 0;
	i = 0;
	while (s[i])
	{
		if (!is_digit(s[i]))
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
	if ((s[0] == '-') && (i++))
		sign *= -1;
	while (s[i] && is_digit(s[i]))
		number = number * 10. + (double)(s[i++] - '0');
	if (s[i] && (s[i++] != '.'))
		return (0.);
	while (s[i + j] && is_digit(s[i + j]))
		number = number * 10. + (double)(s[i + (j++)] - '0');
	while (j--)
		number = number / 10.;
	return (sign*number);
}

t_fract_func	find_func(char c)
{
	if	(c == 'm')
		return (compute_mandelbrot);
	if	(c == 'j')
		return (compute_julia);
	return (NULL);
}

void	assign_w_h(t_args *args, char **argv, int i)
{
	args->width = ft_atoi(argv[i++]);
	args->height = ft_atoi(argv[i++]);
	if ((args->width < 1) || (args->height < 1))
		exit_with_error();
}

t_args	parse_args(int argc, char **argv)
{
	t_args	args;
	int		i;

	if ((argc != 2) && (argc != 4) && (argc != 6))
		exit_with_error();
	args.height = 600;
	args.width = 800;
	args.julia_seed = (t_complex){-1.34228188, 0.};
	args.fract_code = argv[1][0];
	args.fract_func = find_func(args.fract_code);
	if ((!args.fract_func) || argv[1][1])
		exit_with_error();
	i = 2;
	if ((args.fract_code == 'm') && (argc > 4))
		exit_with_error();
	if ((args.fract_code == 'j') && (argc <= 3))
		exit_with_error();
	if ((args.fract_code == 'j') && (argc >= 4))
		args.julia_seed = (t_complex){ft_atod(argv[i++]), ft_atod(argv[i++])};
	if (argc > i + 1)
		assign_w_h(&args, argv, i);
	return (args);
}
