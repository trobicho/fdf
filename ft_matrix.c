/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:51:18 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/17 17:32:51 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_init_mlx.h"
#include <math.h>

static void	ft_matrix_define(t_mymlx *ml, double m[4][4])
{
	int	i;
	int	j;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			ml->matrix[i][j] = m[i][j];
			j++;
		}
		i++;
	}
}

static void	ft_matrix_mul(t_mymlx *ml, double m[4][4])
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
				mr[i][j] += ml->matrix[i][k] * m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	ft_matrix_define(ml, mr);
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

void		ft_rotate(t_mymlx *ml, double angle, double x, double y, double z)
{
	double	m[4][4];
	double	c_a;
	double	s_a;

	c_a = cos(angle);
	s_a = sin(angle);
	ft_matrix_id(m);

	ft_matrix_id(m);
	m[0][0] = x + y * c_a + z * c_a;
	m[0][1] = z * -s_a;
	m[0][2] = y * -s_a;

	m[1][0] = z * s_a;
	m[1][1] = x * c_a + y + z * c_a;
	m[1][2] = x * s_a;

	m[2][0] = y * s_a;
	m[2][1] = x * -s_a;
	m[2][2] = x * c_a + y * c_a + z;
	ft_matrix_mul(ml, m);
}

void		ft_scale(t_mymlx *ml, double x, double y, double z)
{
	double	m[4][4];

	ft_matrix_id(m);
	m[0][0] = x;
	m[1][1] = y;
	m[2][2] = z;
	ft_matrix_mul(ml, m);
}
	
void		ft_translate(t_mymlx *ml, double x, double y, double z)
{
	double	m[4][4];

	ft_matrix_id(m);
	m[0][3] = x;
	m[1][3] = y;
	m[2][3] = z;
	ft_matrix_mul(ml, m);
}

t_point_3d	ft_matrix_apply(t_mymlx *ml, t_point_3d v)
{
	t_point_3d	v_r;

	v_r.x = v.x * ml->matrix[0][0] + v.y * ml->matrix[0][1]
				+ v.z * ml->matrix[0][2] + ml->matrix[0][3];
	v_r.y = v.x * ml->matrix[1][0] + v.y * ml->matrix[1][1]
				+ v.z * ml->matrix[1][2] + ml->matrix[1][3];
	v_r.z = v.x * ml->matrix[2][0] + v.y * ml->matrix[2][1]
				+ v.z * ml->matrix[2][2] + ml->matrix[2][3];
	//v_r->x = ml->matrix[3][0] + ml->matrix[3][1] + matrix[3][2] + matrix[3][3];
	return (v_r);
}
