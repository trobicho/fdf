/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:04:13 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/17 17:30:06 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include "ft_matrix.h"

t_point_2d	ft_point3d_to2d(t_mymlx *mlx, t_point_3d p)
{
	t_point_2d	r;
	p = ft_matrix_apply(mlx, p);
	r.x = (int)(p.x * 5.0);
	r.y = (int)(p.y * 5.0);
	return (r);
}
