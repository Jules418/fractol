/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:34:17 by jules             #+#    #+#             */
/*   Updated: 2024/01/23 07:09:12 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "complex_number.h"
# include <stdlib.h>

# define ZOOM_MULT 2.

typedef int (	*t_color_func)(int, int);

typedef struct s_data
{
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_params
{
	int				s_width;
	int				s_height;
	t_complex		v_center;
	double			zoom_f;
	int				max_iter;
	t_complex		julia_seed;
}				t_params;

typedef int (	*t_fract_func)(t_complex, t_params*);

typedef struct s_args
{
	int				height;
	int				width;
	t_fract_func	fract_func;
	char			fract_code;
	t_complex		julia_seed;
}				t_args;

typedef struct s_fractol
{
	void			*mlx;
	void			*mlx_win;
	t_data			img;
	int				is_img;
	size_t			nb_frame_mod360;
	t_params		params;
	t_fract_func	fract_func;
	char			fract_code;
}				t_fractol;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif