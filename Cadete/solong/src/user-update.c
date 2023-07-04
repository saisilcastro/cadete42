/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:03:07 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/04 05:35:53 by mister-code      ###   ########.fr       */
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
	if (set->key_get(set, KEY_Q))
		set->stop(set);
	return (!set->destroy(set));
}
