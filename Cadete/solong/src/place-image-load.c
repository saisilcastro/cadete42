/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-image-load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:14:55 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/05 18:03:42 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

void	place_image_load_first(t_place *set, B8 *path, B32 id)
{
	t_image	*image;

	if (!set || place_image_select(set, id) || !path)
		return ;
	if (set->gear->up->system == SYSTEM_CONSOLE)
		return ;
	else if (set->gear->up->system == SYSTEM_MINILIBX)
	{
		image = image_of_push(id, NULL, vi2d_start(16, 16));
		if (image)
		{
			mlx_image_load(image, set->gear->plugin, path);
			chained_next_first(&set->gear->image, chained_push(image));
		}
	}
}

void	place_image_load_last(t_place *set, B8 *path, B32 id)
{
	t_image			*image;
	t_mlx_plugin	*plugin;

	if (!set || place_image_select(set, id))
		return ;
	if (set->gear->up->system == SYSTEM_MINILIBX)
	{
		plugin = set->gear->plugin;
		image = image_of_push(id, NULL, vi2d_start(16, 16));
		if (image)
		{
			if (mlx_image_load(image, plugin->mlx, path))
				chained_next_last(&set->gear->image, chained_push(image));
			else
			{
				image_of_pop(image, plugin->mlx, set->gear->up[0]);
				free(image);
			}
		}
	}
}

t_image	*place_image_select(t_place *set, B32 id)
{
	t_chained	*update;
	t_image		*image;

	if (!set)
		return (NULL);
	update = set->gear->image;
	while (update)
	{
		image = update->data;
		if (image->id == id)
			return (image);
		update = update->next;
	}
	return (NULL);
}
