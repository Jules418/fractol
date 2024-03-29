/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_explorer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:56:38 by jules             #+#    #+#             */
/*   Updated: 2024/01/22 19:36:18 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_management.h"

void	set_home(t_fractol *fractol)
{
	fractol->params.v_center = (t_complex){-1.01228188, 0.};
	fractol->params.zoom_f = 300.;
	fractol->params.max_iter = 255;
}

void	set_julia_island(t_fractol *fractol)
{
	fractol->params.v_center = (t_complex){-1.768778833, -0.001738996};
	fractol->params.zoom_f = 1585714676.;
	fractol->params.max_iter = 1300;
}

void	set_sun(t_fractol *fractol)
{
	fractol->params.v_center = (t_complex){-0.776592847, -0.136640848};
	fractol->params.zoom_f = 58282440.;
	fractol->params.max_iter = 770;
}

void	set_tendrils(t_fractol *fractol)
{
	fractol->params.v_center = (t_complex){-0.226266648, 1.11617444};
	fractol->params.zoom_f = 743786806.;
	fractol->params.max_iter = 600;
}
