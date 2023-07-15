/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object-of.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:44:58 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/14 16:27:05 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <object_of.h>
#define VEL_X 6
#define VEL_Y 6

t_object	object_start(B32 id, B8 *name, t_image *image)
{
	t_object	set;

	set.id = id;
	set.name = name;
	set.pos[0] = vi2d_start(0, 0);
	set.vel[0] = vi2d_start(VEL_X, VEL_Y);
	set.route[0] = vi2d_start(0, 0);
	set.axis[0] = vi2d_start(0, 0);
	set.zoom[0] = vf2d_start(0, 0);
	set.image = image;
	set.angle = 0;
	set.where = NOWHERE;
	return (set);
}

t_object	*object_set(B32 id, B8 *name, t_vi2d pos, t_image *image)
{
	t_object	*set;

	set = (t_object *)malloc(sizeof(t_object));
	if (!set)
		return (NULL);
	set->id = id;
	set->name = name;
	set->pos[0] = vi2d_start(pos.x, pos.y);
	set->vel[0] = vi2d_start(VEL_X, VEL_Y);
	set->route[0] = vi2d_start(0, 0);
	set->axis[0] = vi2d_start(0, 0);
	set->zoom[0] = vf2d_start(0, 0);
	set->image = image;
	set->angle = 0;
	set->where = NOWHERE;
	return (set);
}

void	object_pop(t_object *set)
{
	if (!set)
		return ;
	free(set);
}
