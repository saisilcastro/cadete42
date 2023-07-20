/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:49:09 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/20 00:41:52 by lde-cast         ###   ########.fr       */
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
	if (!map_valid_file(path))
	{
		write(1, "Error\n", 6);
		write(1, "invalid file\n", 13);
		return ;
	}
	place_set(&place, up, vi2d_start(640, 480));
	if (!place.start(&place))
	{
		write(1, "Error\ncould not start the fucking machine\n", 42);
		place_pop(&place);
		return ;
	}
	place.init = user_init;
	place.update = user_update;
	place.pop = NULL;
	place.run(&place, path);
}
