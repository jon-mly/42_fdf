/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:22:47 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/06/17 15:50:02 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			clear_map(t_map **map)
{
	t_map	*current;
	t_map	*next;

	if (map != NULL)
	{
		next = *map;
		while (next)
		{
			current = next;
			next = current->next;
			ft_memdel((void**)(&(current->coord_list)));
			ft_memdel((void**)&current);
		}
	}
}

void			exit_error(t_view *view)
{
	ft_putendl("An error has occured.");
	if (view->img_ptr)
		mlx_destroy_image(view->mlx_ptr, view->img_ptr);
	if (view->win_ptr && view->mlx_ptr)
		mlx_destroy_window(view->mlx_ptr, view->win_ptr);
	clear_map(view->map);
	ft_memdel((void**)(&view));
	exit(0);
}

void			exit_usage(void)
{
	ft_putendl("Usage : ./fdf [file to read]");
	exit(0);
}

void			exit_normally(t_view *view)
{
	if (view->img_ptr)
		mlx_destroy_image(view->mlx_ptr, view->img_ptr);
	if (view->win_ptr && view->mlx_ptr)
		mlx_destroy_window(view->mlx_ptr, view->win_ptr);
	clear_map(view->map);
	ft_memdel((void**)(&view));
	exit(0);
}
