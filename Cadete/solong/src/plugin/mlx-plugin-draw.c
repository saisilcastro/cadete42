/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-draw-plugin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:11:02 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/06 18:18:27 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <plugin/mlx_plugin.h>

void	mlx_plugin_draw(t_machine *set, void *buffer, t_vi2d pos)
{
	t_mlx_plugin	*plugin;

	if (!set || !buffer || set->up->system != SYSTEM_MINILIBX)
		return ;
	plugin = set->plugin;
	mlx_put_image_to_window(plugin->mlx, plugin->window, buffer, pos.x, pos.y);
}
