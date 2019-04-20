/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:55:11 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/20 20:36:09 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

int		ft_map_parse(t_map *map, int fd)
{
	char	*line;
	char	*ptr;
	char	*ptr_save;
	int		pz;
	int		x;
	int		y;
	int		w;
	int		base;

	w = 0;
	y = 0;
	base = 10;
	while ((x = get_next_line(fd, &line)) > 0)
	{
		ptr = line;
		ptr_save = ptr;
		x = 0;
		pz = ft_strtol(ptr, &ptr, 10);
		while (1)
		{
			if (ptr == ptr_save)
			{
				if (w > 0 && x == w)
					break ;
				else if (w == 0 && x > 0)
				{
					w = x;
					break;
				}
				else
					return (-1);
			}
			else if (ptr[0] == ',')
			{
				base = 0;
				ptr++;
			}
			else
			{
				base = 10;
				x++;
			}
			ptr_save = ptr;
			pz = ft_strtol(ptr, &ptr, base);
		}
		if (x != w)
			return (-1);
		y++;
	}
	ft_map_alloc(map, w, y);
	return (0);
}

int		ft_map_reparse(t_map *map, int fd)
{
	char	*line;
	char	*ptr;
	int		pz;
	int		x;
	int		y;
	int		base;

	y = 0;
	while ((x = get_next_line(fd, &line)) > 0)
	{
		ptr = line;
		x = 0;
		while (1)
		{
			if (x == map->w)
					break ;
			else if (ptr[0] == ',')
			{
				base = 0;
				ptr++;
			}
			else
			{
				base = 10;
				x++;
			}
			pz = ft_strtol(ptr, &ptr, base);
			if (base == 0)
				map->p[y * map->w + (x - 1)].color = pz;
			else
			{
				map->p[y * map->w + (x - 1)].color = 0x00FFFFFF;
				map->p[y * map->w + (x - 1)].x = (double)x - 1;
				map->p[y * map->w + (x - 1)].y = (double)y;
				map->p[y * map->w + (x - 1)].z = (double)pz;
			}
		}
		if (x != map->w)
			return (-1);
		y++;
	}
	return (0);
}
