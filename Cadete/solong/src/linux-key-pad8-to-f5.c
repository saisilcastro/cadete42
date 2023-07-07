/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux-key-pad8-to-f5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:59:44 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/06 13:49:17 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux_keyboard_of.h>

void	key_pad8_to_f5(t_keyboard_map *map, int keycode)
{
	if (keycode == 0xFF97)
		*map = KEY_PAD_8;
	if (keycode == 0xFF9A)
		*map = KEY_PAD_9;
	if (keycode == 0xFFBE)
		*map = KEY_F1;
	if (keycode == 0xFFBF)
		*map = KEY_F2;
	if (keycode == 0xFFC0)
		*map = KEY_F3;
	if (keycode == 0xFFC1)
		*map = KEY_F4;
	if (keycode == 0xFFC2)
		*map = KEY_F5;
}
