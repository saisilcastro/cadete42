/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-object-create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:37:38 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/19 20:01:40 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	start_item_image(char *array)
{
	array[0] = '1';
	array[1] = 'C';
	array[2] = 'E';
	array[3] = 'P';
	array[4] = 'F';
	array[5] = 2;
	array[6] = 3;
	array[7] = 4;
	array[8] = 5;
	array[9] = 6;
}

static void	object_name(char **name, char letter)
{
	if (letter == 'P')
		*name = "hero";
	else if (letter == 'E')
		*name = "exit";
	else if (letter == '1')
		*name = "block";
	else if (letter == 'C')
		*name = "collect";
	else
		*name = "enemy";
}

static void	object_treat(t_place *set, t_vi2d i, t_map *map)
{
	t_vi2d		pos;
	t_object	*obj;
	char		*name;
	char		arr[10];

	start_item_image(arr);
	object_name(&name, arr[i.y]);
	image_create(set, map, &pos, vi2d_start(arr[i.y + 5], i.x));
	obj = object_set(i.x, name, pos, set->image_select(set, arr[i.y + 5]));
	obj->dest[0] = vi2d_start(pos.x, pos.y);
	if (arr[i.y] == 'P')
	{
		obj->dest->y += 1;
		set->hero_id = i.x;
	}
	if (arr[i.y] == 'E')
		obj->status &= ~(1 << OBJECT_VISIBLE);
	if (arr[i.y] == 'C')
		set->collect->max++;
	set->object_next_last(set, obj);
}

static void	remain_load(t_place *set, t_map *map, char *array)
{
	t_vi2d	id;

	if (!set || !map)
		return ;
	id.x = -1;
	while (++id.x < map->size->x * map->size->y)
	{
		id.y = -1;
		while (++id.y < 5)
		{
			if (*(*(map->data + (id.x / map->size->x))
					+ (id.x % map->size->x)) == array[id.y])
				object_treat(set, id, map);
		}
	}
}

void	object_create(t_place *set, t_map *map)
{
	char	array[10];

	if (!set || !set->gear->bg->image || !map)
		return ;
	start_item_image(array);
	remain_load(set, map, array);
}
