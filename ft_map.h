/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:41:41 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/17 16:47:22 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_MAP_H
# define FT_MAP_H
#include "ft_point.h"
#include "ft_init_mlx.h"

void			ft_map_alloc(t_map *map, int w, int h);
void			ft_map_test(t_map *map);
void			ft_map_render(t_mymlx *mlx, t_map *map);
#endif
