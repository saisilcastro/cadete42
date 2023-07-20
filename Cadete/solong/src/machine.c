/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:51:44 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/20 00:39:02 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <machine.h>
#include <plugin/mlx_plugin.h>

void	machine_set(t_machine *set, t_SystemSet up, B8 *title, t_vi2d size)
{
	if (!set)
		return ;
	set->up[0] = up;
	set->title = title;
	set->size[0] = size;
	set->pos[0] = vi2d_start(0, 0);
	set->bg[0] = object_start(0, "background", NULL);
	set->plugin = NULL;
	set->image = NULL;
	set->object = NULL;
	mouse_of_set(&set->mouse[0], 0, 0, 0x00);
	set->event = 0x01;
}

t_status	machine_start(t_machine *set)
{
	if (!set)
		return (Off);
	if (set->up->system == SYSTEM_CONSOLE)
		return (On);
	else if (set->up->system == SYSTEM_MINILIBX)
	{
		set->plugin = mlx_plugin_push();
		return (mlx_plugin_start(set));
	}
	return (Off);
}

static void	machine_object_pop(t_machine *set)
{
	t_chained	*next;

	if (!set)
		return ;
	while (set->object)
	{
		next = set->object->next;
		if (set->object->data)
			free(set->object->data);
		free(set->object);
		set->object = next;
	}
}

static void	console_pop(t_machine *set)
{
	t_chained	*next;

	if (!set)
		return ;
	while (set->image)
	{
		next = set->image->next;
		image_of_pop(set->image->data, set->plugin, set->up[0]);
		free(set->image);
		set->image = next;
	}
	machine_object_pop(set);
}

void	machine_pop(t_machine *set)
{
	if (!set || !set->plugin)
		return ;
	if (set->up->system == SYSTEM_CONSOLE)
		console_pop(set);
	else if (set->up->system == SYSTEM_MINILIBX)
	{
		mlx_plugin_pop(set);
		machine_object_pop(set);
	}
}
