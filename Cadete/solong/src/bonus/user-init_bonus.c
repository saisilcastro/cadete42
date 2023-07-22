/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:28:04 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/21 16:43:41 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

static void	path_image(char *path[ENEMY_FOUR + 1])
{
	*(path + GRASS_IMG - 1) = "img/tileset/grass.xpm";
	*(path + TREE_IMG - 1) = "img/tileset/tree.xpm";
	*(path + JEWEL_IMG - 1) = "img/tileset/jewel.xpm";
	*(path + EXIT_IMG - 1) = "img/tileset/exit.xpm";
	*(path + TWINSEN_FRONT - 1) = "img/sprite/twinsen-ft-up.xpm";
	*(path + TWINSEN_DG_FT - 1) = "img/sprite/twinsen-dg-ft-up.xpm";
	*(path + TWINSEN_DG_FT_LEFT - 1) = "img/sprite/twinsen-dg-ft-left.xpm";
	*(path + TWINSEN_BACK - 1) = "img/sprite/twinsen-back-up.xpm";
	*(path + TWINSEN_DG_BACK - 1) = "img/sprite/twinsen-dg-back.xpm";
	*(path + TWINSEN_DG_BACK_LEFT - 1) = "img/sprite/twinsen-dg-back-left.xpm";
	*(path + TWINSEN_SIDE - 1) = "img/sprite/twinsen-side-up.xpm";
	*(path + TWINSEN_SIDE_LEFT - 1) = "img/sprite/twinsen-side-up-left.xpm";
	*(path + ENEMY_ONE - 1) = "img/sprite/mage1.xpm";
	*(path + ENEMY_TWO - 1) = "img/sprite/mage2.xpm";
	*(path + ENEMY_THREE - 1) = "img/sprite/mage3.xpm";
	*(path + ENEMY_FOUR - 1) = "img/sprite/mage4.xpm";
}

static t_status	image_load(t_place *set)
{
	char		*path[ENEMY_FOUR + 1];
	int			i;

	if (!set)
		return (Off);
	path_image(path);
	i = -1;
	while (++i < ENEMY_FOUR)
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

	image = set->image_select(set, GRASS_IMG);
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
		set->draw_sub_bg(set, GRASS_IMG, pos);
		i++;
	}
}

void	user_init(t_place *set, void *data)
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
