/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object-route-down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:35:49 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/19 17:50:36 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object_of.h>

static t_status	sw_dir(t_object *obj)
{
	obj->status |= (1 << OBJECT_MOVING);
	obj->where = SOUTHWEST;
	obj->pos->x -= obj->vel->x;
	obj->pos->y += obj->vel->y;
	if (obj->pos->y >= obj->dest->y)
		obj->pos->y = obj->dest->y;
	if (obj->pos->x <= obj->dest->x)
	{
		obj->status &= ~(1 << OBJECT_MOVING);
		obj->pos->x = obj->dest->x;
		return (On);
	}
	return (Off);
}

static t_status	se_dir(t_object *obj)
{
	obj->status |= (1 << OBJECT_MOVING);
	obj->where = SOUTHEAST;
	obj->pos->x += obj->vel->x;
	obj->pos->y += obj->vel->y;
	if (obj->pos->y >= obj->dest->y)
		obj->pos->y = obj->dest->y;
	if (obj->pos->x >= obj->dest->x)
	{
		obj->status &= ~(1 << OBJECT_MOVING);
		obj->pos->x = obj->dest->x;
		return (On);
	}
	return (Off);
}

static t_status	south_dir(t_object *obj)
{
	obj->where = SOUTH;
	obj->status |= (1 << OBJECT_MOVING);
	obj->pos->y += obj->vel->y;
	if (obj->pos->y >= obj->dest->y)
	{
		obj->status &= ~(1 << OBJECT_MOVING);
		obj->pos->y = obj->dest->y;
		return (On);
	}
	return (Off);
}

t_status	down_dir(t_object *obj)
{
	if (obj->pos->y < obj->dest->y)
	{
		if (obj->pos->x == obj->dest->x)
			return (south_dir(obj));
		if (obj->pos->x < obj->dest->x)
			return (se_dir(obj));
		if (obj->pos->x > obj->dest->x)
			return (sw_dir(obj));
	}
	return (Off);
}
