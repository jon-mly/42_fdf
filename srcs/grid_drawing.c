/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:12:19 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/01/26 14:39:14 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_map_height(t_map **map)
{
	t_map	*current;
	int		count;

	count = 0;
	current = *map;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}

void	horizontal_line_fill(t_map **map, t_view view)
{
	t_map		*current;
	int			x;
	int			y;
	t_point		start;
	t_point		end;

	current = *map;
	y = 0;
	if (!(current))
		return;
	while (current)
	{
		x = -1;
		while (++x < view.map_length - 1)
		{
			start = point_from((double)x, (double)y, (double)current->coord_list[x], view);
			end = point_from((double)(x + 1), (double)y, (double)current->coord_list[x + 1], view);
			draw_line(start, end, view);
		}
		y++;
		current = current->next;
	}
}

void	vertical_line_fill(t_map **map, t_view view)
{
	t_map		*current;
	int			x;
	int			y;
	t_point		start;
	t_point		end;

	current = *map;
	y = 0;
	if (!(current))
		return;
	while (current->next)
	{
		x = -1;
		while (++x < view.map_length)
		{
			start = point_from((double)x, (double)y, (double)current->coord_list[x], view);
			end = point_from((double)x, (double)(y + 1), current->next->coord_list[x], view);
			//ft_putendl("Pass");
			draw_line(start, end, view);
			//ft_putendl("End");
		}
		y++;
		current = current->next;
	}
}

void	display_map(t_map **map, t_view *view)
{
	void	*ptr_img;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		endian;

	ft_putendl("#2");
	if (view->img_ptr)
		mlx_destroy_image(view->mlx_ptr, view->img_ptr);
	if (!(ptr_img = mlx_new_image(view->mlx_ptr, view->win_length, view->win_height)))
		return;
	view->img_length = view->win_length;
	view->img_height = view->win_height;
	view->img_ptr = ptr_img;
	view->step = (double)(((view->zoom) * (view->img_length)) / ((*map)->len));
	img_str = mlx_get_data_addr(ptr_img, &bpp, &s_l, &endian);
	view->img_str = (unsigned char *)img_str;
	view->line_size = s_l / 4;
	horizontal_line_fill(map, *view);
	vertical_line_fill(map, *view);
	mlx_put_image_to_window((void *)view, view->win_ptr, ptr_img, 0, 0);
}
