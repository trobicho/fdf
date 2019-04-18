/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:04:13 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/18 02:05:55 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include "ft_matrix.h"
#include <math.h>

t_point_2d	ft_point3d_to2d(t_mymlx *mlx, t_point_3d p)
{
	t_point_2d	r;
	p = ft_matrix_apply(mlx->matrix, p);
	p = ft_matrix_apply(mlx->matrix_repair, p);
	r.x = (int)(p.x);
	r.y = (int)(p.y);
	return (r);
}

t_point_3d	ft_normalize(t_point_3d v)
{
	t_point_3d	vr;
	double		len;
	
	len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (len > 0)
	{
		vr.x = v.x / len;
		vr.y = v.y / len;
		vr.z = v.z / len;
	}
	else
		return ((t_point_3d){0.0, 0.0, 0.0});
	return (vr);
}
