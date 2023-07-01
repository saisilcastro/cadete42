/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:51:44 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/30 19:55:11 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <machine.h>

void	machine_set(t_machine *set, t_SystemSet up, B8 *title, t_vi2d size)
{
	if (!set)
		return ;
	set->up[0] = up;
	set->title = title;
	set->size[0] = size;
	set->pos[0] = vi2d_start(WINDOW_LEFT_CENTER, WINDOW_TOP_CENTER);
	set->bg[0] = object_start(0, "background", NULL);
	set->plugin = NULL;
	set->image = NULL;
	set->object = NULL;
	mouse_of_set(&set->mouse, 0, 0, 0x00);
	set->event = 0x00;
}
