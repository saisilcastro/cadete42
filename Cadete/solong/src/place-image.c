/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:45:37 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/04 05:33:13 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

void	place_image_pop(t_place *set)
{
	t_chained	*next;

	if (!set)
		return ;
	while (set->gear->image)
	{
		next = set->gear->image->next;
		image_pop(set->gear->image->data);
		free(set->gear->image);
		set->gear->image = next;
	}
}
