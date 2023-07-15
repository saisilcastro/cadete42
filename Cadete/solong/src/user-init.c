/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:38:43 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/14 17:30:08 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <map_of.h>
#include <unistd.h>

static void	image_load(t_place *set)
{
	if (!set)
		return ;
	set->image_load_last(set, "img/background/rock.xpm", 0);
	set->image_load_last(set, "img/tileset/grass.xpm", 1);
	set->image_load_last(set, "img/tileset/tree.xpm", 2);
	set->image_load_last(set, "img/sprite/twinsen-front-up.xpm", 3);
	set->image_load_last(set, "img/sprite/croma.xpm", 4);
}

static void	object_create(t_place *set)
{
	t_vi2d	pos;
	B32		id;

	id = 0;
	while (id < 20)
	{
		if (id == 0)
		{
			pos.x = set->gear->bg->pos->x + (set->gear->size->x / 2);
			pos.y = set->gear->bg->pos->y + (set->gear->size->y / 2);
			set->object_next_last(set, id, vi2d_start(pos.x, pos.y),
				set->image_select(set, 3));
		}
		else
		{
			pos.x = rand() % (set->gear->bg->image->size->x);
			pos.y = rand() % (B32)(set->gear->bg->image->size->y / 1.5);
			set->object_next_last(set, id, vi2d_start(pos.x, pos.y),
				set->image_select(set, 4));
		}
		id++;
	}
}

void	user_init(t_place *place, void *data)
{
	t_map	map;

	map_set(&map);
	if (!place)
		return ;
	map_load(&map, data);
	if (map_validate(&map) != MAP_NO_ERROR)
	{
		map_pop(&map);
		place->gear->event &= ~(1 << MACHINE_RUNNING);
		return ;
	}
	image_load(place);
	place->gear->bg->pos[0] = vi2d_start(100, 2300);
	place->map_set(place, 0);
	object_create(place);
	map_pop(&map);
}
