/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:38:15 by jules             #+#    #+#             */
/*   Updated: 2024/01/21 01:47:04 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	init_params(int argc, char **argv)
{
	t_params	params;

	(void) argc;
	(void) argv;
	params.s_width = WIDTH;
	params.s_height = HEIGHT;
	params.v_center = (t_complex){-1.01228188, 0.};
	params.zoom_f = 300.;
	params.max_iter = 255;
	params.color_func = compute_color_bnw;
	params.julia_seed = (t_complex){-1.343333334, 0.};
	return (params);
}

t_fractol	init_fractol(int argc, char **argv)
{
	t_fractol	frctl;

	frctl.mlx = mlx_init();
	frctl.mlx_win = mlx_new_window(frctl.mlx, WIDTH, HEIGHT, "fractol");
	if (!frctl.mlx_win)
		exit(EXIT_FAILURE);
	frctl.img.img = mlx_new_image(frctl.mlx, WIDTH, HEIGHT);
	frctl.img.addr = mlx_get_data_addr(frctl.img.img, \
			&frctl.img.bits_per_pixel, \
			&frctl.img.line_length, &frctl.img.endian);
	frctl.params = init_params(argc, argv);
	frctl.fract_func = compute_julia;
	frctl.fract_code = 'j';
	return (frctl);
}
