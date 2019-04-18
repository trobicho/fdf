/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:04:23 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/18 02:10:56 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "ft_line.h"
#include "ft_user.h"
#include "ft_init_mlx.h"
#include "ft_matrix.h"
#include "mlx.h"
#include "ft_map.h"

int		main(int ac, char **av)
{
	t_mymlx	myml;
	t_map	map;

	ft_map_parse(&map, 0);
	if (ft_init_mlx(&myml, 800, 800, "test") == -1)
		return (EXIT_FAILURE);
	ft_map_test(&map);
	if (map.p == NULL)
		return (EXIT_FAILURE);
	myml.map = &map;
	ft_matrix_id(myml.matrix);
	ft_matrix_id(myml.matrix_repair);
	ft_translate(myml.matrix_repair, 400, 400, 0);
	ft_translate(myml.matrix, -(myml.map->w-1) / 2.0, -(myml.map->h-1) / 2.0, 0);
	ft_map_render(&myml, &map);
	mlx_hook(myml.win_ptr, 3, 1, &ft_key_hook, &myml);
	mlx_hook(myml.win_ptr, 4, 1, &ft_mouse_press, &myml);
	mlx_hook(myml.win_ptr, 5, 1, &ft_mouse_release, &myml);
	mlx_hook(myml.win_ptr, 6, 1, &ft_mouse_move, &myml);
	mlx_put_image_to_window(myml.mlx_ptr, myml.win_ptr, myml.img_ptr, 0, 0);
	mlx_loop(myml.mlx_ptr);
	return (EXIT_SUCCESS);
}
