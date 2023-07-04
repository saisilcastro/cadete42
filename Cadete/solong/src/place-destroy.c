/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:52:30 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/03 15:29:59 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

t_STATUS	place_destroy(t_place *set)
{
	t_mlx_plugin	*plugin;

	if (!(set->gear->event & (1 << MACHINE_RUNNING)))
	{
		switch(set->gear->up->system)
		{
			case SYSTEM_CONSOLE:
			break ;
			case SYSTEM_MINILIBX:
			{
				plugin = set->gear->plugin;
				mlx_destroy_window(plugin->mlx, plugin->window);
				return (On);
			}
			break ;				
		}
	}
	return (Off);
}