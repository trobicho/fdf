/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:40:49 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/17 23:53:52 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_line.h"
#include "get_next_line.h"
#include "./libft/libft.h" //a changer
#include <stdlib.h>

void	ft_map_alloc(t_map *map, int w, int h)
{
	if ((map->p = malloc(sizeof(t_point_3d) * w * h)) != NULL)
	{
		map->w = w;
		map->h = h;
	}
}

int		ft_map_parse(t_map *map, int fd)
{
	char	*line;
	char	*ptr;
	char	*ptrSave;
	int		pz;
	int		x;
	int		y;
	int		w;

	w = 0;
	y = 0;
	while ((x = get_next_line(fd, &line)) > 0)
	{
		ptr = line;
		ptrSave = line;
		x = 0;
		while ((ptr = ft_atoi_seek(ptr, &pz)))
		{
			printf("%d ", pz);
			if (ptr == ptrSave)
			{
				if (w > 0 && x == w)
					break ;
				else if (w == 0 && x > 0)
				{
					w = x;
					break;
				}
				else
				{
					printf("(ret -1)%d %d\n", w, x);
					return (-1);
				}
			}
			x++;
			ptrSave = ptr;
		}
		printf("\n");
		y++;
	}
	return (x);
}

void	ft_map_test(t_map *map)
{
	ft_map_alloc(map, 4, 3);
	if (map->p != NULL)
	{
		map->p[0] = (t_point_3d){.x = 0, .y = 0, .z = 0};
		map->p[1] = (t_point_3d){.x = 1, .y = 0, .z = 0};
		map->p[2] = (t_point_3d){.x = 2, .y = 0, .z = 0};
		map->p[3] = (t_point_3d){.x = 3, .y = 0, .z = 0};
		map->p[4] = (t_point_3d){.x = 0, .y = 1, .z = 1};
		map->p[5] = (t_point_3d){.x = 1, .y = 1, .z = 1};
		map->p[6] = (t_point_3d){.x = 2, .y = 1, .z = 0};
		map->p[7] = (t_point_3d){.x = 3, .y = 1, .z = 0};
		map->p[8] = (t_point_3d){.x = 0, .y = 2, .z = 0};
		map->p[9] = (t_point_3d){.x = 1, .y = 2, .z = 0};
		map->p[10] = (t_point_3d){.x = 2, .y = 2, .z = 0};
		map->p[11] = (t_point_3d){.x = 3, .y = 2, .z = 0};
	}
}

void	ft_map_render(t_mymlx *mlx, t_map *map)
{
	int i;
	int	j;
	t_point_2d a;
	t_point_2d b;

	ft_blackit(mlx->img_ptr, mlx->w, mlx->h);
	if (map->w > 0 && map->h > 0)
	{
		i = 0;
		while(i < map->h)
		{
			a = ft_point3d_to2d(mlx, map->p[i * map->w]);
			j = 1;
			while (j < map->w)
			{
				b = ft_point3d_to2d(mlx, map->p[j + i * map->w]);
				ft_drawline(mlx->img_ptr, a, b, 0x00AAAAAA);
				a = b;
				j++;
			}
			i++;
		}
		i = 0;
		while(i < map->w)
		{
			a = ft_point3d_to2d(mlx, map->p[i]);
			j = 1;
			while (j < map->h)
			{
				b = ft_point3d_to2d(mlx, map->p[i + j * map->w]);
				ft_drawline(mlx->img_ptr, a, b, 0x00AAAAAA);
				a = b;
				j++;
			}
			i++;
		}
	}
}
