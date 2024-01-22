/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:06:06 by jules             #+#    #+#             */
/*   Updated: 2024/01/22 15:52:43 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	compute_mandelbrot(t_complex c, t_params p)
{
	t_complex	z;
	int			i;

	i = 0;
	z = (t_complex){0., 0.};
	while (i < p.max_iter)
	{
		z = add(mult(z, z), c);
		if (norme2(z) > 4.)
			break ;
		i++;
	}
	return (i);
}

int	compute_julia(t_complex z0, t_params p)
{
	t_complex	z;
	int			i;

	i = 0;
	z = z0;
	while (i < p.max_iter)
	{
		z = add(mult(z, z), p.julia_seed);
		if (norme2(z) > 4.)
			break ;
		i++;
	}
	return (i);
}

void	create_fractal(t_fractol *frctl)
{
	double		x;
	double		y;
	int			nb_iter;
	t_complex	screen_c;
	t_complex	z;

	screen_c = (t_complex){(double)frctl->params.s_width / 2., \
		(double)frctl->params.s_height / 2.};
	x = 0.;
	while (x < (double)frctl->params.s_width)
	{
		y = 0.;
		while (y < (double)frctl->params.s_height)
		{
			z = (t_complex){x, y};
			z = add(frctl->params.v_center, \
					mult_scal(2. / frctl->params.zoom_f, sub(z, screen_c)));
			nb_iter = frctl->fract_func(z, frctl->params);
			my_mlx_pixel_put(&frctl->img, x, y, \
				frctl->params.color_func(nb_iter, frctl->params.max_iter));
			y += 1.;
		}
		x += 1.;
	}
}
