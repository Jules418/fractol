/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_management.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:10:09 by jules             #+#    #+#             */
/*   Updated: 2024/01/23 08:40:20 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_MANAGEMENT_H
# define FRACTAL_MANAGEMENT_H

# include "fractol.h"
# include <math.h>

// ------- colors.c -------
int		rgb(int r, int g, int b);
int		compute_color(int n, t_fractol *fractol);

// ------- draw_fractals.c -------
int		compute_mandelbrot(t_complex c, t_params *p);
int		compute_julia(t_complex z0, t_params *p);
int		compute_tricorn(t_complex c, t_params *p);
void	create_fractal(t_fractol *frctl);

// ------- mandelbrot_explorer.c -------
void	set_home(t_fractol *fractol);
void	set_julia_island(t_fractol *fractol);
void	set_sun(t_fractol *fractol);
void	set_tendrils(t_fractol *fractol);

#endif