/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:40:49 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/20 20:30:38 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_line.h"
#include "get_next_line.h"
#include "./libft/libft.h" //a changer
#include "ft_matrix.h"
#include "ft_matrix_calc.h"
#include <stdlib.h>

void	ft_map_alloc(t_map *map, int w, int h)
{
	if ((map->p = malloc(sizeof(t_point_3d) * w * h)) != NULL)
	{
		map->w = w;
		map->h = h;
	}
}

void	ft_map_render(t_mymlx *mlx, t_map *map)
{
	int i;
	int	j;
	t_point_2d a;
	t_point_2d b;

	ft_memset(mlx->buf, 0x0, mlx->sline * mlx->h);
	if (map->w > 0 && map->h > 0)
	{
		i = 0;
		while (i < map->h)
		{
			a = ft_point3d_to2d(mlx, map->p[i * map->w]);
			j = 1;
			while (j < map->w)
			{
				b = ft_point3d_to2d(mlx, map->p[j + i * map->w]);
				ft_drawline(mlx, a, b);
				a = b;
				j++;
			}
			i++;
		}
		i = 0;
		while (i < map->w)
		{
			a = ft_point3d_to2d(mlx, map->p[i]);
			j = 1;
			while (j < map->h)
			{
				b = ft_point3d_to2d(mlx, map->p[i + j * map->w]);
				ft_drawline(mlx, a, b);
				a = b;
				j++;
			}
			i++;
		}
	}
}

void	ft_map_reset_marix(t_mymlx *ml)
{
	double	scale;

	ft_matrix_id(ml->matrix);
	ft_matrix_id(ml->matrix_repair);
	ft_translate(ml->matrix_repair, ml->w / 2.0, ml->h / 2.0, 0);
	scale = ((double)ml->w / ml->map->w < (double)ml->h / ml->map->h)
		? (double)ml->w / ml->map->w : (double)ml->h / ml->map->h;
	scale -= 0.2;
	ft_scale(ml->matrix, scale, scale, scale);
	ft_translate(ml->matrix, -(ml->map->w-1) / 2.0, -(ml->map->h-1) / 2.0, 0.0);
}
