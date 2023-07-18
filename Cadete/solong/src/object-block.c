/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object-block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:41:37 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/17 23:02:41 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object_of.h>
#define STEPBACK 1

static t_status	object_straight_dir(t_object *obj)
{
	if (obj->where == NORTH)
		obj->pos->y += obj->vel->y;
	else if (obj->where == SOUTH)
	{
		obj->pos->y -= obj->vel->y;
		return (On);
	}
	else if (obj->where == WEST)
	{
		obj->pos->x += obj->vel->x;
		return (On);
	}
	else if (obj->where == EAST)
	{
		obj->pos->x -= obj->vel->x;
		return (On);
	}
	return (Off);
}

static t_status	object_diagonal_dir(t_object *obj)
{
	if (obj->where == NORTHEAST)
	{
		obj->pos->y += obj->vel->y;
		obj->pos->x -= obj->vel->x;
		return (On);
	}
	else if (obj->where == NORTHWEST)
	{
		obj->pos->y += obj->vel->y;
		obj->pos->x += obj->vel->x;
		return (On);
	}
	else if (obj->where == SOUTHEAST)
	{
		obj->pos->y -= obj->vel->y;
		obj->pos->x -= obj->vel->x;
		return (On);
	}
	else if (obj->where == SOUTHWEST)
	{
		obj->pos->y -= obj->vel->y;
		obj->pos->x += obj->vel->x;
		return (On);
	}
	return (Off);
}

t_status	object_block(t_object *obj)
{
	return (object_straight_dir(obj) || object_diagonal_dir(obj));
}
