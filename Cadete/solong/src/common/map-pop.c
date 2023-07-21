/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:57:00 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/15 14:59:43 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>

void	map_pop(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->data)
	{
		i = -1;
		while (*(map->data + ++i))
			free(*(map->data + i));
		free(map->data);
	}
	if (map->validator)
	{
		i = -1;
		while (*(map->validator + ++i))
			free(*(map->validator + i));
		free(map->validator);
	}
}
