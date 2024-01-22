/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:38:15 by jules             #+#    #+#             */
/*   Updated: 2024/01/22 14:50:54 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "parsing.h"

t_params	init_params(t_args as)
{
	t_params	params;

	params.s_width = as.width;
	params.s_height = as.height;
	params.v_center = (t_complex){-1.01228188, 0.};
	params.zoom_f = 300.;
	params.max_iter = 255;
	params.color_func = compute_color_bnw;
	params.julia_seed = as.julia_seed;
	return (params);
}

t_fractol	init_fractol(int argc, char **argv)
{
	t_fractol	frctl;
	t_args		as;

	as = parse_args(argc, argv);
	frctl.mlx = mlx_init();
	frctl.mlx_win = mlx_new_window(frctl.mlx, as.width, as.height, "fractol");
	if (!frctl.mlx_win)
		exit(EXIT_FAILURE);
	frctl.img.img = mlx_new_image(frctl.mlx, as.width, as.height);
	frctl.img.addr = mlx_get_data_addr(frctl.img.img, \
			&frctl.img.bits_per_pixel, \
			&frctl.img.line_length, &frctl.img.endian);
	frctl.params = init_params(as);
	frctl.fract_func = as.fract_func;
	frctl.fract_code = as.fract_code;
	return (frctl);
}
