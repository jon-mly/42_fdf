# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/02 11:04:36 by jmlynarc          #+#    #+#              #
#    Updated: 2018/04/17 15:50:30 by jmlynarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
ASSOCIATED_REP = $(NAME).dSYM

LIBFT_REP = libft/
LIBFT = libft/libft.a

INCLUDE_FLAG = -I includes/

SRCS_REP = srcs/
SRCS = $(SRCS_REP)colors.c \
		$(SRCS_REP)line_drawing.c \
		$(SRCS_REP)read_map.c \
		$(SRCS_REP)calc_coordinates.c \
		$(SRCS_REP)fill_pixel.c \
		$(SRCS_REP)grid_drawing.c \
		$(SRCS_REP)exit.c \
		$(SRCS_REP)key_events.c \
		$(SRCS_REP)main.c

O_SRCS = $(SRCS:.c=.o)

W_FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -I ~/Library -g -L ~/Library -lmlx -framework OpenGL -framework \
			AppKit

MATH_FLAG = -lm

%.o: %.c
	@gcc $(W_FLAGS) -c $< -o $@

$(NAME):
	make -C $(LIBFT_REP)
	gcc $(INCLUDE_FLAG) $(MLX_FLAGS) $(MATH_FLAG) $(SRCS) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	make clean -C $(LIBFT_REP)
	rm -rf $(O_SRCS)

fclean: clean
	make fclean -C $(LIBFT_REP)
	rm -rf $(NAME) $(ASSOCIATED_REP)

re: fclean all
