/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:52:30 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/06 13:52:33 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

t_status	place_destroy(t_place *set)
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
