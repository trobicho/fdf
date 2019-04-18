/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:51:18 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/18 01:51:19 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include <math.h>

static void	ft_matrix_define(double m1[4][4], double m2[4][4])
{
	int	i;
	int	j;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			m1[i][j] = m2[i][j];
			j++;
		}
		i++;
	}
}

static void	ft_matrix_mul(double m1[4][4], double m2[4][4])
{
	int		i;
	int		j;
	int		k;
	double	mr[4][4];

	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			k = 0;
			mr[i][j] = 0.0;
			while(k < 4)
			{
				mr[i][j] += m1[i][k] * m2[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	ft_matrix_define(m1, mr);
}

void		ft_matrix_id(double m[4][4])
{
	int i;

	i = 0;
	while(i < 4*4)
	{
		m[i / 4][i % 4] = 0;
		i++;
	}
	m[0][0] = 1;
	m[1][1] = 1;
	m[2][2] = 1;
	m[3][3] = 1;
}

void		ft_rotate(double m[4][4], double angle, double x, double y, double z)
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

void		ft_scale(double m[4][4], double x, double y, double z)
{
	double	md[4][4];

	ft_matrix_id(md);
	md[0][0] = x;
	md[1][1] = y;
	md[2][2] = z;
	ft_matrix_mul(md, m);
	ft_matrix_define(m, md);
}
	
void		ft_translate(double m[4][4], double x, double y, double z)
{
	double	md[4][4];

	ft_matrix_id(md);
	md[0][3] = x;
	md[1][3] = y;
	md[2][3] = z;
	ft_matrix_mul(m, md);
}

t_point_3d	ft_matrix_apply(double m[4][4], t_point_3d v)
{
	t_point_3d	v_r;

	v_r.x = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + m[0][3];
	v_r.y = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + m[1][3];
	v_r.z = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + m[2][3];
	//v_r->x = ml->matrix[3][0] + ml->matrix[3][1] + matrix[3][2] + matrix[3][3];
	return (v_r);
}
