/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:05:33 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/06/17 15:50:14 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <math.h>

/*
** ======================== MACROS
*/

# define WIN_LENGTH 1600
# define WIN_HEIGHT 1200

/*
** ======================== TYPEDEF
*/

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}				t_color;

typedef struct	s_map
{
	size_t				len;
	int					*coord_list;
	struct s_map		*next;
}				t_map;

typedef struct	s_view
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_height;
	int				win_length;
	void			*img_ptr;
	unsigned char	*img_str;
	int				line_size;
	int				img_height;
	int				img_length;
	double			zoom;
	double			view_angle;
	double			view_rotation;
	double			step;
	int				center_x;
	int				center_y;
	t_map			**map;
	int				map_length;
	int				map_height;
	double			z_scale;
}				t_view;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_line
{
	t_point		start;
	t_point		end;
	t_color		color;
}				t_line;

/*
** ======================== PROTOTYPES
*/

int				get_endian_color(unsigned int r, unsigned int g,
		unsigned int b);
void			draw_line(t_point start, t_point end, t_view view);
t_map			**read_map_from(char *file);
void			fill_pixel(t_view view, t_point point, t_color color);
t_point			calc_coordinates(t_view view, double prop_x, double prop_y);
int				display_map(t_map **map, t_view *view);
t_color			color_from(unsigned char r, unsigned char g, unsigned char b);
int				count_map_height(t_map **map);
t_point			point_from(double i, double j, double z, t_view view);
void			exit_error(t_view *view);
void			exit_normally(t_view *view);
void			exit_usage(void);
void			clear_map(t_map **map);
void			handle_key(int key, t_view *view);

#endif
