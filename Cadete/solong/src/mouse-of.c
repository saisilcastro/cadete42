/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse-of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:42:00 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/30 19:44:12 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mouse_of.h>

void	mouse_of_set(t_mouse *set, B32 x, B32 y,
	unsigned int button)
{
	if (!set)
		return ;
	set->x = x;
	set->y = y;
	set->button = button;
	set->wheel = 0x00;
}
