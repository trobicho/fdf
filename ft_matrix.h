/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:51:12 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/18 00:32:43 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

void		ft_matrix_id(double m[4][4]);
void		ft_rotate(double m[4][4], double angle, double x, double y, double z);
void		ft_scale(double m[4][4], double x, double y, double z);
void		ft_translate(double m[4][4], double x, double y, double z);
t_point_3d	ft_matrix_apply(double m[4][4], t_point_3d v);
#endif
