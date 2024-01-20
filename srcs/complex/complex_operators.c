/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operators.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:45:09 by jules             #+#    #+#             */
/*   Updated: 2024/01/20 02:26:40 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex_number.h"

t_complex	add(t_complex a, t_complex b)
{
	return ((t_complex){a.re + b.re, a.im + b.im});
}

t_complex	sub(t_complex a, t_complex b)
{
	return ((t_complex){a.re - b.re, a.im - b.im});
}

t_complex	mult(t_complex a, t_complex b)
{
	double	res_re;
	double	res_im;

	res_re = (a.re * b.re) - (a.im * b.im);
	res_im = (a.im * b.re) + (a.re * b.im);
	return ((t_complex){res_re, res_im});
}

t_complex	mult_scal(double x, t_complex z)
{
	return ((t_complex){z.re * x, z.im * x});
}

double	norme2(t_complex z)
{
	return (z.re * z.re + z.im * z.im);
}