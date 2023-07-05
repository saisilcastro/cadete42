/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux-key-tilde-to-pgdn.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:51:00 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/04 11:12:36 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux_keyboard_of.h>

void	key_tilde_to_pgdn(t_KEYBOARD_MAP *map, int keycode)
{
	if (keycode == 0xFE53)
		*map = KEY_TILDE;
	if (keycode == 0xFF1B)
		*map = KEY_ESC;
	if (keycode == 0xFF51)
		*map = KEY_LEFT;
	if (keycode == 0xFF52)
		*map = KEY_UP;
	if (keycode == 0xFF54)
		*map = KEY_DOWN;
	if (keycode == 0xFF53)
		*map = KEY_RIGHT;
	if (keycode == 0xFF63)
		*map = KEY_INSERT;
	if (keycode == 0xFFFF)
		*map = KEY_DELETE;
	if (keycode == 0xFF50)
		*map = KEY_HOME;
	if (keycode == 0xFF57)
		*map = KEY_END;
	if (keycode == 0xFF55)
		*map = KEY_PGUP;
	if (keycode == 0xFF56)
		*map = KEY_PGDN;
}
