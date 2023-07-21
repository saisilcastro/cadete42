/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:03:47 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/16 00:40:47 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>

void	map_set(t_map *map)
{
	map->data = NULL;
	map->validator = NULL;
	map->begin[0] = vi2d_start(0, 0);
	map->pos[0] = vi2d_start(0, 0);
	map->size[0] = vi2d_start(0, 0);
	map->collectable = 0;
}
