/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_user.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:30:15 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/18 02:00:29 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init_mlx.h"
#include "ft_matrix.h"
#include "ft_point.h"
#include "mlx.h"
#include <stdio.h>

int		ft_key_hook(int keycode, void *param)
{
	t_mymlx	*ml;

	ml = (t_mymlx*)param;
	if (keycode == 53)
		printf("test\n");
	else if (keycode == 89)
		ft_rotate(ml->matrix, -0.5, 0, 0, 1);
	else if (keycode == 92)
		ft_rotate(ml->matrix, 0.5, 0, 0, 1);
	else if (keycode == 84)
		ft_rotate(ml->matrix, -0.5, 1, 0, 0);
	else if (keycode == 91)
		ft_rotate(ml->matrix, 0.5, 1, 0, 0);
	else if (keycode == 86)
		ft_rotate(ml->matrix, -0.5, 0, 1, 0);
	else if (keycode == 88)
		ft_rotate(ml->matrix, 0.5, 0, 1, 0);
	else if (keycode == 69)
		ft_scale(ml->matrix, 1.2, 1.2, 1.2);
	else if (keycode == 78)
		ft_scale(ml->matrix, 0.8, 0.8, 0.8);
	else if (keycode == 125)
		ft_translate(ml->matrix_repair, 0, 5, 0);
	else if (keycode == 126)
		ft_translate(ml->matrix_repair, 0, -5, 0);
	else if (keycode == 124)
		ft_translate(ml->matrix_repair, 5, 0, 0);
	else if (keycode == 123)
		ft_translate(ml->matrix_repair, -5, 0, 0);
	else
		return (0);
	ft_map_render(ml, ml->map);
	mlx_put_image_to_window(ml->mlx_ptr, ml->win_ptr, ml->img_ptr, 0, 0);
	return (0);
}

int		ft_mouse_press(int button, int x, int y, void *param)
{
	t_mymlx	*ml;

	ml = (t_mymlx*)param;
	if (button < 3)
		ml->button = button;
	return (0);
}

int		ft_mouse_release(int button, int x, int y, void *param)
{
	t_mymlx	*ml;

	ml = (t_mymlx*)param;
	if (button < 3)
		ml->button = 0;
	return (0);
}

int		ft_mouse_move(int x, int y, void *param)
{
	static int	x_last = 0;
	static int	y_last = 0;
	t_point_3d	vec;
	t_mymlx	*ml;

	ml = (t_mymlx*)param;
	if (ml->button == 1)
	{
		if (x_last != x || y_last != y)
		{
			vec.x = x - x_last;
			vec.y = y - y_last;
			vec.z = 0;
			vec = ft_normalize(vec);
			if (vec.x != 0.0 || vec.y != 0.0 || vec.z != 0.0)
			{
				ft_rotate(ml->matrix, 0.15, vec.y, vec.x, vec.z);
				ft_map_render(ml, ml->map);
				mlx_put_image_to_window(ml->mlx_ptr, ml->win_ptr, ml->img_ptr, 0, 0);
				x_last = x;
				y_last = y;
			}
		}
	}
	return (0);
}
