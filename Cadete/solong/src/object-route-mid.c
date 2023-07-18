/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object-route-mid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:29:37 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/17 20:23:33 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object_of.h>
#include <stdio.h>

t_status	west_dir(t_object *obj)
{
	obj->status |= (1 << OBJECT_MOVING);
	obj->dest->x -= obj->vel->x;
	obj->where = WEST;
	if (obj->dest->x <= obj->pos->x)
	{
		obj->dest->x = obj->pos->x;
		obj->status &= ~(1 << OBJECT_MOVING);
		return (On);
	}
	return (Off);
}

t_status	east_dir(t_object *obj)
{
	obj->status |= (1 << OBJECT_MOVING);
	obj->dest->x += obj->vel->x;
	obj->where = EAST;
	if (obj->dest->x >= obj->pos->x)
	{
		obj->dest->x = obj->pos->x;
		obj->status &= ~(1 << OBJECT_MOVING);
		return (On);
	}
	return (Off);
}

t_status	mid_dir(t_object *obj)
{
	if (!obj)
		return (Off);
	if (obj->dest->y == obj->pos->y)
	{
		if (obj->dest->x < obj->pos->x)
			return (east_dir(obj));
		if (obj->dest->x > obj->pos->x)
			return (west_dir(obj));
	}
	return (Off);
}
