/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-mouse-plugin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:37:27 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/02 22:24:00 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <machine.h>
#include <bit_of.h>
#include <plugin/mlx_plugin.h>

int	mlx_mouse_update(int button, int x, int y, t_machine *set)
{
	if (!set)
		return (0);
	set->mouse->x = x;
	set->mouse->y = y;
	if (button == 1)
		set->mouse->button |= (1 << MACHINE_MOUSE_LEFT);
	if (button == 2)
		set->mouse->button |= (1 << MACHINE_MOUSE_MIDDLE);
	if (button == 3)
		set->mouse->button |= (1 << MACHINE_MOUSE_RIGHT);
	if (button == 4)
		set->mouse->wheel |= (1 << MOUSE_WHEEL_UP);
	if (button == 5)
		set->mouse->wheel |= (1 << MOUSE_WHEEL_DOWN);
	return (0);
}

int	mlx_mouse_press(int button, int x, int y, t_machine *set)
{
	if (!set)
		return (0);
	set->mouse->x = x;
	set->mouse->y = y;
		if (button == 1)
		set->mouse->button |= (1 << MACHINE_MOUSE_LEFT);
	if (button == 2)
		set->mouse->button |= (1 << MACHINE_MOUSE_MIDDLE);
	if (button == 3)
		set->mouse->button |= (1 << MACHINE_MOUSE_RIGHT);
	return (0);
}

int	mlx_mouse_release(int button, int x, int y, t_machine *set)
{
	if (!set || !button)
		return (0);
	set->mouse->x = x;
	set->mouse->y = y;
	if (button == 1)
		set->mouse->button &= ~(1 << MACHINE_MOUSE_LEFT);
	if (button == 2)
		set->mouse->button &= ~(1 << MACHINE_MOUSE_MIDDLE);
	if (button == 3)
		set->mouse->button &= ~(1 << MACHINE_MOUSE_RIGHT);
	return (0);
}
