/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:30:18 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/06 21:38:17 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

t_status	place_object_select(t_place *set, B32 id)
{
	t_chained	*update;
	t_object	*object;

	if (!set || !set->gear->object)
		return (Off);
	update = set->gear->object;
	while (update)
	{
		object = update->data;
		if (object && object->id == id)
			return (On);
		update = update->next;
	}
	return (Off);
}

void	place_object_next_first(t_place *set, B32 id,
	t_vi2d pos, t_image *image)
{
	t_object	*object;

	if (!set || place_object_select(set, id))
		return ;
	object = object_set(id, "object", pos, image);
	if (object)
		chained_next_first(&set->gear->object, chained_push(object));
}

void	place_object_next_last(t_place *set, B32 id,
	t_vi2d pos, t_image *image)
{
	t_object	*object;

	if (!set || place_object_select(set, id))
		return ;
	object = object_set(id, "object", pos, image);
	if (object)
		chained_next_last(&set->gear->object, chained_push(object));
}
