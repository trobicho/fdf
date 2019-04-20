CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g
SRCS = main.c ft_user.c ft_parse.c ft_map.c ft_point.c ft_line.c ft_matrix_calc.c ft_matrix.c ft_init_mlx.c
HDRS = ft_user.h ft_map.h ft_parse.h ft_point.h ft_line.h ft_matrix_calc.c ft_matrix.h ft_init_mlx.h
OUTS = $(SRCS:.c=.o)
NAME = fdf

all: $(NAME)

$(NAME): $(OUTS)
	$(CC) $(OUTS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OUTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
