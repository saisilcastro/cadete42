/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:56:18 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/06 14:12:48 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

void	place_draw(t_place *set)
{
	t_chained	*update;

	if (!set)
		return ;
	update = set->gear->object;
	while (update)
	{
		machine_draw(set->gear, update->data);
		update = update->next;
	}
}
