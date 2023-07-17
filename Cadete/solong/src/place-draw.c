/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:56:18 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/15 22:11:02 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

void	place_draw(t_place *set)
{
	t_chained	*update;
	t_object	*obj;

	if (!set)
		return ;
	update = set->gear->object;
	while (update)
	{
		obj = update->data;
		if ((obj->status & (1 << OBJECT_VISIBLE)) != 0)
			machine_draw(set->gear, update->data);
		update = update->next;
	}
}
