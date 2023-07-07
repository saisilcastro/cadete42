/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux-key-m-to-x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:42:52 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/06 13:47:29 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux_keyboard_of.h>

void	key_m_to_x(t_keyboard_map *map, int keycode)
{
	if (keycode == 0x006D)
		*map = KEY_M;
	if (keycode == 0x006E)
		*map = KEY_N;
	if (keycode == 0x006F)
		*map = KEY_O;
	if (keycode == 0x0070)
		*map = KEY_P;
	if (keycode == 0x0071)
		*map = KEY_Q;
	if (keycode == 0x0072)
		*map = KEY_R;
	if (keycode == 0x0073)
		*map = KEY_S;
	if (keycode == 0x0074)
		*map = KEY_T;
	if (keycode == 0x0075)
		*map = KEY_U;
	if (keycode == 0x0076)
		*map = KEY_V;
	if (keycode == 0x0077)
		*map = KEY_W;
	if (keycode == 0x0078)
		*map = KEY_X;
}
