/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:15:53 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/20 20:26:40 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include "ft_matrix.h"
#include <math.h>

void	ft_rotate(double m[4][4], double angle, double x, double y, double z)
{
	double	md[4][4];
	double	c_a;
	double	s_a;

	c_a = cos(angle);
	s_a = sin(angle);
	ft_matrix_id(md);
	md[0][0] = x * x * (1 - c_a) + c_a;
	md[0][1] = x * y * (1 - c_a) - z * s_a;
	md[0][2] = x * z * (1 - c_a) + y * s_a;
	md[1][0] = y * x * (1 - c_a) + z * s_a;
	md[1][1] = y * y * (1 - c_a) + c_a;
	md[1][2] = y * z * (1 - c_a) - x * s_a;
	md[2][0] = z * x * (1 - c_a) - y * s_a;
	md[2][1] = z * y * (1 - c_a) + x * s_a;
	md[2][2] = z * z * (1 - c_a) + c_a;
	ft_matrix_mul(md, m);
	ft_matrix_define(m, md);
}

void	ft_scale(double m[4][4], double x, double y, double z)
{
	double	md[4][4];

	ft_matrix_id(md);
	md[0][0] = x;
	md[1][1] = y;
	md[2][2] = z;
	ft_matrix_mul(md, m);
	ft_matrix_define(m, md);
}

void	ft_scale_pre(double m[4][4], double x, double y, double z)
{
	double	md[4][4];

	ft_matrix_id(md);
	md[0][0] = x;
	md[1][1] = y;
	md[2][2] = z;
	ft_matrix_mul(m, md);
}

void	ft_translate(double m[4][4], double x, double y, double z)
{
	double	md[4][4];

	ft_matrix_id(md);
	md[0][3] = x;
	md[1][3] = y;
	md[2][3] = z;
	ft_matrix_mul(m, md);
}
