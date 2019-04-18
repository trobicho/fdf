/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_user.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:30:39 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/18 01:28:19 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_USER_H
# define FT_USER_H

void	ft_key_hook(int keycode, void *param);
int		ft_mouse_press(int button, int x, int y, void *param);
int		ft_mouse_release(int button, int x, int y, void *param);
int		ft_mouse_move(int x, int y, void *param);
#endif
