/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:10:52 by jules             #+#    #+#             */
/*   Updated: 2024/01/20 13:14:25 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

int	compute_color_bnw(int n, int max_iter)
{
	if (n == max_iter)
		return (0);
	return (RGB((int)((float)(n * 255) / (float)max_iter), \
				(int)((float)(n * 255) / (float)max_iter), \
				(int)((float)(n * 255) / (float)max_iter)));
}
