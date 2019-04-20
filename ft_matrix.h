/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:51:12 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/20 20:20:27 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

void		ft_matrix_define(double m1[4][4], double m2[4][4]);
void		ft_matrix_mul(double m1[4][4], double m2[4][4]);
void		ft_matrix_id(double m[4][4]);
t_point_3d	ft_matrix_apply(double m[4][4], t_point_3d v);
#endif
