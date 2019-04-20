/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:14:42 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/20 20:27:05 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PIXEL_H
# define FT_PIXEL_H

#include "ft_init_mlx.h"

void	ft_putpixel(t_mymlx *mlx, int x, int y, unsigned int color);
void	ft_blackit(t_mymlx *mlx);
#endif
