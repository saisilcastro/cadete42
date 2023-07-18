/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object-route-up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:00:05 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/17 20:14:04 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object_of.h>

static t_status	north_dir(t_object *obj)
{
	obj->where = NORTH;
	obj->status |= (1 << OBJECT_MOVING);
	obj->dest->y -= obj->vel->y;
	if (obj->dest->y <= obj->pos->y)
	{
		obj->status &= ~(1 << OBJECT_MOVING);
		obj->dest->y = obj->pos->y;
		return (On);
	}
	return (Off);
}

static t_status	ne_dir(t_object *obj)
{
	obj->where = NORTHEAST;
	obj->status |= (1 << OBJECT_MOVING);
	obj->dest->x += obj->vel->x;
	obj->dest->y -= obj->vel->y;
	if (obj->dest->y <= obj->pos->y)
		obj->dest->y = obj->pos->y;
	if (obj->dest->x >= obj->pos->x)
	{
		obj->status &= ~(1 << OBJECT_MOVING);
		obj->dest->x = obj->pos->x;
		return (On);
	}
	return (Off);
}

static t_status	nw_dir(t_object *obj)
{
	obj->where = NORTHWEST;
	obj->status |= (1 << OBJECT_MOVING);
	obj->dest->x -= obj->vel->x;
	obj->dest->y -= obj->vel->y;
	if (obj->dest->y <= obj->pos->y)
		obj->dest->y = obj->pos->y;
	if (obj->dest->x <= obj->pos->x)
	{
		obj->status &= ~(1 << OBJECT_MOVING);
		obj->dest->x = obj->pos->x;
		return (On);
	}
	return (Off);
}

t_status	up_dir(t_object *obj)
{
	if (obj->dest->y > obj->pos->y)
	{
		if (obj->dest->x == obj->pos->x)
			return (north_dir(obj));
		if (obj->dest->x < obj->pos->x)
			return (ne_dir(obj));
		if (obj->dest->x > obj->pos->x)
			return (nw_dir(obj));
	}
	return (Off);
}
