/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:29:15 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/05/23 11:25:31 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Will calculate the 2D-coordinates of a point (a node of the wireframe)
** based on its 3D-coordinates, the view angle, rotation, zoom and center.
*/

static t_vector		apply_x_rotation(t_vector vector, t_view view)
{
	double		y;
	double		z;

	y = vector.y;
	z = vector.z;
	vector.y = y * cos(view.view_angle) - z * sin(view.view_angle);
	vector.z = y * sin(view.view_angle) + z * cos(view.view_angle);
	return (vector);
}

static t_vector		apply_z_rotation(t_vector vector, t_view view)
{
	double		x;
	double		y;

	x = vector.x;
	y = vector.y;
	vector.x = x * cos(view.view_rotation) - y * sin(view.view_rotation);
	vector.y = x * sin(view.view_rotation) + y * cos(view.view_rotation);
	return (vector);
}

t_point				point_from(double i, double j, double z, t_view view)
{
	t_point			a;
	t_vector		vector;

	vector.x = (i - ((double)view.map_length) / 2) * view.step;
	vector.y = (j - ((double)view.map_height) / 2) * view.step;
	vector.z = z * view.z_scale;
	vector = apply_z_rotation(vector, view);
	vector = apply_x_rotation(vector, view);
	a.x = (int)(vector.x + view.center_x);
	a.y = (int)(vector.y + view.center_y);
	return (a);
}
