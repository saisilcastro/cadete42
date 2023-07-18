/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-object-image-create.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:06:43 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/17 18:07:42 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	image_create(t_place *set, t_map *map, t_vi2d *pos, t_vi2d id)
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
