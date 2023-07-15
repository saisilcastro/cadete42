/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:03:47 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/14 20:04:22 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>

void	map_set(t_map *map)
{
	if (!map)
		return ;
	map->data = NULL;
	map->validator = NULL;
	map->begin[0] = vi2d_start(0, 0);
	map->pos[0] = vi2d_start(0, 0);
	map->size[0] = vi2d_start(0, 0);
	map->collectable = 0;
}
