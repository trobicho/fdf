/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:58:44 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/20 20:31:24 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_init_mlx.h"
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

void		ft_putpixel(t_mymlx *mlx, int x, int y, unsigned int color)
{
	ft_putcolor_bpp(&mlx->buf[x * mlx->bpp + y * mlx->sline], mlx->bpp, color);
}
