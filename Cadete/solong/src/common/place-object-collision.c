/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-object-collision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 02:35:44 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/18 02:38:26 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

t_object	*place_object_collision(t_place *set, t_object *selected)
{
	t_object	*current;
	t_chained	*search;

	search = set->gear->object;
	while (search)
	{
		current = search->data;
		if (current->id != selected->id && object_collision(selected, current))
			return (current);
		search = search->next;
	}
	return (NULL);
}
