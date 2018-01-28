/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:05:50 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/01/26 14:35:11 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		print_map(t_map **map)
{
	t_map		*current;
	size_t		i;

	current = *map;
	while (current)
	{
		i = -1;
		while (++i < current->len)
		{
			ft_putnbr((current->coord_list)[i]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		current = current->next;
	}
}

int     deal_key(int key, void *param)
{
	t_view		*view;

	view = (t_view *)param;
	printf("key = %d\n", key);
    if (key == 53)
        exit(0);
	else if (key == 12)
	{
		view->zoom = view->zoom + 0.1;
		display_map(view->map, view);
	}
	else if (key == 14)
	{
		view->zoom = view->zoom - 0.1;
		display_map(view->map, view);
	}
	else if (key == 13)
	{
		view->center_y -= sin(view->view_angle) * 0.1 * (double)(view->img_height);
		display_map(view->map, view);
	}
	else if (key == 1)
	{
		view->center_y += sin(view->view_angle) * 0.1 * (double)(view->img_height);
		display_map(view->map, view);
	}
	else if (key == 126)
	{
		view->view_angle += M_PI_4 / 3;
		display_map(view->map, view);
	}
	else if (key == 125)
	{
		view->view_angle -= M_PI_4 / 3;
		display_map(view->map, view);
	}
	else if (key == 0)
	{
		view->center_x -= 0.1 * (double)(view->img_length);
		display_map(view->map, view);
	}
	else if (key == 2)
	{
		view->center_x += 0.1 * (double)(view->img_length);
		display_map(view->map, view);
	}
	else if (key == 123)
	{
		view->view_rotation -= M_PI_4 / 3;
		display_map(view->map, view);
	}
	else if (key == 124)
	{
		view->view_rotation += M_PI_4 / 3;
		display_map(view->map, view);
	}
	else if (key == 6)
	{
		view->z_scale *= 2;
		display_map(view->map, view);
	}
	else if (key == 8)
	{
		view->z_scale /= 2;
		display_map(view->map, view);
	}
    return (0);
}

t_view		*init_environment(void)
{
	t_view		*view;

	if (!(view = (t_view *)malloc(sizeof(t_view))))
		return (NULL);
	view->mlx_ptr = NULL;
	view->win_ptr = NULL;
	view->img_ptr = NULL;
	view->img_str = NULL;
	view->map = NULL;
	view->zoom = 0.4;
	view->view_angle = M_PI_2;
	view->view_rotation = 0;
	view->z_scale = 10;
	view->i = 0;

	return (view);
}

int main(int ac, char **av)
{
	t_map		**map;
	t_view		*view;

	view = init_environment();

	if (ac != 2)
		return (0);
	map = read_map_from(av[1]);
	if (map == NULL)
		ft_putendl("Returned t_map** is NULL");
	else
		print_map(map);

	view->map = map;
	view->map_length = (*map)->len;
	view->map_height = count_map_height(map);
	view->mlx_ptr = mlx_init();
    view->win_ptr = mlx_new_window(view->mlx_ptr, 1200, 800, "mlx 42");
	view->win_length = 1200;
	view->win_height = 800;
	view->center_x = view->win_length / 2;
	view->center_y = view->win_height / 2;
	display_map(map, view);

    mlx_key_hook(view->win_ptr, deal_key, (void *)view);
    mlx_loop(view->mlx_ptr);

	return (0);
}
