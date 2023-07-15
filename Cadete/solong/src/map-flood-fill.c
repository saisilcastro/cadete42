/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-flood-fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:55:11 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/14 21:52:19 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>
#include <stdio.h>

void	flood_fill(char **map, t_vi2d size, t_vi2d begin)
{
	if (*(*(map + begin.y) + begin.x) == '1'
		|| *(*(map + begin.y) + begin.x) == 'F'
		|| *(*(map + begin.y) + begin.x) == 'T')
		return ;
	*(*(map + begin.y) + begin.x) = 'T';
	if (begin.y + 1 < size.y)
		flood_fill(map, size, vi2d_start(begin.x, begin.y + 1));
	if (begin.y - 1 > 0)
		flood_fill(map, size, vi2d_start(begin.x, begin.y - 1));
	if (begin.x + 1 < size.x)
		flood_fill(map, size, vi2d_start(begin.x + 1, begin.y));
	if (begin.x - 1 > 0)
		flood_fill(map, size, vi2d_start(begin.x - 1, begin.y));
}

t_map_error	map_flood_fill(t_map *map)
{
	B32	i;

	if (!map)
		return (MAP_NOT_CREATED);
	flood_fill(map->validator, map->size[0], map->begin[0]);
	i = -1;
	while (++i < map->size->x * map->size->y)
	{
		printf("%c", *(*(map->validator + (i / map->size->x)) + (i % map->size->x)));
		if ((i % map->size->x + 1) == map->size->x)
			printf("\n");
	}
	return (MAP_NO_ERROR);
}
