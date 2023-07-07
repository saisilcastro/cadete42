/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:38:43 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/07 11:38:34 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	image_load(t_place *set)
{
	set->image_load_last(set, "img/background/rock.xpm", 0);
	set->image_load_last(set, "img/sprite/croma.xpm", 1);
	set->image_load_last(set, "img/sprite/twinsen-front-up.xpm", 2);
}

static void	object_create(t_place *set)
{
	t_vi2d	pos;
	B32		id;

	id = 0;
	while (id < 20)
	{
		if (id == 0)
		{
			pos.x = set->gear->bg->pos->x + (set->gear->size->x / 2);
			pos.y = set->gear->bg->pos->y + (set->gear->size->y / 2);
			set->object_next_first(set, id, vi2d_start(pos.x, pos.y),
				set->image_select(set, 2));
		}
		else
		{
			pos.x = rand() % (set->gear->bg->image->size->x);
			pos.y = rand() % (B32)(set->gear->bg->image->size->y / 1.5);
			set->object_next_last(set, id, vi2d_start(pos.x, pos.y),
				set->image_select(set, 1));
		}
		id++;
	}
}

void	user_init(t_place *place, void *data)
{
	if (!place || data)
		return ;
	image_load(place);
	place->gear->bg->pos[0] = vi2d_start(100, 900);
	place->map_set(place, 0);
	object_create(place);
}
