/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object-collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:05:35 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/15 22:13:55 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object_of.h>

static t_status    object_x_collision(t_object *ob1, t_object *ob2)
{
	B32	ob1_left;
	B32	ob1_right;
	B32	ob2_left;
	B32	ob2_right;

	if (!ob1 || !ob1->image || !ob2 || !ob2->image)
		return (Off);
	ob1_left = ob1->pos->x;
	ob1_right = ob1->pos->x + ob1->image->size->x;
	ob2_left = ob2->pos->x;
	ob2_right = ob2->pos->x + ob2->image->size->x;
	if (ob1_left > ob2_right || ob1_right < ob2_left)
		return (Off);
	return (On);
}

static t_status    object_y_collision(t_object *ob1, t_object *ob2)
{
	B32	ob1_top;
	B32	ob1_bottom;
	B32	ob2_top;
	B32	ob2_bottom;

	if (!ob1 || !ob1->image || !ob2 || !ob2->image)
		return (Off);
	ob1_top = ob1->pos->y;
	ob1_bottom = ob1->pos->y + ob1->image->size->y;
	ob2_top = ob2->pos->y;
	ob2_bottom = ob2->pos->y + ob2->image->size->y;
	if (ob1_top > ob2_bottom || ob1_bottom < ob2_top)
			return (Off);
	return (On);
}

t_status	object_collision(t_object *ob1, t_object *ob2)
{
	if (!ob1 || !ob2 || !(ob1->status & (1 << OBJECT_VISIBLE))
		|| !(ob2->status & (1 << OBJECT_VISIBLE)))
		return (Off);
	return (object_x_collision(ob1, ob2) && object_y_collision(ob1, ob2));
}
