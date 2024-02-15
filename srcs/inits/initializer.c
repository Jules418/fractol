/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:38:15 by jules             #+#    #+#             */
/*   Updated: 2024/02/15 12:46:46 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inits.h"

t_fract_func	find_func(char c)
{
	if (c == 'm')
		return (compute_mandelbrot);
	if (c == 'j')
		return (compute_julia);
	if (c == 't')
		return (compute_tricorn);
	return (NULL);
}

void	assign_w_h(t_args *args, char **argv, int i)
{
	args->width = ft_atoi(argv[i++]);
	args->height = ft_atoi(argv[i]);
	if ((args->width < 1) || (args->height < 1))
		exit_with_error();
}

t_args	parse_args(int argc, char **argv)
{
	t_args	args;
	int		i;

	if ((argc != 2) && (argc != 4) && (argc != 6))
		exit_with_error();
	args.height = 600;
	args.width = 800;
	args.julia_seed = (t_complex){-1.34228188, 0.};
	args.fract_code = argv[1][0];
	args.fract_func = find_func(args.fract_code);
	if ((!args.fract_func) || argv[1][1])
		exit_with_error();
	i = 2;
	if ((args.fract_code != 'j') && (argc > 4))
		exit_with_error();
	if ((args.fract_code == 'j') && (argc <= 3))
		exit_with_error();
	if ((args.fract_code == 'j') && (argc >= 4))
	{
		args.julia_seed = (t_complex){ft_atod(argv[i]), ft_atod(argv[i + 1])};
		i += 2;
	}
	if (argc > i + 1)
		assign_w_h(&args, argv, i);
	return (args);
}

t_params	init_params(t_args as)
{
	t_params	params;

	params.s_width = as.width;
	params.s_height = as.height;
	params.v_center = (t_complex){-1.01228188, 0.};
	params.zoom_f = 300.;
	params.max_iter = 255;
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
	frctl.nb_frame_mod360 = 0;
	frctl.lock_colors = 0;
	return (frctl);
}
