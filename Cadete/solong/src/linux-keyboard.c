/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux-keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:15:36 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/04 11:03:20 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux_keyboard_of.h>

t_KEYBOARD_MAP	linux_key_get(int keycode)
{
	t_KEYBOARD_MAP	map;

	key_number(&map, keycode);
	key_a_to_l(&map, keycode);
	key_m_to_x(&map, keycode);
	key_y_to_stop(&map, keycode);
	key_tilde_to_pgdn(&map, keycode);
	key_left_to_pad7(&map, keycode);
	key_pad8_to_f5(&map, keycode);
	key_f6_to_f12(&map, keycode);
	return (map);
}
