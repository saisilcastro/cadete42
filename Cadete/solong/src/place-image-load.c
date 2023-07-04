/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-image-load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:14:55 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/03 16:45:26 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

void    place_image_load_first(t_place *set, B8 *path, B32 id)
{
    t_image     *image;

    if (!set || place_image_select(set, id) || !path)
        return ;
    switch (set->gear->up->system)
    {
        case SYSTEM_CONSOLE:
        break ;
        case SYSTEM_MINILIBX:
        {
            image = image_of_push(id, NULL, vi2d_start(16, 16));
            if (image)
            {
                mlx_image_load(image, set->gear->plugin, path);
                chained_next_first(&set->gear->image, chained_push(image));
            }
        }
        break;
    }
}

void    place_image_load_last(t_place *set, B8 *path, B32 id)
{
    t_image *image;

    if (!set || place_image_select(set, id))
    {
        (void)path;
        return ;
    }
    switch (set->gear->up->system)
    {
        case SYSTEM_CONSOLE:
        {
            image = image_of_push(id, NULL, vi2d_start(16, 16));
            if (image)
                chained_next_last(&set->gear->image, chained_push(image));
        }
        break ;
        case SYSTEM_MINILIBX:
        {
            image = image_of_push(id, NULL, vi2d_start(16, 16));
            if (image)
            {
                mlx_image_load(image, ((t_mlx_plugin *)set->gear->plugin)->mlx, path);
                chained_next_last(&set->gear->image, chained_push(image));
            }
        }
        break;
    }
}

t_image *place_image_select(t_place *set, B32 id)
{
    t_chained   *update;
    t_image     *image;

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