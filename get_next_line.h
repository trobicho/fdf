/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:28:02 by trobicho          #+#    #+#             */
/*   Updated: 2019/04/11 16:15:12 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE	4000
# include <unistd.h>

typedef struct	s_dlst
{
	char			*buf;
	ssize_t			size;
	int				fd;
	struct s_dlst	*prev;
	struct s_dlst	*next;
}				t_dlst;

int				get_next_line(const int fd, char **line);
#endif
