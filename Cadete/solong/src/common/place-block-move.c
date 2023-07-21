/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-block-move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:04:09 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/20 01:13:23 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

static void	hero_control(t_place *set, t_object *hero)
{
	place_camera_object(set, hero);
	if (set->key_down(set, KEY_LEFT) || set->key_down(set, KEY_A))
		hero->dest->x -= hero->vel->x;
	if (set->key_down(set, KEY_RIGHT) || set->key_down(set, KEY_D))
		hero->dest->x += hero->vel->x;
	if (set->key_down(set, KEY_UP) || set->key_down(set, KEY_W))
		hero->dest->y -= hero->vel->y;
	if (set->key_down(set, KEY_DOWN) || set->key_down(set, KEY_S))
		hero->dest->y += hero->vel->y;
}

t_status	place_block_move(t_place *set, t_object *hero)
{
	t_object	fake_hero;

	object_clone(hero, &fake_hero);
	hero_control(set, &fake_hero);
	object_route(&fake_hero);
	if (object_name_is(place_object_collision(set, &fake_hero), "block"))
		return (On);
	return (Off);
}
