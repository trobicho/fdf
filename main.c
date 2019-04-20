/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:04:23 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/20 21:14:40 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "ft_line.h"
#include "ft_user.h"
#include "ft_init_mlx.h"
#include "ft_matrix.h"
#include "ft_matrix_calc.h"
#include "mlx.h"
#include "ft_map.h"

int		main(int ac, char **av)
{
	t_mymlx	myml;
	t_map	map;
	int		fd;

	if (ac != 2)
	{
		return (-1);
	}
	fd = open(av[1], 0);
	if (fd < 3)
		return (-1);
	ft_map_parse(&map, fd);
	close(fd);
	fd = open(av[1], 0);
	ft_map_reparse(&map, fd);
	if (ft_init_mlx(&myml, 1000, 800, "test") == -1)
		return (EXIT_FAILURE);
	myml.map = &map;
	ft_map_reset_marix(&myml);
	ft_map_render(&myml, &map);
	mlx_hook(myml.win_ptr, 2, 0, &ft_key_hook, &myml);
	mlx_hook(myml.win_ptr, 4, 0, &ft_mouse_press, &myml);
	mlx_hook(myml.win_ptr, 5, 0, &ft_mouse_release, &myml);
	mlx_hook(myml.win_ptr, 6, 0, &ft_mouse_move, &myml);
	mlx_put_image_to_window(myml.mlx_ptr, myml.win_ptr, myml.img_ptr, 0, 0);
	mlx_loop(myml.mlx_ptr);
	return (EXIT_SUCCESS);
}
