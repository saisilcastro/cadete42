/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse-of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:43:21 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/21 10:43:23 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mouse-of.h>

void	mouse_of_set(t_mouse *set, B32 x, B32 y, unsigned button, unsigned wheel)
{
	if (!set)
		return ;
	set->x = x;
	set->y = y;
	set->button = button;
	set->wheel = wheel;
}