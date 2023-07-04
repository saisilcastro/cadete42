/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:22:08 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/03 15:35:20 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

static void	mlx_plugin_run(t_place *set, void *data)
{
	void	*plugin;

	if (!set)
	{
		(void)data;
		return ;
	}
	plugin = NULL;
	plugin = ((t_mlx_plugin *)set->gear->plugin)->mlx;
	if (!plugin)
		return ;
	if (set->update)
		mlx_loop_hook(plugin, set->update, set->gear);
	mlx_start_event(set->gear);
}

void	place_run(t_place *set, void *data)
{
	if (!set)
		return ;
	if (set->init)
		set->init(set, data);
	switch(set->gear->up->system)
	{
		case SYSTEM_CONSOLE:
		break ;
		case SYSTEM_MINILIBX:
			mlx_plugin_run(set, data);
		break ;
	}
	if (set->update)
		set->update(set);
	if (set->gear->up->system == SYSTEM_MINILIBX)
		mlx_loop(((t_mlx_plugin *)set->gear->plugin)->mlx);
	if (set->pop)
		set->pop(set);
	place_pop(set);
}
