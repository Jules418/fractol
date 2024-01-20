/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:06:06 by jules             #+#    #+#             */
/*   Updated: 2024/01/20 03:13:45 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterate_mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	int			i;

	i = 0;
	z = (t_complex){0., 0.};
	while (i < max_iter)
	{
		z = add(mult(z, z), c);
		if (norme2(z) >= 4.)
			break;
		i++;
	}
	return (i);
}

void	create_img_mandelbrot(t_data *data, t_params p)
{
	double		x;
	double		y;
	int			nb_iter;
	t_complex	screen_c;
	t_complex	z;

	screen_c = (t_complex){(double)p.s_width / 2., (double)p.s_height / 2.};
	x = 0.;
	while (x < (double)p.s_width)
	{
		y = 0.;
		while (y < (double)p.s_height)
		{
			z = (t_complex){x, y};
			z = add(p.v_center, mult_scal(2/p.zoom_f, sub(z, screen_c)));
			nb_iter = iterate_mandelbrot(z, p.max_iter);
			my_mlx_pixel_put(data, x, y, compute_color_bnw(nb_iter, p.max_iter));
			y += 1.;
		}
		x += 1.;
	}
}