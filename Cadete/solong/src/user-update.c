/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:03:07 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/18 00:50:20 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>
#include <stdio.h>
#include <string.h>

t_object	*place_collision(t_chained *update, t_object *hero)
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
	t_object	fake_hero;

	if (object->id == set->hero_id)
	{
		fake_hero.id = object->id;
		fake_hero.pos[0] = vi2d_start(object->pos->x, object->pos->y);
		fake_hero.status = object->status;
		fake_hero.vel[0] = vi2d_start(object->vel->x, object->vel->y);
		fake_hero.image = object->image;
		hero_control(set, &fake_hero);
		object_route(&fake_hero);
		collider = place_collision(set->gear->object, &fake_hero);
		if (collider && !strcmp(collider->name, "block"))
			return ;
		hero_control(set, object);
		object_route(object);
		collider = place_collision(set->gear->object, object);
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
