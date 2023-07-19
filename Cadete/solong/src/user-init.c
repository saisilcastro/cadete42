/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:38:43 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/18 23:22:43 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	image_load(t_place *set)
{
	if (!set)
		return ;
	set->image_load_last(set, "img/tileset/grass.xpm", 1);
	set->image_load_last(set, "img/tileset/tree.xpm", 2);
	set->image_load_last(set, "img/tileset/jewel.xpm", 3);
	set->image_load_last(set, "img/tileset/exit.xpm", 4);
	set->image_load_last(set, "img/sprite/twinsen-front-up.xpm", 5);
	set->image_load_last(set, "img/sprite/croma.xpm", 6);
}

static void	floor_load(t_place *set, t_map *map)
{
	B32		i;
	t_vi2d	pos;
	t_image	*image;

	image = set->image_select(set, 1);
	if (!set || !image)
		return ;
	set->map_create(set, 0,
		vi2d_start(image->size->x * map->size->x,
			image->size->y * map->size->y));
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
	map_load(&map, data);
	if (map_validate(&map) != MAP_NO_ERROR)
	{
		map_pop(&map);
		set->gear->event &= ~(1 << MACHINE_RUNNING);
		return ;
	}
	image_load(set);
	floor_load(set, &map);
	object_create(set, &map);
	map_pop(&map);
}

void	user_init(t_place *set, void *data)
{
	map_init(set, data);
}
