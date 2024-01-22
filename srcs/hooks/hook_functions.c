/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:57:05 by jules             #+#    #+#             */
/*   Updated: 2024/01/22 19:58:01 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if ((button == 4) || (button == 5))
		rescale(button, x, y, fractol);
	if ((button == 1) && (fractol->fract_code == 'j'))
		set_julia_seed(x, y, fractol);
	return (0);
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
