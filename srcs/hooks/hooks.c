/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:06:21 by jules             #+#    #+#             */
/*   Updated: 2024/01/22 14:57:13 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int	close_fractol(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}

t_complex	get_mouse_wp(int x, int y, t_fractol *fractol)
{
	t_complex	s_center;
	t_complex	v_center;
	t_complex	p_mouse;

	s_center = (t_complex){(double) fractol->params.s_width / 2., \
			(double) fractol->params.s_height / 2.};
	v_center = fractol->params.v_center;
	p_mouse = (t_complex){(double) x, (double) y};

	return (add(v_center, \
			mult_scal(2. / fractol->params.zoom_f, sub(p_mouse, s_center))));
}

void	rescale(int button, int x, int y, t_fractol *fractol)
{
	t_complex	s_center;
	t_complex	v_center;
	t_complex	p_mouse;
	double		new_z;

	s_center = (t_complex){(double) fractol->params.s_width / 2., \
			(double) fractol->params.s_height / 2.};
	v_center = fractol->params.v_center;
	p_mouse = (t_complex){(double) x, (double) y};
	if (button == 4)
	{
		new_z = fractol->params.zoom_f * ZOOM_MULT;
		if (new_z > 2000000000000000.)
			new_z = 2000000000000000.;
		fractol->params.v_center = add(v_center, \
			mult_scal(1. / fractol->params.zoom_f, sub(p_mouse, s_center)));
	}
	else
	{
		new_z = fractol->params.zoom_f / ZOOM_MULT;
		fractol->params.v_center = add(v_center, \
			mult_scal(1. / new_z, sub(s_center, p_mouse)));
	}
	fractol->params.zoom_f = new_z;
}

void	set_julia_seed(int x, int y, t_fractol *fractol)
{
	
	fractol->params.julia_seed = get_mouse_wp(x, y, fractol);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if ((button == 4) || (button == 5))
		rescale(button, x, y, fractol);
	if ((button == 1) && (fractol->fract_code == 'j'))
		set_julia_seed(x, y, fractol);
	return (0);
}
