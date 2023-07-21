/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-image-load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:14:55 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/20 09:29:20 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

t_status	place_image_load_first(t_place *set, char *path, int id)
{
	t_image			*image;

	if (!set || place_image_select(set, id) || !path)
		return (Off);
	if (set->gear->up->system == SYSTEM_MINILIBX)
	{
		image = image_of_push(id, NULL, vi2d_start(16, 16));
		if (image)
		{
			if (mlx_image_load(image,
					((t_mlx_plugin *)set->gear->plugin)->mlx, path))
			{
				chained_next_first(&set->gear->image, chained_push(image));
				return (On);
			}
			else
			{
				image_of_pop(image,
					((t_mlx_plugin *)set->gear->plugin)->mlx, set->gear->up[0]);
				free(image);
			}
		}
	}
	return (Off);
}

t_status	place_image_load_last(t_place *set, char *path, int id)
{
	t_image			*image;

	if (!set || place_image_select(set, id))
		return (Off);
	if (set->gear->up->system == SYSTEM_MINILIBX)
	{
		image = image_of_push(id, NULL, vi2d_start(16, 16));
		if (image)
		{
			if (mlx_image_load(image,
					((t_mlx_plugin *)set->gear->plugin)->mlx, path))
			{
				chained_next_last(&set->gear->image, chained_push(image));
				return (On);
			}
			else
			{
				image_of_pop(image,
					((t_mlx_plugin *)set->gear->plugin)->mlx, set->gear->up[0]);
				free(image);
			}
		}
	}
	return (Off);
}

t_image	*place_image_select(t_place *set, int id)
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
