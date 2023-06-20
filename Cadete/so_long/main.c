/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:42:06 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/19 21:42:08 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <machine.h>

void	player_animation(t_machine *set, t_object *object);

typedef enum{
	TWINSEN_FRONT,
	TWINSEN_BACK,
	TWINSEN_SIDE_RIGHT,
	TWINSEN_SIDE_LEFT,
	TWINSEN_DIAGONAL_BACK_LEFT,
	TWINSEN_DIAGONAL_BACK_RIGHT,
	TWINSEN_DIAGONAL_FRONT_RIGHT,
	TWINSEN_DIAGONAL_FRONT_LEFT,
}IMAGE_ROW;

void	local_init(t_machine *set)
{
	B32	id;
	B32	x;
	B32	y;

	if (!set)
		return ;
	set->map_create(set, set->w, set->h);
	set->bg->image->color = pixel_rgba_local(0, 0, 0, 255);
	set->image_load(set, "img/twinsen-front-up.xpm", TWINSEN_FRONT);
	set->image_load(set, "img/twinsen-back-up.xpm", TWINSEN_BACK);
	set->image_load(set, "img/twinsen-side-up.xpm", TWINSEN_SIDE_RIGHT);
	set->image_load(set, "img/twinsen-side-up-left.xpm", TWINSEN_SIDE_LEFT);
	set->image_load(set, "img/twinsen-diagonal-back.xpm", TWINSEN_DIAGONAL_BACK_RIGHT);
	set->image_load(set, "img/twinsen-diagonal-back-left.xpm", TWINSEN_DIAGONAL_BACK_LEFT);
	set->image_load(set, "img/twinsen-diagonal-front.xpm", TWINSEN_DIAGONAL_FRONT_RIGHT);
	set->image_load(set, "img/twinsen-diagonal-front-left.xpm", TWINSEN_DIAGONAL_FRONT_LEFT);
	id = 0;
	while (id < 10)
	{
		x = rand() % set->w;
		y = rand() % set->h;
		set->object_create(set, id, vi2d_start(x, y),
				set->image_search(set, TWINSEN_BACK));
		id++;
	}
}

int	local_update(t_machine *set)
{
	static int	selected;
	t_chained	*chained;
	t_object	*object;
	t_pixel		color;

	color = pixel_rgba_local(0, 255, 0, 255);
	if (!set)
		return (0);
	machine_bg_update(set, 0);
	set->draw(set);
	set->mouse_pos(set);
	if (set->mouse_press(set, MACHINE_MOUSE_RIGHT))
		printf("clica a mae\n");
	if (set->mouse->x > 0 && set->mouse->x < 50
		&& set->mouse->y > 0 && set->mouse->y < 50)
		printf("ai carai\n");
	if (set->key_get(set, KEY_Q))
		machine_destroy_window(set);
	if (set->key_get(set, KEY_N))
	{
		selected++;
		if (selected > 9)
			selected = 0;
	}
	chained = set->object;
	while (chained)
	{
		object = chained->content;
		if (object->id == selected)
		{
			if (set->mouse_press(set, MACHINE_MOUSE_LEFT))
			{
				object->route->x = set->mouse->x;
				object->route->y = set->mouse->y;
			}
			if (set->key_get(set, KEY_LEFT))
				object->route->x -= object->vel->x;
			if (set->key_get(set, KEY_RIGHT))
				object->route->x += object->vel->x;
			if (set->key_get(set, KEY_UP))
				object->route->y -= object->vel->y;
			if (set->key_get(set, KEY_DOWN))
				object->route->y += object->vel->y;
			if (!set->object_route(object))
				player_animation(set, object);
		}
		else
		{
			if (set->object_route(object))
			{
				object->route->x = (rand() % set->w);
				object->route->y = (rand() % set->h);
			}
			else
				player_animation(set, object);
		}
		chained = chained->next;
	}
	return (0);
}

void	player_animation(t_machine *set, t_object *object)
{
	if (!set)
		return ;
	if (object->where == NORTH)
		object->image = set->image_search(set, TWINSEN_BACK);
	if (object->where == NORTHWEST)
		object->image = set->image_search(set, TWINSEN_DIAGONAL_BACK_LEFT);
	if (object->where == NORTHEAST)
		object->image = set->image_search(set, TWINSEN_DIAGONAL_BACK_RIGHT);
	if (object->where == SOUTH)
		object->image = set->image_search(set, TWINSEN_FRONT);
	if (object->where == SOUTHWEST)
		object->image = set->image_search(set, TWINSEN_DIAGONAL_FRONT_LEFT);
	if (object->where == SOUTHEAST)
		object->image = set->image_search(set, TWINSEN_DIAGONAL_FRONT_RIGHT);
	if (object->where == WEST)
		object->image = set->image_search(set, TWINSEN_SIDE_LEFT);
	if (object->where == EAST)
		object->image = set->image_search(set, TWINSEN_SIDE_RIGHT);
}

int	main(void)
{
	t_machine	where;

	machine_start(&where);
	where.init = local_init;
	where.update = local_update;
	machine_run(&where);
	return (0);
}
