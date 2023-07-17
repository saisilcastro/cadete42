/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:49:09 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/16 00:37:17 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>
#include <map_of.h>

extern void	user_init(t_place *place, void *data);
extern int	user_update(t_place *place);

void	so_long_execute(char *path)
{
	static t_place		place;
	t_SystemSet			up;

	up.system = SYSTEM_MINILIBX;
	up.driver = GRAPHIC_PRIMARY;
	up.audio = SYSTEM_AUDIO_NONE;
	up.lan = SYSTEM_NETWORK_NONE;
	place_set(&place, up, vi2d_start(640, 480));
	if (!place.start(&place))
		return ;
	place.init = user_init;
	place.update = user_update;
	place.pop = NULL;
	place.run(&place, path);
}
