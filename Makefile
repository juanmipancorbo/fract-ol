# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 17:18:46 by jpancorb          #+#    #+#              #
#    Updated: 2024/04/03 22:30:51 by jpancorb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	add to mlx Makefile to silence warning messages
#	$(OBJ): $(SRC)
#		@$(CC) -c $(CFLAGS) $^

NAME	= fractol
SRCS	= events.c init.c main.c math_utils.c render.c utils.c
HEADER	= fractol.h
MLX		= mlx/libmlx.a
CFLAGS	= -Wall -Werror -Wextra 

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
		cc $(CFLAGS) -o $@ $^ -Lmlx -lmlx -framework OpenGL -framework AppKit

%.o: %.c $(HEADER)
		cc $(CFLAGS) -Imlx -c $< -o $@

$(MLX):
		$(MAKE) -C mlx

clean:
		$(MAKE) -C mlx clean
		rm -f $(OBJS)

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re