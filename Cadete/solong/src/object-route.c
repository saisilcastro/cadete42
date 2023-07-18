/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object-route.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:07:04 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/17 19:49:03 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object_of.h>

t_status	object_route(t_object *obj)
{
	if (!obj)
		return (Off);
	if (obj->pos->x == obj->dest->x && obj->pos->y == obj->dest->y)
		return (On);
	return (up_dir(obj) || mid_dir(obj) || down_dir(obj));
}
