/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:10:52 by jules             #+#    #+#             */
/*   Updated: 2024/01/23 08:47:29 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_management.h"

int	rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	hue_to_rgb(int h)
{
	float	x;

	x = 1.f - fabs((fmodf((float)h / 60.f, 2.f) - 1.f));
	if ((0 <= h) && (h < 60))
		return (rgb(255, 255 * x, 0));
	if ((60 <= h) && (h < 120))
		return (rgb(255 * x, 255, 0));
	if ((120 <= h) && (h < 180))
		return (rgb(0, 255, 255 * x));
	if ((180 <= h) && (h < 240))
		return (rgb(0, 255 * x, 255));
	if ((240 <= h) && (h < 300))
		return (rgb(255 * x, 0, 255));
	if ((300 <= h) && (h < 360))
		return (rgb(255, 0, 255 * x));
	return (0);
}

int	compute_color(int n, t_fractol *fractol)
{
	if (n == fractol->params.max_iter)
		return (0);
	return (hue_to_rgb((n + fractol->nb_frame_mod360) % 360));
}
