/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:27:28 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/20 17:49:35 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include "ft_pixel.h"
#include "ft_line.h"
#include "ft_init_mlx.h"
#include <math.h>

void	ft_drawline(t_mymlx *mlx, t_point_2d a, t_point_2d b)
{
	double	xs;
	double	ys;
	double	x;
	double	y;
	int		len;
	int		lenMax;

	xs = (b.x - a.x) < 0 ? -1.0 : 1.0;
	ys = (b.y - a.y) < 0 ? -1.0 : 1.0;
	if (ABS(b.x - a.x) < ABS(b.y - a.y))
		lenMax = ABS(b.y - a.y);
	else
		lenMax = ABS(b.x - a.x);
	if(lenMax > 0)
	{
		xs *= fabs((double)b.x - (double)a.x) / (double)lenMax;
		ys *= fabs((double)b.y - (double)a.y) / (double)lenMax;
		len = 0;
		x = (double)a.x;
		y = (double)a.y;
		while (len < lenMax)
		{
			if (x > 0 && x < mlx->w && y > 0 && y < mlx->h)
				ft_putpixel(mlx, (int)x, (int)y, a.color);
			x += xs;
			y += ys;
			len++;
		}
	}
}
