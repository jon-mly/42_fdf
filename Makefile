NAME = fdf

TEST = test_fdf

LIBFT_REP = libft/
LIBFT = libft/libft.a

SRCS_REP = srcs/
SRCS = $(SRCS_REP)colors.c \
		$(SRCS_REP)line_drawing.c \
		$(SRCS_REP)read_map.c \
		$(SRCS_REP)calc_coordinates.c \
		$(SRCS_REP)fill_pixel.c \
		$(SRCS_REP)grid_drawing.c \

W_FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -I ~/Library -g -L ~/Library -lmlx -framework OpenGL -framework \
			AppKit

MATH_FLAG = -lm

test:
	gcc $(MLX_FLAGS) $(MATH_FLAG) $(SRCS) $(SRCS_REP)main_test.c $(LIBFT) -o $(TEST)

all: test

clean:
	cd $(LIBFT_REP) && make clean
	rm -rf $(SRCS)

fclean: clean
	cd $(LIBFT_REP) && make fclean
	rm -rf $(TEST)

re: fclean all
