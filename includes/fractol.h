/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:34:17 by jules             #+#    #+#             */
/*   Updated: 2024/01/21 02:05:38 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include "complex_number.h"
# include "colors.h"

# define WIDTH 800
# define HEIGHT 600

# define ZOOM_MULT 2.


typedef int (	*t_color_func)(int, int);

typedef struct	s_data
{
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_params
{
	int				s_width;
	int				s_height;
	t_complex		v_center;
	double			zoom_f;
	int				max_iter;
	t_color_func	color_func;
	t_complex		julia_seed;
}				t_params;

typedef int (	*t_fract_func)(t_complex, t_params);

typedef struct s_fractol
{
	void			*mlx;
	void			*mlx_win;
	t_data			img;
	int				is_img;
	t_params		params;
	t_fract_func	fract_func;
	char			fract_code;
}				t_fractol;

# include "explorer.h"
# include "hooks.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int		compute_mandelbrot(t_complex c, t_params p);
int 	compute_julia(t_complex z0, t_params p);
void	create_fractal(t_fractol *frctl);

t_fractol	init_fractol(int argc, char **argv);

#endif