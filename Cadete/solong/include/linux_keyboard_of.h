/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_keyboard_of.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:21:54 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/04 11:02:37 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINUX_KEYBOARD_OF_H
# define LINUX_KEYBOARD_OF_H

# include <keyboard_of.h>

t_KEYBOARD_MAP	linux_key_get(int keycode);
void			key_number(t_KEYBOARD_MAP *map, int keycode);
void			key_a_to_l(t_KEYBOARD_MAP *map, int keycode);
void			key_m_to_x(t_KEYBOARD_MAP *map, int keycode);
void			key_y_to_stop(t_KEYBOARD_MAP *map, int keycode);
void			key_tilde_to_pgdn(t_KEYBOARD_MAP *map, int keycode);
void			key_left_to_pad7(t_KEYBOARD_MAP *map, int keycode);
void			key_pad8_to_f5(t_KEYBOARD_MAP *map, int keycode);
void			key_f6_to_f12(t_KEYBOARD_MAP *map, int keycode);

#endif // LINUX_KEYBOARD_OF_H