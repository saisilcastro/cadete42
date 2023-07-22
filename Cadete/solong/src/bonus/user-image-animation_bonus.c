/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-image-animation_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:21:42 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/21 13:55:37 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	image_animation(t_place *set, t_object *obj)
{
	if (!set || !obj)
		return ;
	if (obj->where == NORTH)
		obj->image = set->image_select(set, TWINSEN_BACK);
	else if (obj->where == NORTHEAST)
		obj->image = set->image_select(set, TWINSEN_DG_BACK);
	else if (obj->where == NORTHWEST)
		obj->image = set->image_select(set, TWINSEN_DG_BACK_LEFT);
	else if (obj->where == SOUTH)
		obj->image = set->image_select(set, TWINSEN_FRONT);
	else if (obj->where == SOUTHEAST)
		obj->image = set->image_select(set, TWINSEN_DG_FT);
	else if (obj->where == SOUTHWEST)
		obj->image = set->image_select(set, TWINSEN_DG_FT_LEFT);
	else if (obj->where == EAST)
		obj->image = set->image_select(set, TWINSEN_SIDE);
	else if (obj->where == WEST)
		obj->image = set->image_select(set, TWINSEN_SIDE_LEFT);
}
