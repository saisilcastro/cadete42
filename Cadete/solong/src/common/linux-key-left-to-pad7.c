/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux-key-left-to-pad7.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:54:23 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/06 13:47:19 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux_keyboard_of.h>

void	key_left_to_pad7(t_keyboard_map *map, int keycode)
{
	if (keycode == 0xFF51)
		*map = KEY_LEFT;
	if (keycode == 0xFF52)
		*map = KEY_UP;
	if (keycode == 0xFF53)
		*map = KEY_RIGHT;
	if (keycode == 0xFF54)
		*map = KEY_DOWN;
	if (keycode == 0xFF9E)
		*map = KEY_PAD_0;
	if (keycode == 0xFF9C)
		*map = KEY_PAD_1;
	if (keycode == 0xFF99)
		*map = KEY_PAD_2;
	if (keycode == 0xFF9B)
		*map = KEY_PAD_3;
	if (keycode == 0xFF96)
		*map = KEY_PAD_4;
	if (keycode == 0xFF9D)
		*map = KEY_PAD_5;
	if (keycode == 0xFF98)
		*map = KEY_PAD_6;
	if (keycode == 0xFF95)
		*map = KEY_PAD_7;
}
