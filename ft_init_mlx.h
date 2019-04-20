/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <trobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:53:49 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/20 20:32:32 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_INIT_MLX_H
# define FT_INIT_MLX_H

typedef struct	s_point_3d
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
}				t_point_3d;

typedef struct	s_map
{
	t_point_3d	*p;
	int			w;
	int			h;
}				t_map;

typedef struct	s_mymlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			w;
	int			h;
	double		matrix_repair[4][4];
	double		matrix[4][4];
	t_map		*map;
	int			button;
	char		*buf;
	int			bpp;
	int			sline;
	int			endian;
}				t_mymlx;

int	ft_init_mlx(t_mymlx *init, int w, int h, char *name);
#endif
