/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-plugin-draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:11:02 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/21 14:44:37 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_plugin.h>

void	mlx_plugin_draw(t_machine *set, void *buffer, t_vi2d pos)
{
	t_mlx_plugin	*plugin;

	if (!set || !buffer || set->up->system != SYSTEM_MINILIBX)
		return ;
	plugin = set->plugin;
	if (plugin)
	{
		mlx_put_image_to_window(plugin->mlx, plugin->window,
			buffer, pos.x, pos.y);
	}
}
