/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:49:09 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/01 15:01:08 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>
#include <stdio.h>

extern void	user_init(t_place *place, void *data);

void	so_long_execute(char *map)
{
	t_place		place;
	t_SystemSet	up;

	up.system = SYSTEM_MINILIBX;
	up.driver = GRAPHIC_PRIMARY;
	up.audio = SYSTEM_AUDIO_NONE;
	up.lan = SYSTEM_NETWORK_NONE;
	place_set(&place, up, vi2d_start(640, 480));
	place.init = user_init;
	place.run(&place, map);
}
