/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:52:30 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/05 13:45:04 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

t_STATUS	place_destroy(t_place *set)
{
	t_mlx_plugin	*plugin;

	if (!(set->gear->event & (1 << MACHINE_RUNNING)))
	{
		if (set->gear->up->system == SYSTEM_CONSOLE)
			return (On);
		else if (set->gear->up->system == SYSTEM_MINILIBX)
		{
			plugin = set->gear->plugin;
			mlx_loop_end(plugin->mlx);
			return (On);
		}
	}
	return (Off);
}
