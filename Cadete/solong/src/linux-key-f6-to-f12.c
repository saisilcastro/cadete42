/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux-key-f6-to-f12.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:02:53 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/06 13:47:13 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux_keyboard_of.h>

void	key_f6_to_f12(t_keyboard_map *map, int keycode)
{
	if (keycode == 0xFFC3)
		*map = KEY_F6;
	if (keycode == 0xFFC4)
		*map = KEY_F7;
	if (keycode == 0xFFC5)
		*map = KEY_F8;
	if (keycode == 0xFFC6)
		*map = KEY_F9;
	if (keycode == 0xFFC7)
		*map = KEY_F10;
	if (keycode == 0xFFC8)
		*map = KEY_F11;
	if (keycode == 0xFFC9)
		*map = KEY_F12;
}
