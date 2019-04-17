/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:14:42 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/17 17:07:43 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PIXEL_H
# define FT_PIXEL_H

void		ft_putpixel(void *img_ptr, int x, int y, unsigned int color);
void		ft_blackit(void *img_ptr, int w, int h);
#endif
