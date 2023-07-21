/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse-of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:42:00 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/20 09:25:37 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mouse_of.h>

void	mouse_of_set(t_mouse *set, int x, int y,
	unsigned int button)
{
	if (!set)
		return ;
	set->x = x;
	set->y = y;
	set->button = button;
	set->wheel = 0x00;
}
