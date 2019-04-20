/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:51:18 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/20 20:34:57 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include <math.h>

void		ft_matrix_define(double m1[4][4], double m2[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m1[i][j] = m2[i][j];
			j++;
		}
		i++;
	}
}

void		ft_matrix_mul(double m1[4][4], double m2[4][4])
{
	int		i;
	int		j;
	int		k;
	double	mr[4][4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			mr[i][j] = 0.0;
			while (k < 4)
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
	while (i < 4 * 4)
	{
		m[i / 4][i % 4] = 0;
		i++;
	}
	m[0][0] = 1;
	m[1][1] = 1;
	m[2][2] = 1;
	m[3][3] = 1;
}

t_point_3d	ft_matrix_apply(double m[4][4], t_point_3d v)
{
	t_point_3d	v_r;

	v_r.x = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + m[0][3];
	v_r.y = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2] + m[1][3];
	v_r.z = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2] + m[2][3];
	return (v_r);
}
