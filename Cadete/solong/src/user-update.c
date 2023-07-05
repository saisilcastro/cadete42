/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:03:07 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/05 20:42:56 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>
#include <stdio.h>

int	user_update(t_place *set)
{
	t_mlx_plugin	*plugin;

	if (!set)
		return (0);
	plugin = NULL;
	plugin = set->gear->plugin;
	if (!plugin)
		return (0);
	set->draw_bg(set);
	if (set->key_down(set, KEY_LEFT))
		set->gear->bg->pos->x -= set->gear->bg->vel->x;
	if (set->key_down(set, KEY_RIGHT))
		set->gear->bg->pos->x += set->gear->bg->vel->x;
	if (set->key_down(set, KEY_UP))
		set->gear->bg->pos->y -= set->gear->bg->vel->y;
	if (set->key_down(set, KEY_DOWN))
		set->gear->bg->pos->y += set->gear->bg->vel->y;
	if (set->key_down(set, KEY_Q))
		set->stop(set);
	return (!set->destroy(set));
}
