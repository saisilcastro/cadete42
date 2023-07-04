/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:39:50 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/04 05:33:25 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

void	place_map_set(t_place *set, B32 id)
{
	t_image	*image;

	if (!set || !set->gear->image)
		return ;
	image = set->image_select(set, id);
	if (image)
		set->gear->bg->image = image;
}
