/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:10:10 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/20 17:02:24 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LINE_H
# define FT_LINE_H

#include "ft_point.h"
#include "ft_init_mlx.h"
#define	ABS(v)	((v) < 0 ? -(v) : (v))

typedef	unsigned int Uint;

void	ft_drawline(t_mymlx *mlx, t_point_2d a, t_point_2d b);
#endif
