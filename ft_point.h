/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:38:03 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/18 01:11:12 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_POINT_H
# define FT_POINT_H
#include "ft_init_mlx.h"

typedef struct	s_point_2d
{
	int	x;
	int	y;
}				t_point_2d;

t_point_2d	ft_point3d_to2d(t_mymlx *mlx, t_point_3d p);
t_point_3d	ft_normalize(t_point_3d v);
#endif
