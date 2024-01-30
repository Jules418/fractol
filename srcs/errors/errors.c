/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:19:34 by jules             #+#    #+#             */
/*   Updated: 2024/01/23 08:48:48 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	exit_with_error(void)
{
	char	*error_message;

	error_message = "Your arguments need to be like this !\n\t./fractol \
<fract> [width height]\n\n\t<fract> can be :\n\t\tm \
: mandelbrot set\n\t\tj : julia set\n\t\tt : tricorn (Mandelbar) fractal\n\n\
\tNote that if you want the julia set, you MUST give \
2 numbers x and y\n\t\tto use for a seed (x y -> \
x + iy)\n\n\t[width height] are two strictly positive optionnal numbers \n\
\t\tto specify the size of the window (800 600 by default)\n";
	ft_putstr(error_message);
	exit(EXIT_FAILURE);
}
