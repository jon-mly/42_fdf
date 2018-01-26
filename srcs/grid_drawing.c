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
/*
	t_map		*current;
	int			i;
	int			y;
	int			height;
	double		prop;

	current = *map;
	height = count_map_height(map);
	prop = (double)(((current->len > height) ? current->len : height) - 1);
	y = 0;
	while (current)
	{
		i = -1;
		while (++i < current->len - 1)
		{
//			printf("i = %d, y = %d, prop_x = %.3f, prop_y = %.3f\n", i, y, (double)i / (double)(current->len - 1), (double)y / (double)(height - 1));
			draw_line(calc_coordinates(view,
						(double)i / prop, (double)y / prop),
					calc_coordinates(view,
						(double)(i + 1) / prop, (double)y / prop),
					view);
		}
		y++;
		current = current->next;
	}
	*/

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
			start.x = (view.center_x) + (x - ((view.map_length) / 2)) * (view.step);
			start.y = (view.center_y) + (y - ((view.map_height) / 2)) * (view.step);
			end.x = (view.center_x) + (x + 1 - ((view.map_length) / 2)) * (view.step);
			end.y = (view.center_y) + (y - ((view.map_height) / 2)) * (view.step);
			draw_line(start, end, view);
		}
		y++;
		current = current->next;
	}
}

void	vertical_line_fill(t_map **map, t_view view)
{
	/*
	t_map		*current;
	int			y;
	int			x;
	int			height;
	double		prop;

	current = *map;
	height = count_map_height(map);
	prop = (double)(((current->len > height) ? current->len : height) - 1);
	y = 0;
	while (current->next)
	{
		x = -1;
		while (++x < current->len)
		{
//			printf("i = %d, y = %d, prop_x = %.3f, prop_y = %.3f\n", x, y, (double)x / (double)(current->len - 1), (double)y / (double)(height - 1));
			draw_line(calc_coordinates(view,
						(double)x / prop, (double)y / prop),
					calc_coordinates(view,
						(double)x / prop, (double)(y + 1) / prop),
					view);
		}
		y++;
		current = current->next;
	}
	*/

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
			start.x = view.center_x + (x - ((view.map_length) / 2)) * (view.step);
			start.y = view.center_y + (y - ((view.map_height) / 2)) * (view.step);
			end.x = view.center_x + (x - ((view.map_length) / 2)) * (view.step);
			end.y = view.center_y + (y + 1 - ((view.map_height) / 2)) * (view.step);
			draw_line(start, end, view);
		}
		y++;
		current = current->next;
	}

}

void	display_map(t_map **map, t_view view)
{
	void	*ptr_img;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		endian;

	if (view.img_ptr)
		mlx_destroy_image(view.mlx_ptr, view.img_ptr);
	if (!(ptr_img = mlx_new_image(view.mlx_ptr, view.win_length, view.win_length)))
		return;
	view.img_length = view.win_length;
	view.img_height = view.win_height;
	view.img_ptr = ptr_img;
	view.step = (double)(((view.zoom) * (view.img_length)) / ((*map)->len));
printf("Step = %.3f\n", view.step);
	view.img_ptr = ptr_img;
	img_str = mlx_get_data_addr(ptr_img, &bpp, &s_l, &endian);
	view.img_str = (unsigned char *)img_str;
	view.line_size = s_l;
	ft_putendl("#3.5");
	horizontal_line_fill(map, view);
	ft_putendl("#4");
	vertical_line_fill(map, view);
	ft_putendl("#5");
	mlx_put_image_to_window((void *)(&view), view.win_ptr, ptr_img, 0, 0);
}
