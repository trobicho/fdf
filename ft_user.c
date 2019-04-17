/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_user.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:30:15 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/17 21:54:34 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init_mlx.h"
#include "ft_matrix.h"
#include "mlx.h"
#include <stdio.h>

void	ft_key_hook(int keycode, void *param)
{
	t_mymlx	*ml;

	ml = (t_mymlx*)param;
	if (keycode == 53)
		printf("test\n");
	else if (keycode == 89)
		ft_rotate(ml, -1, 0, 0, 1);
	else if (keycode == 92)
		ft_rotate(ml, 1, 0, 0, 1);
	else if (keycode == 84)
		ft_rotate(ml, -1, 1, 0, 0);
	else if (keycode == 91)
		ft_rotate(ml, 1, 1, 0, 0);
	else if (keycode == 86)
		ft_rotate(ml, -1, 0, 1, 0);
	else if (keycode == 88)
		ft_rotate(ml, 1, 0, 1, 0);
	else if (keycode == 69)
		ft_scale(ml, 1.2, 1.2, 1.2);
	else if (keycode == 78)
		ft_scale(ml, 0.8, 0.8, 0.8);
	else if (keycode == 125)
		ft_translate(ml, 0, 1, 0);
	else if (keycode == 126)
		ft_translate(ml, 0, -1, 0);
	else if (keycode == 124)
		ft_translate(ml, 1, 0, 0);
	else if (keycode == 123)
		ft_translate(ml, -1, 0, 0);
	else
		return ;
	ft_map_render(ml, ml->map);
	mlx_put_image_to_window(ml->mlx_ptr, ml->win_ptr, ml->img_ptr, 0, 0);
}
