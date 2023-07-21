/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:38:43 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/20 09:30:52 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	path_image(char *path[6])
{
	*(path + 0) = "img/tileset/grass.xpm";
	*(path + 1) = "img/tileset/tree.xpm";
	*(path + 2) = "img/tileset/jewel.xpm";
	*(path + 3) = "img/tileset/exit.xpm";
	*(path + 4) = "img/sprite/twinsen-front-up.xpm";
	*(path + 5) = "img/sprite/croma.xpm";
}

static t_status	image_load(t_place *set)
{
	char		*path[6];
	int			i;

	if (!set)
		return (Off);
	path_image(path);
	i = -1;
	while (++i < 6)
	{
		if (!set->image_load_last(set, path[i], i + 1))
		{
			write(1, "Error\nimage doesn't exist\n", 26);
			set->gear->event &= ~(1 << MACHINE_RUNNING);
			return (Off);
		}
	}
	return (On);
}

static void	floor_load(t_place *set, t_map *map)
{
	int		i;
	t_vi2d	pos;
	t_image	*image;

	image = set->image_select(set, 1);
	if (!set || !image || !map)
		return ;
	set->map_create(set, 0,
		vi2d_start(image->size->x * map->size->x,
			image->size->y * map->size->y));
	if (!set->gear->bg->image)
	{
		write(1, "Error\nthere is no background", 28);
		set->gear->event &= ~(1 << MACHINE_RUNNING);
	}
	pos = vi2d_start(0, 0);
	i = 0;
	while (i < map->size->x * map->size->y)
	{
		pos.x = ((i % map->size->x) * image->size->x);
		pos.y = ((i / map->size->x) * image->size->y);
		set->draw_sub_bg(set, 1, pos);
		i++;
	}
}

void	map_init(t_place *set, void *data)
{
	t_map	map;

	map_set(&map);
	if (!set)
		return ;
	if (map_load(&map, data) != MAP_NO_ERROR)
	{
		map_pop(&map);
		set->gear->event &= ~(1 << MACHINE_RUNNING);
		return ;
	}
	if (map_validate(&map) != MAP_NO_ERROR)
	{
		map_pop(&map);
		set->gear->event &= ~(1 << MACHINE_RUNNING);
		return ;
	}
	if (image_load(set))
	{
		floor_load(set, &map);
		object_create(set, &map);
	}
	map_pop(&map);
}

void	user_init(t_place *set, void *data)
{
	map_init(set, data);
}
