/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object-route-down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:35:49 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/17 20:11:34 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object_of.h>

static t_status	sw_dir(t_object *obj)
{
	obj->status |= (1 << OBJECT_MOVING);
	obj->where = SOUTHWEST;
	obj->dest->x -= obj->vel->x;
	obj->dest->y += obj->vel->y;
	if (obj->dest->y >= obj->pos->y)
		obj->dest->y = obj->pos->y;
	if (obj->dest->x <= obj->pos->x)
	{
		obj->status &= ~(1 << OBJECT_MOVING);
		obj->dest->x = obj->pos->x;
		return (On);
	}
	return (Off);
}

static t_status	se_dir(t_object *obj)
{
	obj->status |= (1 << OBJECT_MOVING);
	obj->where = SOUTHEAST;
	obj->dest->x += obj->vel->x;
	obj->dest->y += obj->vel->y;
	if (obj->dest->y >= obj->pos->y)
		obj->dest->y = obj->pos->y;
	if (obj->dest->x >= obj->pos->x)
	{
		obj->status &= ~(1 << OBJECT_MOVING);
		obj->dest->x = obj->pos->x;
		return (On);
	}
	return (Off);
}

static t_status	south_dir(t_object *obj)
{
	obj->where = SOUTH;
	obj->status |= (1 << OBJECT_MOVING);
	obj->dest->y += obj->vel->y;
	if (obj->dest->y >= obj->pos->y)
	{
		obj->status &= ~(1 << OBJECT_MOVING);
		obj->dest->y = obj->pos->y;
		return (On);
	}
	return (Off);
}

t_status	down_dir(t_object *obj)
{
	if (obj->dest->y < obj->pos->y)
	{
		if (obj->dest->x == obj->pos->x)
			return (south_dir(obj));
		if (obj->dest->x < obj->pos->x)
			return (se_dir(obj));
		if (obj->dest->x > obj->pos->x)
			return (sw_dir(obj));
	}
	return (Off);
}
