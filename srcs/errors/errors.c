/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:19:34 by jules             #+#    #+#             */
/*   Updated: 2024/01/22 19:30:48 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	exit_with_error(void)
{
	exit(EXIT_FAILURE);
}

/*
Your arguments need to be like this !
	./fractol <fract> [width height]


	<fract> can be :
		m : mandelbrot set\
		j : julia set\n
		n : newton fractal\n
	
	Note that if you want the julia set, you MUST give 2 numbers x and y
		to use for a seed (x y -> x + iy)
		
	[width height] are two optionnal numbers
		to specify the size of the window (800 600 by default)
*/