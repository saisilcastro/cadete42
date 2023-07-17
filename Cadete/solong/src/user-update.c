/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:03:07 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/16 08:19:53 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>
#include <stdio.h>
#include <string.h>

static t_object	*place_collision(t_chained *update, t_object *hero)
{
	t_object	*obj;
	t_chained	*current;

	current = update;
	while (current)
	{
		obj = current->data;
		if (obj->id != hero->id && object_collision(hero, obj))
			return (obj);
		current = current->next;
	}
	return (NULL);
}

static void	hero_control(t_place *set, t_object *hero)
{
	place_camera_object(set, hero);
	if (set->key_down(set, KEY_A))
		hero->pos->x -= hero->vel->x;
	if (set->key_down(set, KEY_D))
		hero->pos->x += hero->vel->x;
	if (set->key_down(set, KEY_W))
		hero->pos->y -= hero->vel->y;
	if (set->key_down(set, KEY_S))
		hero->pos->y += hero->vel->y;
}

void	hero_update(t_place *set, t_object *object)
{
	t_object	*collider;

	if (object->id == set->hero_id)
	{
		hero_control(set, object);
		collider = place_collision(set->gear->object, object);
		if (collider && !strcmp(collider->name, "collect"))
		{
			collider->status &= ~(1 << OBJECT_VISIBLE);
			set->collect->current++;
			printf("%i %i\n", set->collect->current, set->collect->max);
		}
		if (collider && !strcmp(collider->name, "exit"))
			printf("exiting\n");
		if (collider && !strcmp(collider->name, "block"))
			object->vel[0] = vi2d_start(-6, -6);
		else
			object->vel[0] = vi2d_start(6, 6);
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
