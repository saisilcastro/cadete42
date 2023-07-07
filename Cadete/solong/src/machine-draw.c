/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine-draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:11:03 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/06 22:28:15 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <machine.h>
#include <plugin/mlx_plugin.h>
#include <stdio.h>

t_status	is_croma(t_pixel *set, B8U alpha)
{
	if ((set && set->r == 255 && set->g == 0 && set->b == 255)
		|| (set && set->a == alpha))
		return (On);
	return (Off);
}

void	xpm_to_alpha(t_machine *set, t_object *obj)
{
	B32		x;
	B32		y;
	t_pixel	px;

	if (!set || !set->bg->image)
		return ;
	y = -1;
	while (++y < obj->image->size->y)
	{
		x = -1;
		while (++x < obj->image->size->x)
		{
			pixel_from_abgr(&px, image_color_int(obj->image, x, y));
			if (is_croma(&px, 255))
			{
				pixel_from_abgr(&px, image_color_int(set->bg->image,
						obj->pos->x + x, obj->pos->y + y));
				px.a = 255;
				pixel_to_int(obj->image, &px, vi2d_start(x, y));
			}
		}
	}
}

void	machine_draw(t_machine	*set, t_object *obj)
{
	B32			x;
	B32			y;

	if (!set)
		return ;
	if (set->up->system == SYSTEM_MINILIBX)
	{
		x = obj->pos->x - set->bg->pos->x;
		y = obj->pos->y - set->bg->pos->y;
		xpm_to_alpha(set, obj);
		mlx_plugin_draw(set, obj->image->buffer, vi2d_start(x, y));
	}
}
