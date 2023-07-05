/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux-key-number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:35:26 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/04 10:36:41 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux_keyboard_of.h>

void	key_number(t_KEYBOARD_MAP *map, int keycode)
{
	if (keycode == 0x0030)
		*map = KEY_0;
	if (keycode == 0x0031)
		*map = KEY_1;
	if (keycode == 0x0032)
		*map = KEY_2;
	if (keycode == 0x0033)
		*map = KEY_3;
	if (keycode == 0x0034)
		*map = KEY_4;
	if (keycode == 0x0035)
		*map = KEY_5;
	if (keycode == 0x0036)
		*map = KEY_6;
	if (keycode == 0x0037)
		*map = KEY_7;
	if (keycode == 0x0038)
		*map = KEY_8;
	if (keycode == 0x0039)
		*map = KEY_9;
}
