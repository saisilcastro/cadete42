/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:03:07 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/19 18:03:07 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>
#include <stdio.h>
#include <string.h>

static void	hero_control(t_place *set, t_object *hero)
{
	place_camera_object(set, hero);
	if (set->key_down(set, KEY_LEFT))
		hero->dest->x -= hero->vel->x;
	else if (set->key_down(set, KEY_RIGHT))
		hero->dest->x += hero->vel->x;
	else if (set->key_down(set, KEY_UP))
		hero->dest->y -= hero->vel->y;
	else if (set->key_down(set, KEY_DOWN))
		hero->dest->y += hero->vel->y;
}

t_status	place_block_move(t_place *set, t_object *hero)
{
	t_object	fake_hero;
	t_object	*collider;

	object_clone(hero, &fake_hero);
	hero_control(set, &fake_hero);
	object_route(&fake_hero);
	collider = place_object_collision(set, &fake_hero);
	if (collider && !strcmp(collider->name, "block"))
		return (On);
	return (Off);
}

void	hero_update(t_place *set, t_object *object)
{
	t_object	*collider;

	if (object->id == set->hero_id)
	{
		if (place_block_move(set, object))
			return ;
		hero_control(set, object);
		object_route(object);
		collider = place_object_collision(set, object);
		if (collider && !strcmp(collider->name, "collect"))
		{
			collider->status &= ~(1 << OBJECT_VISIBLE);
			set->collect->current++;
			printf("%i %i\n", set->collect->current, set->collect->max);
		}
		else if (collider && !strcmp(collider->name, "exit"))
			object->status &= ~(1 << OBJECT_VISIBLE);
	}
}

static void	object_update(t_place *set)
{
	t_chained	*update;
	t_object	*object;

	update = set->gear->object;
	while (update)
	{
		object = update->data;
		hero_update(set, object);
		if (!strcmp(object->name, "exit"))
		{
			if (set->collect->current == set->collect->max)
				object->status |= (1 << OBJECT_VISIBLE);
		}
		update = update->next;
	}
}

int	user_update(t_place *set)
{
	if (!set)
		return (0);
	if (set->key_down(set, KEY_ESC))
		set->stop(set);
	object_update(set);
	set->draw_bg(set);
	return (!set->destroy(set));
}
