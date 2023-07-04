/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:51:44 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/03 14:48:08 by mister-code      ###   ########.fr       */
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
	set->pos[0] = vi2d_start(WINDOW_LEFT_CENTER, WINDOW_TOP_CENTER);
	set->bg[0] = object_start(0, "background", NULL);
	set->plugin = NULL;
	set->image = NULL;
	set->object = NULL;
	mouse_of_set(&set->mouse[0], 0, 0, 0x00);
	set->event = 0x01;
}

t_STATUS	machine_start(t_machine *set)
{
	if (!set)
		return (Off);
	switch (set->up->system)
	{
		case SYSTEM_CONSOLE:
			return (On);
		break ;
		case SYSTEM_MINILIBX:
		{
			set->plugin = mlx_plugin_push();
			return (mlx_plugin_start(set));
		}
		break ;
	}
	return (Off);
}
#include <stdio.h>

static void	machine_object_pop(t_machine *set)
{
	t_chained *next;

	if (!set)
		return ;
	while (set->object)
	{
		next = set->object->next;
		free(set->object);
		set->object = next;
	}	
}

static void	console_pop(t_machine *set)
{
	t_chained *next;
	
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
	if (!set)
		return ;
	switch(set->up->system)
	{
		case SYSTEM_CONSOLE:
			console_pop(set);
		break ;
		case SYSTEM_MINILIBX:
		{
			mlx_plugin_pop(set);
			machine_object_pop(set);
		}
		break ;
	}
}
