/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:58:44 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/17 20:45:05 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

static void	ft_putcolor_bpp(char *buf, int bpp, unsigned int color)
{
	int		b;
	char	*c;

	b = 0;
	c = (char*)&color;
	while (b < bpp)
	{
		buf[b] = c[b];
		b++;
	}
}

void		ft_putpixel(void *img_ptr, int x, int y, unsigned int color)
{
	int		bpp;
	int		sline;
	int		endian;
	char	*buf;

	buf = mlx_get_data_addr(img_ptr, &bpp, &sline, &endian);
	bpp /= 8;
	ft_putcolor_bpp(&buf[x * bpp + y * sline], bpp, color);
}

void	ft_blackit(void *img_ptr, int w, int h)
{
	int	x;
	int	y;

	y = 0;
	while(y < h)
	{
		x = 0;
		while(x < w)
		{
			ft_putpixel(img_ptr, x, y, 0);
			x++;
		}
		y++;
	}
}
