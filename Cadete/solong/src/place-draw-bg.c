/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-draw-bg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:14:32 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/06 18:35:04 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>
#include <stdio.h>

static void	map_lock(t_place *set)
{
	t_vi2d	limit;

	if (!set)
		return ;
	limit.x = set->gear->bg->image->size->x - set->gear->size->x;
	limit.y = set->gear->bg->image->size->y - set->gear->size->y;
	if (set->gear->bg->pos->x < 0)
		set->gear->bg->pos->x = 0;
	if (set->gear->bg->pos->x > limit.x)
		set->gear->bg->pos->x = limit.x;
	if (set->gear->bg->pos->y < 0)
		set->gear->bg->pos->y = 0;
	if (set->gear->bg->pos->y > limit.y)
		set->gear->bg->pos->y = limit.y;
}

void	place_draw_bg(t_place *set)
{
	void			*buffer;
	B32				x;
	B32				y;

	if (!set)
		return ;
	if (set->gear->up->system == SYSTEM_MINILIBX
		&& set->gear->bg->image && set->gear->bg->image->buffer)
	{
		buffer = set->gear->bg->image->buffer;
		map_lock(set);
		x = -set->gear->bg->pos->x;
		y = -set->gear->bg->pos->y;
		mlx_plugin_draw(set->gear, buffer, vi2d_start(x, y));
	}
}
