/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-object-pop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:16:05 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/16 01:06:06 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

static void	remove_with_prev(t_chained **upd, t_chained **next)
{
	t_chained	*prev;

	prev = (*upd)->prev;
	free(*upd);
	*upd = prev;
	(*upd)->next = *next;
	if (*next)
		(*next)->prev = *upd;
}

void	place_object_pop(t_chained **set, t_object *rem)
{
	t_chained	*upd;
  	t_chained	*next;

	upd = *set;
	while (upd)
	{
		next = upd->next;
		if (((t_object *)upd->data)->id == rem->id)
		{
			if (!upd->prev)
			{
				free(*set);
				*set = next;
				break ;
			}
			remove_with_prev(&upd, &next);
			break ;
		}
		upd = next;
	}
}
