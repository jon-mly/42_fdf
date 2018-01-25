NAME = fdf

TEST = test_fdf

LIBFT_REP = libft/
LIBFT = libft/libft.a

SRCS_REP = srcs/
SRCS = $(SRCS_REP)colors.c \
		$(SRCS_REP)line_drawing.c \
		$(SRCS_REP)read_map.c

W_FLAGS = -Wall -Werror -Wextra

MLX_FLAGS = -I ~/Library -g -L ~/Library -lmlx -framework OpenGL -framework \
			AppKit

test:
	gcc $(MLX_FLAGS) $(SRCS) $(SRCS_REP)main_test.c $(LIBFT) -o $(TEST)

all: test

clean:
	cd $(LIBFT_REP) && make clean
	rm -rf $(SRCS)

fclean: clean
	cd $(LIBFT_REP) && make fclean
	rm -rf $(TEST)

re: fclean all
