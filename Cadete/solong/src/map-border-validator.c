/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-border-validator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:11:34 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/14 19:33:57 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>

static t_map_error	top_bottom_validation(t_map *map, B32 x, B32 y)
{
	while (++y < 2)
	{
		x = -1;
		while (++x < map->size->x)
		{
			if (y == 0 && *(*(map->data + 0) + x) != '1')
				return (MAP_INVALID_TOP_BOTTOM);
			if (y == 1 && *(*(map->data + map->size->y - 1) + x) != '1')
				return (MAP_INVALID_TOP_BOTTOM);
		}
	}
	return (MAP_NO_ERROR);
}

static t_map_error	between_validation(t_map *map, B32 x, B32 y)
{
	while (++x < 2)
	{
		y = 0;
		while (++y < map->size->y - 1)
		{
			if (x == 0 && *(*(map->data + y) + 0) != '1')
				return (MAP_INVALID_MID_BORDER);
			if (x == 1 && *(*(map->data + y) + map->size->x - 1) != '1')
				return (MAP_INVALID_MID_BORDER);
		}
	}
	return (MAP_NO_ERROR);
}

t_map_error	map_border_validator(t_map *map)
{
	B32			x;
	B32			y;
	t_map_error	error;

	if (!map)
		return (MAP_NOT_CREATED);
	x = -1;
	y = -1;
	error = top_bottom_validation(map, x, y);
	if (error != MAP_NO_ERROR)
		return (error);
	x = -1;
	error = between_validation(map, x, y);
	if (error != MAP_NO_ERROR)
		return (error);
	return (MAP_NO_ERROR);
}
