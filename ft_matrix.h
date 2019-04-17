/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:51:12 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/17 17:25:37 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

void		ft_matrix_id(double m[4][4]);
void		ft_rotate(t_mymlx *ml, double angle, double x, double y, double z);
void		ft_scale(t_mymlx *ml, double x, double y, double z);
void		ft_translate(t_mymlx *ml, double x, double y, double z);
t_point_3d	ft_matrix_apply(t_mymlx *ml, t_point_3d v);
#endif
