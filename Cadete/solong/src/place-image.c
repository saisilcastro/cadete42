/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:45:37 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/20 00:16:37 by lde-cast         ###   ########.fr       */
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
		image_of_pop(set->gear->image->data,
			((t_mlx_plugin *)set->gear->plugin)->mlx, set->gear->up[0]);
		free(set->gear->image);
		set->gear->image = next;
	}
}
