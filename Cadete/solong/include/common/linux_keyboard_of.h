/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_keyboard_of.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:21:54 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/06 13:45:41 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINUX_KEYBOARD_OF_H
# define LINUX_KEYBOARD_OF_H

# include <keyboard_of.h>

t_keyboard_map	linux_key_get(int keycode);
void			key_number(t_keyboard_map *map, int keycode);
void			key_a_to_l(t_keyboard_map *map, int keycode);
void			key_m_to_x(t_keyboard_map *map, int keycode);
void			key_y_to_stop(t_keyboard_map *map, int keycode);
void			key_tilde_to_pgdn(t_keyboard_map *map, int keycode);
void			key_left_to_pad7(t_keyboard_map *map, int keycode);
void			key_pad8_to_f5(t_keyboard_map *map, int keycode);
void			key_f6_to_f12(t_keyboard_map *map, int keycode);

#endif // LINUX_KEYBOARD_OF_H