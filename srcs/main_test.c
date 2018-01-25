#include "fdf.h"

static void		display_map(t_map **map)
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

int main(int ac, char **av)
{
	t_map		**map;

	if (ac != 2)
		return (0);
	map = read_map_from(av[1]);
	if (map == NULL)
		ft_putendl("Returned t_map** is NULL");
	else
		display_map(map);
	return (0);
}
