/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:30:52 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/12 18:46:54 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>
#include <stdio.h>

static t_status	valid_border(t_map *map)
{
	B32	x;
	B32	y;

	if (!map)
		return (Off);
	y = -1;
	while (++y < 2)
	{
		x = -1;
		while (++x < map->size->x)
		{
			if (y == 0 && *(*(map->data + 0) + x) != '1')
				return (Off);
			if (y == 1 && *(*(map->data + map->size->y - 1) + x) != '1')
				return (Off);
		}
	}
	return (On);
}

t_status	map_validate(t_map *map)
{
	if (!map)
		return (Off);
	if (valid_border(map))
		return (On);
	return (Off);
}
