/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:03:07 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/06 23:51:13 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

static void	object_update(t_place *set)
{
	t_chained	*update;
	t_object	*object;

	update = set->gear->object;
	while (update)
	{
		object = update->data;
		if (object->id == 0)
		{
			if (set->key_down(set, KEY_LEFT))
				object->pos->x -= object->vel->x;
			if (set->key_down(set, KEY_RIGHT))
				object->pos->x += object->vel->x;
			if (set->key_down(set, KEY_UP))
				object->pos->y -= object->vel->y;
			if (set->key_down(set, KEY_DOWN))
				object->pos->y += object->vel->y;
		}
		update = update->next;
	}
}

int	user_update(t_place *set)
{
	t_mlx_plugin	*plugin;

	if (!set)
		return (0);
	plugin = NULL;
	plugin = set->gear->plugin;
	if (!plugin)
		return (0);
	if (set->key_down(set, KEY_A))
		set->gear->bg->pos->x -= set->gear->bg->vel->x;
	if (set->key_down(set, KEY_D))
		set->gear->bg->pos->x += set->gear->bg->vel->x;
	if (set->key_down(set, KEY_W))
		set->gear->bg->pos->y -= set->gear->bg->vel->y;
	if (set->key_down(set, KEY_S))
		set->gear->bg->pos->y += set->gear->bg->vel->y;
	object_update(set);
	set->draw_bg(set);
	set->draw(set);
	return (!set->destroy(set));
}
