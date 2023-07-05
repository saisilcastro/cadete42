/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux-key-a-to-l.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:38:52 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/04 10:39:18 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux_keyboard_of.h>

void	key_a_to_l(t_KEYBOARD_MAP *map, int keycode)
{
	if (keycode == 0x0061)
		*map = KEY_A;
	if (keycode == 0x0062)
		*map = KEY_B;
	if (keycode == 0x0063)
		*map = KEY_C;
	if (keycode == 0x0064)
		*map = KEY_D;
	if (keycode == 0x0065)
		*map = KEY_E;
	if (keycode == 0x0066)
		*map = KEY_F;
	if (keycode == 0x0067)
		*map = KEY_G;
	if (keycode == 0x0068)
		*map = KEY_H;
	if (keycode == 0x0069)
		*map = KEY_I;
	if (keycode == 0x006A)
		*map = KEY_J;
	if (keycode == 0x006B)
		*map = KEY_K;
	if (keycode == 0x006C)
		*map = KEY_L;
}
