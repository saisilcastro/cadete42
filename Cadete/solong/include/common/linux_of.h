/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_of.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:19:08 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/20 09:13:39 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINUX_OF_H
# define LINUX_OF_H

# include <linux_keyboard_of.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP,
	ON_MOUSEDOWN,
	ON_MOUSEUP,
	ON_MOUSEMOVE,
	NOTIFY_IN,
	NOTIFY_OUT,
	FOCUS_IN,
	FOCUS_OUT,
	KEYMAP_NOTIFY,
	ON_EXPOSE,
	ON_DESTROY = 17
};

enum {
	NO_EVENT_MASK = 0L,
	KEY_PRESS_MASK = (1L << 0),
	KEY_RELEASE_MASK = (1L<<1),
	MOUSE_PRESS_MASK = (1L<<2),
	MOUSE_RELEASE_MASK = (1L<<3),
	ENTER_WINDOW_MASK = (1L<<4),
	LEAVE_WINDOW_MASK = (1L<<5),
	POINTER_MOTION_MASK = (1L<<6),
	POINTER_MOTION_HINT_MASK = (1L<<7)
};

#endif // LINUX_OF_H