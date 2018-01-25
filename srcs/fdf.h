#ifndef FDF_H
# define FDF_H

/*
** ======================== INCLUDES
*/

# include "mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


/*
** ======================== TYPEDEF
*/

typedef struct	s_map
{
	size_t				len;
	int					*coord_list;
	struct s_map		*next;
}				t_map;

typedef struct	s_view
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_view;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_line
{
	t_point		start;
	t_point		end;
	int			color;
}				t_line;


/*
** ======================== PROTOTYPES
*/

int		get_endian_color(unsigned int r, unsigned int g, unsigned int b);
void	draw_line(t_point start, t_point end, t_view view);
t_map			**read_map_from(char *file);

#endif
