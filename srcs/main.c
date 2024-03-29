/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:50:53 by jules             #+#    #+#             */
/*   Updated: 2024/02/15 12:47:35 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractal_management.h"
#include "inits.h"
#include "hooks.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_loop(t_fractol *fractol)
{
	create_fractal(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, \
		fractol->img.img, 0, 0);
	if (!fractol->lock_colors)
		fractol->nb_frame_mod360 = (fractol->nb_frame_mod360 + 1) % 360;
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	fractol = init_fractol(argc, argv);
	mlx_hook(fractol.mlx_win, 17, 1L << 0, close_fractol, &fractol);
	mlx_mouse_hook(fractol.mlx_win, mouse_hook, &fractol);
	mlx_hook(fractol.mlx_win, 2, 1L << 0, key_handler, &fractol);
	mlx_loop_hook(fractol.mlx, draw_loop, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
