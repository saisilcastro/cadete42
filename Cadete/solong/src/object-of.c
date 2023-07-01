/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object-of.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:44:58 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/30 19:53:10 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <object_of.h>

t_object	object_start(B32 id, B8 *name, t_image *image)
{
	t_object	set;

	set.id = id;
	set.name = name;
	set.pos[0] = vi2d_start(0, 0);
	set.vel[0] = vi2d_start(1, 1);
	set.route[0] = vi2d_start(0, 0);
	set.axis[0] = vi2d_start(0, 0);
	set.zoom[0] = vf2d_start(0, 0);
	set.image = image;
	set.angle = 0;
	set.where = NOWHERE;
	return (set);
}

t_object	*object_set(B32 id, B8 *name, t_image *image)
{
	t_object	*set;

	set = (t_object *)malloc(sizeof(t_object));
	if (!set)
		return (NULL);
	set->id = id;
	set->name = name;
	set->pos[0] = vi2d_start(0, 0);
	set->vel[0] = vi2d_start(1, 1);
	set->route[0] = vi2d_start(0, 0);
	set->axis[0] = vi2d_start(0, 0);
	set->zoom[0] = vf2d_start(0, 0);
	set->image = image;
	set->angle = 0;
	set->where = NOWHERE;
	return (set);
}
