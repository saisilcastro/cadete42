/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:01:28 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/15 13:09:24 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

void    place_camera_object(t_place *set, t_object *obj)
{
    t_vi2d  pos;
    if (!set)
        return ;
    pos.x = obj->pos->x - ((set->gear->size->x - obj->image->size->x) * 0.5);
    pos.y = obj->pos->y - ((set->gear->size->y - obj->image->size->y) * 0.5);
    set->gear->bg->pos->x = pos.x;
    set->gear->bg->pos->y = pos.y;
}