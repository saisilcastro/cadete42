/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-update_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:42:34 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/21 23:25:20 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>
#include <place_print.h>
#include <mlx.h>

static void	take_step(t_place *set, t_object *hero)
{
	if (hero->status & (1 << OBJECT_VISIBLE))
	{
		set->step++;
	}
}

static void	hero_control(t_place *set, t_object *hero)
{
	place_camera_object(set, hero);
	if (set->key_down(set, KEY_LEFT) || set->key_down(set, KEY_A))
	{
		hero->dest->x -= hero->vel->x;
		take_step(set, hero);
	}
	if (set->key_down(set, KEY_RIGHT) || set->key_down(set, KEY_D))
	{
		hero->dest->x += hero->vel->x;
		take_step(set, hero);
	}
	if (set->key_down(set, KEY_UP) || set->key_down(set, KEY_W))
	{
		hero->dest->y -= hero->vel->y;
		take_step(set, hero);
	}
	if (set->key_down(set, KEY_DOWN) || set->key_down(set, KEY_S))
	{
		hero->dest->y += hero->vel->y;
		take_step(set, hero);
	}
}

void	hero_update(t_place *set, t_object *object)
{
	t_object	*collider;

	if (object->id == set->hero_id)
	{
		if (place_block_move(set, object))
			return ;
		hero_control(set, object);
		if (object_route(object))
			image_animation(set, object);
		collider = place_object_collision(set, object);
		if (object_name_is(collider, "collect"))
		{
			collider->status &= ~(1 << OBJECT_VISIBLE);
			set->collect->current++;
		}
		else if (object_name_is(collider, "exit"))
			object->status &= ~(1 << OBJECT_VISIBLE);
		else if (object_name_is(collider, "enemy"))
		{
			write(1, "game over\n", 10);
			set->stop(set);
		}
	}
}

int	user_update(t_place *set)
{
	t_chained		*update;
	t_object		*object;
	t_pixel			pixel;

	if (!set)
		return (0);
	set->draw_bg(set);
	if (set->key_down(set, KEY_ESC))
		set->stop(set);
	pixel = pixel_rgba_local(255, 224, 255, 0);
	place_print(set, conf_start(vi2d_start(10, 15),
			pixel), "moves %d", set->step);
	update = set->gear->object;
	while (update)
	{
		object = update->data;
		hero_update(set, object);
		if (object_name_is(object, "exit"))
		{
			if (set->collect->current == set->collect->max)
				object->status |= (1 << OBJECT_VISIBLE);
		}
		update = update->next;
	}
	return (!set->destroy(set));
}
