/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:59:13 by jules             #+#    #+#             */
/*   Updated: 2024/01/23 08:38:42 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int	close_fractol(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

t_complex	get_world_pos(int x, int y, t_fractol *fractol)
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
	t_complex	mouse;
	t_complex	v_center;
	double		new_z;

	mouse = get_world_pos(x, y, fractol);
	v_center = fractol->params.v_center;
	if (button == 4)
	{
		new_z = fractol->params.zoom_f * ZOOM_MULT;
		if (isinf(new_z))
			return ;
		fractol->params.v_center = add(v_center, \
			mult_scal(1. / ZOOM_MULT, sub(mouse, v_center)));
	}
	else
	{
		new_z = fractol->params.zoom_f / ZOOM_MULT;
		if (new_z == 0.)
			return ;
		fractol->params.v_center = add(v_center, \
			mult_scal(1., sub(v_center, mouse)));
	}
	fractol->params.zoom_f = new_z;
}

void	set_julia_seed(int x, int y, t_fractol *fractol)
{
	fractol->params.julia_seed = get_world_pos(x, y, fractol);
}

void	move_julia_seed(int keycode, t_fractol *fractol)
{
	t_complex	displacement;

	if (keycode == 'i')
		displacement = (t_complex){0, -50};
	if (keycode == 'j')
		displacement = (t_complex){-50, 0};
	if (keycode == 'k')
		displacement = (t_complex){0, 50};
	if (keycode == 'l')
		displacement = (t_complex){50, 0};
	fractol->params.julia_seed = add(fractol->params.julia_seed, \
			mult_scal(2. / fractol->params.zoom_f, displacement));
}
