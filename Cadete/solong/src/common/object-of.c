/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object-of.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:44:58 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/20 09:26:19 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <object_of.h>
#define VEL_X 4
#define VEL_Y 4

t_object	object_start(int id, char *name, t_image *image)
{
	t_object	set;

	set.id = id;
	set.name = name;
	set.pos[0] = vi2d_start(0, 0);
	set.vel[0] = vi2d_start(VEL_X, VEL_Y);
	set.dest[0] = vi2d_start(0, 0);
	set.axis[0] = vi2d_start(0, 0);
	set.zoom[0] = vf2d_start(0, 0);
	set.image = image;
	set.angle = 0;
	set.where = SOUTH;
	return (set);
}

t_object	*object_set(int id, char *name, t_vi2d pos, t_image *image)
{
	t_object	*set;

	set = (t_object *)malloc(sizeof(t_object));
	if (!set)
		return (NULL);
	set->id = id;
	set->name = name;
	set->pos[0] = vi2d_start(pos.x, pos.y);
	set->vel[0] = vi2d_start(VEL_X, VEL_Y);
	set->dest[0] = vi2d_start(pos.x, pos.x);
	set->axis[0] = vi2d_start(0, 0);
	set->zoom[0] = vf2d_start(0, 0);
	set->image = image;
	set->angle = 0;
	set->where = SOUTH;
	set->status = 0x1;
	return (set);
}

t_status	object_name_is(t_object *obj, char *name)
{
	char	*buffer;

	if (!obj || !name)
		return (Off);
	buffer = obj->name;
	while (*buffer && *name && *buffer == *name)
	{
		buffer++;
		name++;
	}
	if (!*buffer && !*name)
		return (On);
	return (Off);
}

void	object_clone(t_object *src, t_object *dest)
{
	dest->id = src->id;
	dest->name = src->name;
	dest->pos[0] = vi2d_start(src->pos->x, src->pos->y);
	dest->vel[0] = vi2d_start(src->vel->x, src->vel->y);
	dest->dest[0] = vi2d_start(src->pos->x, src->pos->y);
	dest->axis[0] = vi2d_start(src->axis->x, src->axis->y);
	dest->zoom[0] = vf2d_start(src->zoom->x, src->zoom->y);
	dest->image = src->image;
	dest->angle = src->angle;
	dest->where = src->where;
	dest->status = src->status;
}

void	object_pop(t_object *set)
{
	if (!set)
		return ;
	free(set);
}
