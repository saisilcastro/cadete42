/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:39:50 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/19 16:56:50 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

void	place_map_create(t_place *set, B32 id, t_vi2d size)
{
	t_mlx_plugin	*plugin;
	t_image			*image;

	if (!set || !size.x || !size.y || !set->gear->plugin)
		return ;
	if (set->gear->up->system == SYSTEM_MINILIBX && id > -1)
	{
		image = image_of_push(id, NULL, size);
		if (image)
		{
			plugin = set->gear->plugin;
			mlx_create_image(image, plugin->mlx);
			chained_next_last(&set->gear->image, chained_push(image));
			set->map_set(set, 0);
		}
	}
}

void	place_map_set(t_place *set, B32 id)
{
	t_image	*image;

	if (!set || !set->gear->image)
		return ;
	image = set->image_select(set, id);
	if (image)
		set->gear->bg->image = image;
}
