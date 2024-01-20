/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:12:38 by jules             #+#    #+#             */
/*   Updated: 2024/01/20 03:22:59 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define RGB(r, g, b) (((r) << 16) | ((g) << 8) | (b))

int	compute_color_bnw(int n, int max_iter);


#endif