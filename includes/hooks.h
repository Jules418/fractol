/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:05:39 by jules             #+#    #+#             */
/*   Updated: 2024/01/21 01:49:46 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "fractol.h"

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

int		close(t_fractol *fractol);
int		draw_loop(t_fractol *fractol);
void	rescale(int button, int x, int y, t_fractol *fractol);
int		mouse_hook(int button, int x, int y, t_fractol *fractol);
int		key_handler(int keycode, t_fractol *fractol);

#endif