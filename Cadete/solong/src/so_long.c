/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:49:09 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/01 17:17:38 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>
#include <stdio.h>

extern void	user_init(t_place *place, void *data);
extern void	user_pop(t_place *place);

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
	place.pop = user_pop;
	place.run(&place, map);
}
