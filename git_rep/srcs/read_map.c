/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:05:54 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/06/17 16:44:21 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		is_integer_convertible(char *str)
{
	size_t		i;

	i = -1;
	while (str[++i])
	{
		if ((i == 0 && !(ft_isdigit(str[i])) && str[i] != '-' && str[i] != '+')
			|| (i > 0 && !(ft_isdigit(str[i]))))
			return (0);
	}
	return (1);
}

static size_t	line_count(char **coord_line)
{
	size_t		count;

	count = 0;
	while (coord_line[count])
		count++;
	return (count);
}

static t_map	*convert_coord_line(char **coord_line)
{
	t_map		*line;
	int			*z_coord_list;
	size_t		i;
	size_t		count;

	if (!coord_line)
		return (NULL);
	count = line_count(coord_line);
	i = -1;
	if (!(line = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(z_coord_list = (int*)malloc(sizeof(int) * count)))
		return (NULL);
	while (++i < count)
	{
		if (!(is_integer_convertible(coord_line[i])))
			return (NULL);
		z_coord_list[i] = ft_atoi(coord_line[i]);
		ft_memdel((void**)&coord_line[i]);
	}
	line->coord_list = z_coord_list;
	line->len = count;
	line->next = NULL;
	ft_memdel((void**)&coord_line);
	return (line);
}

static void		append_node(t_map **map, t_map *new_node)
{
	t_map	*current;

	current = *map;
	if (current == NULL)
		*map = new_node;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

t_map			**read_map_from(char *file)
{
	int		fd;
	char	**tmp;
	t_map	**map;
	t_map	*new_node;

	if ((fd = open(file, O_RDONLY)) < 3)
		return (NULL);
	if (!(tmp = (char **)malloc(sizeof(char *))))
		return (NULL);
	if (!(map = (t_map**)malloc(sizeof(t_map*))))
		return (NULL);
	*map = NULL;
	while ((get_next_line(fd, tmp)) > 0)
	{
		if (!(new_node = convert_coord_line(ft_strsplit(*tmp, ' '))))
			return (NULL);
		append_node(map, new_node);
		ft_memdel((void**)tmp);
	}
	ft_strdel(tmp);
	ft_memdel((void**)&tmp);
	close(fd);
	return (map);
}
