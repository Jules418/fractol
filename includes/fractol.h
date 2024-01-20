/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:34:17 by jules             #+#    #+#             */
/*   Updated: 2024/01/20 03:24:16 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "complex_number.h"
# include "colors.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_params
{
	int			s_width;
	int			s_height;
	t_complex	v_center;
	double		zoom_f;
	int			max_iter;
	t_complex	julia_seed;
}				t_params;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	create_img_mandelbrot(t_data *data, t_params p);

#endif