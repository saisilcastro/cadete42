/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux-key-y-to-stop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:48:02 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/06 13:47:43 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux_keyboard_of.h>

void	key_y_to_stop(t_keyboard_map *map, int keycode)
{
	if (keycode == 0x0079)
		*map = KEY_Y;
	if (keycode == 0x007A)
		*map = KEY_Z;
	if (keycode == 0x0020)
		*map = KEY_SPACE;
	if (keycode == 0x002C)
		*map = KEY_COMMA;
	if (keycode == 0x002D)
		*map = KEY_MINUS;
	if (keycode == 0x003D)
		*map = KEY_EQUALS;
	if (keycode == 0x005B)
		*map = KEY_OPENBRACE;
	if (keycode == 0x005D)
		*map = KEY_CLOSEBRACE;
	if (keycode == 0xFF08)
		*map = KEY_BACKSPACE;
	if (keycode == 0xFF09)
		*map = KEY_TAB;
	if (keycode == 0xFF13)
		*map = KEY_FULLSTOP;
	if (keycode == 0xFF0D)
		*map = KEY_ENTER;
}
