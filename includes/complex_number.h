/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_number.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:39:34 by jules             #+#    #+#             */
/*   Updated: 2024/01/20 02:26:34 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_NUMBER_H
# define COMPLEX_NUMBER_H

typedef struct	s_complex
{
	double re;
	double im;
}				t_complex;

t_complex	add(t_complex a, t_complex b);
t_complex	sub(t_complex a, t_complex b);
t_complex	mult(t_complex a, t_complex b);
t_complex	mult_scal(double x, t_complex z);
double		norme2(t_complex z);


#endif