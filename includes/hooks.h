/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:05:39 by jules             #+#    #+#             */
/*   Updated: 2024/02/15 12:40:38 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "fractol.h"
# include "fractal_management.h"
# include <stdlib.h>
# include <math.h>

# define ESC 65307
# define UP_ARROW 65362
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define DOWN_ARROW 65364
# define F1 65470
# define F2 65471
# define F3 65472
# define F4 65473
# define ENTER 65293
# define SPACE 32

int		close_fractol(t_fractol *fractol);
void	rescale(int button, int x, int y, t_fractol *fractol);
void	set_julia_seed(int x, int y, t_fractol *fractol);
void	move_julia_seed(int keycode, t_fractol *fractol);

void	move_center(int keycode, t_fractol *fractol);
void	change_max_iter(int keycode, t_fractol *fractol);
void	change_fractale(t_fractol *fractol);
void	select_hotspot(int keycode, t_fractol *fractol);

int		mouse_hook(int button, int x, int y, t_fractol *fractol);
int		key_handler(int keycode, t_fractol *fractol);

#endif