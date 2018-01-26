/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:05:40 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/01/26 14:07:50 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
   static void    draw_sorted_line(t_point start, t_point end, t_view view)
   {
   int     dx;
   int     dy;
   int     e;

   e = end.x - start.x;
   dx = e * 2;
   dy = (end.y - start.y) * 2;
   while (start.x <= end.x)
   {
   mlx_pixel_put(view.mlx_ptr, view.win_ptr, start.x, start.y, get_endian_color(255, 255, 255));
   start.x++;
   if ((e = e - dy) <= 0)
   {
   start.y++;
   e += dx;
   }
   }
   }
   */

static void    naive_draw_line(t_point start, t_point end, t_view view)
{
	int		dx;
	int		dy;
	int		x;
	int		y;
	t_point	point;

	dx = end.x - start.x;
	dy = end.y - start.y;
	if (dx != 0)
	{
		x = start.x - 1;
		while (++x <= end.x)
		{
			y = start.y + dy * (x - start.x) / dx;
			point.x = x;
			point.y = y;
			fill_pixel(view.img_str, view.img_length, point, color_from(255, 255, 255));
//			mlx_pixel_put(view.mlx_ptr, view.win_ptr, x, y, get_endian_color(255, 255, 255));
		}
	}
	else if (dy != 0)
	{
		y = start.y - 1;
		while (++y <= end.y)
		{
			x = start.x + dx * (y - start.y) / dy;
			point.x = x;
			point.y = y;
			fill_pixel(view.img_str, view.img_length, point, color_from(255, 255, 255));
		}
	}
}

void        draw_line(t_point start, t_point end, t_view view)
{
	if (start.x > end.x)
		naive_draw_line(end, start, view);
	else
		naive_draw_line(start, end, view);
}
