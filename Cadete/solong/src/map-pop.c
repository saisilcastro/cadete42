/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:57:00 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/12 16:09:12 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>

void	map_pop(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	if (map->data)
	{
		while (*(map->data + i))
		{
			free(*(map->data + i));
			i++;
		}
		free(map->data);
	}
}
