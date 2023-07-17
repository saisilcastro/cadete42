/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-object-create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:37:38 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/16 07:52:23 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void image_create(t_place *set, t_map *map, t_vi2d *pos, t_vi2d id)
{
	t_image	*image;

	if (!set || !map || !pos)
		return ;
	image = set->image_select(set, 1);
	if (image)
	{
		pos->x = (id.y % map->size->x) * image->size->x;
		pos->y = (id.y / map->size->x) * image->size->y;
	}
}

void	start_item_image(char *array)
{
	array[0] = '1';
	array[1] = 'C';
	array[2] = 'E';
	array[3] = 'P';
	array[4] = 2;
	array[5] = 3;
	array[6] = 4;
	array[7] = 5;
}

static void object_name(char **name, char letter)
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
	char		arr[8];

	start_item_image(arr);
	object_name(&name, arr[i.y]);
	image_create(set, map, &pos, vi2d_start(arr[i.y + 4], i.x));
	obj = object_set(i.x, name, pos, set->image_select(set, arr[i.y + 4]));
	if (arr[i.y] == 'P')
		set->hero_id = i.x;
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
		while (++id.y < 4)
		{
			if (*(*(map->data + (id.x / map->size->x))+ (id.x % map->size->x)) == array[id.y])
				object_treat(set, id, map);
		}
	}
}

void	object_create(t_place *set, t_map *map)
{
	char	array[8];

	if (!set || !map)
		return ;
	start_item_image(array);
	remain_load(set, map, array);
}