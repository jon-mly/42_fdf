/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:54:44 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/01/26 14:37:27 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel(unsigned char *img_str, int line_size, t_point point,
		t_color color)
{
	int		i;

	i = (point.y * line_size + point.x) * 4;
	img_str[i] = color.r;
	img_str[i + 1] = color.g;
	img_str[i + 2] = color.b;
	img_str[i + 3] = color.a;
}
