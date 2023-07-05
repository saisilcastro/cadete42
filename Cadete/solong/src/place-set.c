/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:22:54 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/04 13:44:54 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

static void	place_function(t_place *set);

void	place_set(t_place *set, t_SystemSet up, t_vi2d size)
{
	if (!set)
		return ;
	machine_set(set->gear, up, "machine", vi2d_start(size.x, size.y));
	place_function(set);
}

static t_STATUS	place_start(t_place *set)
{
	if (!set)
		return (Off);
	return (machine_start(set->gear));
}

t_STATUS	place_key_get(t_place *set, B32 map);

static void	place_function(t_place *set)
{
	if (!set)
		return ;
	set->start = place_start;
	set->image_select = place_image_select;
	set->image_load_first = place_image_load_first;
	set->image_load_last = place_image_load_last;
	set->map_set = place_map_set;
	set->init = NULL;
	set->key_down = place_key_get;
	set->run = place_run;
	set->update = NULL;
	set->stop = place_stop;
	set->destroy = place_destroy;
	set->pop = place_pop;
}
