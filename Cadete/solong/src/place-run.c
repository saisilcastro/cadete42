/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:22:08 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/08 11:57:48 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>
#include <stdio.h>

static void	mlx_plugin_run(t_place *set, void *data)
{
	void	*plugin;

	if (!set || !data)
		return ;
	plugin = NULL;
	plugin = ((t_mlx_plugin *)set->gear->plugin)->mlx;
	if (!plugin)
		return ;
	if (set->update)
		mlx_loop_hook(plugin, set->update, set->gear);
	printf("running everything\n");
	mlx_start_event(set->gear);
}

void	place_run(t_place *set, void *data)
{
	if (!set)
		return ;
	if (set->init)
		set->init(set, data);
	if (set->gear->up->system == SYSTEM_CONSOLE)
		return ;
	else if (set->gear->up->system == SYSTEM_MINILIBX)
		mlx_plugin_run(set, data);
	if (set->update)
		set->update(set);
	if (set->gear->up->system == SYSTEM_MINILIBX)
		mlx_loop(((t_mlx_plugin *)set->gear->plugin)->mlx);
	if (set->pop)
		set->pop(set);
	place_pop(set);
}
