/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:30:18 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/16 00:50:48 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

t_object	*place_object_select(t_place *set, B32 id)
{
	t_chained	*update;
	t_object	*object;

	if (!set || !set->gear->object)
		return (NULL);
	update = set->gear->object;
	while (update)
	{
		object = update->data;
		if (object && object->id == id)
			return (object);
		update = update->next;
	}
	return (NULL);
}

void	place_object_next_first(t_place *set, t_object *obj)
{
	if (!set || !obj || place_object_select(set, obj->id))
		return ;
	chained_next_first(&set->gear->object, chained_push(obj));
}

void	place_object_next_last(t_place *set, t_object *obj)
{
	if (!set || !obj || place_object_select(set, obj->id))
		return ;
	chained_next_last(&set->gear->object, chained_push(obj));
}
