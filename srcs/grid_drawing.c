/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:12:19 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/01/25 16:00:48 by jmlynarc         ###   ########.fr       */
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
	t_map	*current;
	int		i;
	int		y;
	int		height;

	current = *map;
	height = count_map_height(map);
	y = 0;
	while (current->next)
	{
		i = -1;
		while (++i < current->len - 1)
		{
			draw_line(calc_coordinates(view,
						(double)i / (double)(view.img_length),
						(double)y / (double)height),
					calc_coordinates(view,
						(double)(i + 1) / (double)(view.img_length),
						(double)y / (double)height),
					view);
		}
		y++;
	}
}

void	display_map(t_map **map, t_view view)
{
	void	*ptr_img;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		endian;

	// SHOULD REMOVE OLD IMAGE IF ANY
	if (!(ptr_img = mlx_new_image(view.mlx_ptr, view.win_length, view.win_length)))
		return;
	view.img_length = view.win_length;
	view.img_height = view.win_height;
ft_putendl("##1");
	view.img_ptr = ptr_img;
	img_str = mlx_get_data_addr(ptr_img, &bpp, &s_l, &endian);
ft_putendl("##2");
	horizontal_line_fill(map, view);
ft_putendl("##3");
	mlx_put_image_to_window((void *)(&view), view.win_ptr, ptr_img, 0, 0);
}
