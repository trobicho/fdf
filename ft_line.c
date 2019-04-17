/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:27:28 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/17 17:26:30 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include "ft_pixel.h"
#include "ft_line.h"
#include <math.h>

void	ft_drawline(void *img_ptr, t_point_2d a, t_point_2d b, Uint color)
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
			ft_putpixel(img_ptr, (int)x, (int)y, color);
			x += xs;
			y += ys;
			len++;
		}
	}
}
