/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:29:15 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/01/26 11:42:12 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Calculate the coordinates of a point in the given image, given the
** PROPORTION of x and y.
** Example : if it's the 15th point of the 3th line out of 30 and 10 lines,
** prop_x = 15 / 30 = 0.5, and prop_y = 3 / 9 = 0.3
*/

t_point		calc_coordinates(t_view view, double prop_x, double prop_y)
{
	int			calc_x;
	int			calc_y;
	t_point		point;

	calc_x = (((1.0 - view.zoom) / 2.0) * view.img_length) +
		(prop_x * view.zoom * view.img_length);
	calc_y = (((1.0 - view.zoom) / 2.0) * view.img_height) +
		(prop_y * view.zoom * view.img_height);
	point.x = calc_x;
	point.y = calc_y;
//	printf("=> prop_x = %.3f, prop_y = %.3f, calc_x = %d, calc_y = %d\n", prop_x, prop_y, calc_x, calc_y);
	return (point);
}

/*
** Will calculate the 2D-coordinates of a point (a node of the wireframe)
** based on its 3D-coordinates, the view angle, rotation, zoom and center.
*/

t_point		point_from(double i, double j, double z, t_view view)
{
	double			x;
	double			y;
	t_point			a;

	x = (double)(view.center_x) + (i - ((double)(view.map_length) / 2)) * view.step;
	y = (double)(view.center_y) + (j - ((double)(view.map_height) / 2)) * view.step * sin(view.view_angle) - z * view.z_scale * cos(view.view_angle);
	a.x = (int)(x * cos(view.view_rotation) - y * sin(view.view_rotation));
	a.y = (int)(x * sin(view.view_rotation) + y * cos(view.view_rotation));
	return (a);
}
