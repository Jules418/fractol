/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:08:53 by jules             #+#    #+#             */
/*   Updated: 2024/01/22 14:57:03 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

void	move_julia_seed(int keycode, t_fractol *fractol)
{
	t_complex	displacement;

	if (keycode == 'o')
		displacement = (t_complex){0, -50};
	if (keycode == 'k')
		displacement = (t_complex){-50, 0};
	if (keycode == 'l')
		displacement = (t_complex){0, 50};
	if (keycode == 'm')
		displacement = (t_complex){50, 0};
	fractol->params.julia_seed = add(fractol->params.julia_seed, \
			mult_scal(2. / fractol->params.zoom_f, displacement));
}

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

void	change_max_iter(int keycode, t_fractol *fractol){
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

int	key_handler(int keycode, t_fractol *fractol)
{
	if (keycode == ESC)
		close_fractol(fractol);
	if (((LEFT_ARROW - 1) < keycode) && (keycode < (DOWN_ARROW + 1)))
		move_center(keycode, fractol);
	if (keycode == 'w')
		rescale(4, fractol->params.s_width / 2, \
				fractol->params.s_height / 2, fractol);
	if (keycode == 's')
		rescale(5, fractol->params.s_width / 2, \
				fractol->params.s_height / 2, fractol);
	if ((keycode == 'a') || (keycode == 'd'))
		change_max_iter(keycode, fractol);
	if ((106 < keycode) && (keycode < 112) && (keycode != 110))
		move_julia_seed(keycode, fractol);
	if (((F1 - 1) < keycode) && (keycode < (F4 + 1)))
		select_hotspot(keycode, fractol);
	if (keycode == ENTER)
		change_fractale(fractol);
	return (0);
}
