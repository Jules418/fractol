/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:06:06 by jules             #+#    #+#             */
/*   Updated: 2024/02/15 12:27:19 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_management.h"

int	compute_mandelbrot(t_complex c, t_params *p)
{
	t_complex	z;
	int			i;

	i = 0;
	z = (t_complex){0., 0.};
	while (i < p->max_iter)
	{
		z = add(mult(z, z), c);
		if (norme2(z) > 4.)
			break ;
		i++;
	}
	return (i);
}

int	compute_julia(t_complex z0, t_params *p)
{
	t_complex	z;
	int			i;

	i = 0;
	z = z0;
	while (i < p->max_iter)
	{
		z = add(mult(z, z), p->julia_seed);
		if (norme2(z) > 4.)
			break ;
		i++;
	}
	return (i);
}

int	compute_tricorn(t_complex c, t_params *p)
{
	t_complex	z;
	t_complex	z_conjugate;
	int			i;

	i = 0;
	z = (t_complex){0., 0.};
	while (i < p->max_iter)
	{
		z_conjugate = conjugate(z);
		z = add(mult(z_conjugate, z_conjugate), c);
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
			z = (t_complex){x, frctl->params.s_height - y};
			z = add(frctl->params.v_center, \
					mult_scal(2. / frctl->params.zoom_f, sub(z, screen_c)));
			nb_iter = frctl->fract_func(z, &frctl->params);
			my_mlx_pixel_put(&frctl->img, x, y, \
				compute_color(nb_iter, frctl));
			y += 1.;
		}
		x += 1.;
	}
}
