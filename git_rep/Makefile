# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/02 11:04:36 by jmlynarc          #+#    #+#              #
#    Updated: 2018/06/17 15:45:58 by jmlynarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
ASSOCIATED_REP = $(NAME).dSYM

LIBFT_REP = libft/
LIBFT = libft/libft.a

INCLUDE_FLAG = -I includes/

SRCS_REP = srcs/
SRCS = colors.c \
		line_drawing.c \
		read_map.c \
		calc_coordinates.c \
		fill_pixel.c \
		grid_drawing.c \
		exit.c \
		key_events.c \
		main.c

SRC = $(addprefix $(SRCS_REP), $(SRCS))

O_SRCS = $(SRC:.c=.o)

W_FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -I ~/Library -g -L ~/Library -lmlx -framework OpenGL -framework \
			AppKit

MATH_FLAG = -lm

DEBUG_FLAG = -g -fsanitize=address -fno-omit-frame-pointer

$(NAME): $(O_SRCS)
	make -C $(LIBFT_REP)
	gcc $(INCLUDE_FLAG) $(MLX_FLAGS) $(MATH_FLAG) $(SRC) $(LIBFT) -o $(NAME)

%.o: %.c
	@gcc $(W_FLAGS) $(INCLUDE_FLAG) -c $< -o $@


all: $(NAME)

clean:
	make clean -C $(LIBFT_REP)
	rm -rf $(O_SRCS)

fclean: clean
	make fclean -C $(LIBFT_REP)
	rm -rf $(NAME) $(ASSOCIATED_REP)

re: fclean all
