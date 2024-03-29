/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conjugate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:55:46 by jules             #+#    #+#             */
/*   Updated: 2024/01/22 20:56:31 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex_number.h"

t_complex	conjugate(t_complex z)
{
	return ((t_complex){z.re, -z.im});
}
