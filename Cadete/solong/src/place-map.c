/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:39:50 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/05 18:31:48 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>
#include <stdio.h>

void	place_map_set(t_place *set, B32 id)
{
	t_image	*image;

	if (!set || !set->gear->image)
		return ;
	image = set->image_select(set, id);
	if (image)
		set->gear->bg->image = image;
}
