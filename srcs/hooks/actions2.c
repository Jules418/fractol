/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:08:53 by jules             #+#    #+#             */
/*   Updated: 2024/01/22 20:01:25 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

void	move_center(int keycode, t_fractol *fractol)
{
	t_complex	displacement;

	if (keycode == UP_ARROW)
		displacement = (t_complex){0, -100};
	if (keycode == LEFT_ARROW)
		displacement = (t_complex){-100, 0};
	if (keycode == DOWN_ARROW)
		displacement = (t_complex){0, 100};
	if (keycode == RIGHT_ARROW)
		displacement = (t_complex){100, 0};
	fractol->params.v_center = add(fractol->params.v_center, \
			mult_scal(2. / fractol->params.zoom_f, displacement));
}

void	change_max_iter(int keycode, t_fractol *fractol)
{
	fractol->params.max_iter += ((keycode == 'd') * 2 - 1) * 50;
	if (fractol->params.max_iter < 20)
		fractol->params.max_iter = 20;
}

void	change_fractale(t_fractol *fractol)
{
	if (fractol->fract_code == 'm')
	{
		fractol->fract_code = 'j';
		fractol->fract_func = compute_julia;
	}
	else
	{
		fractol->fract_code = 'm';
		fractol->fract_func = compute_mandelbrot;
	}
}

void	select_hotspot(int keycode, t_fractol *fractol)
{
	if (keycode == F1)
		set_home(fractol);
	if (keycode == F2)
		set_julia_island(fractol);
	if (keycode == F3)
		set_sun(fractol);
	if (keycode == F4)
		set_tendrils(fractol);
}
