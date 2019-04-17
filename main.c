/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:04:23 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/17 17:31:38 by trobicho         ###   ########.fr       */
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

	if (ft_init_mlx(&myml, 800, 800, "test") == -1)
		return (EXIT_FAILURE);
	ft_matrix_id(myml.matrix);
	ft_map_test(&map);
	if (map.p == NULL)
		return (EXIT_FAILURE);
	myml.map = &map;
	ft_map_render(&myml, &map);
	mlx_key_hook(myml.win_ptr, &ft_key_hook, &myml);
	mlx_put_image_to_window(myml.mlx_ptr, myml.win_ptr, myml.img_ptr, 0, 0);
	mlx_loop(myml.mlx_ptr);
	return (EXIT_SUCCESS);
}
