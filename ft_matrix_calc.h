/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_calc.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:16:33 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/20 20:21:03 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_CALC_H
# define MATRIX_CALC_H

void	ft_rotate(double m[4][4], double angle, double x, double y, double z);
void	ft_scale(double m[4][4], double x, double y, double z);
void	ft_scale_pre(double m[4][4], double x, double y, double z);
void	ft_translate(double m[4][4], double x, double y, double z);
#endif
