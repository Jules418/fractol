/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:10:52 by jules             #+#    #+#             */
/*   Updated: 2024/01/22 19:41:31 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_management.h"

int	rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	compute_color_bnw(int n, int max_iter)
{
	if (n == max_iter)
		return (0);
	return (rgb((int)((float)(n * 255) / (float)max_iter), \
				(int)((float)(n * 255) / (float)max_iter), \
				(int)((float)(n * 255) / (float)max_iter)));
}
