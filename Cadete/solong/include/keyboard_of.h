/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_of.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:17:18 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/04 11:34:51 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_OF_H
# define KEYBOARD_OF_H

typedef enum e_KEYBOARD_MAP{
	KEY_NONE = 0,
	KEY_A = 1,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
	KEY_0 = 27,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_PAD_0 = 37,
	KEY_PAD_1,
	KEY_PAD_2,
	KEY_PAD_3,
	KEY_PAD_4,
	KEY_PAD_5,
	KEY_PAD_6,
	KEY_PAD_7,
	KEY_PAD_8,
	KEY_PAD_9,
	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	KEY_F7,
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_F11,
	KEY_F12,
	KEY_ESC = 59,
	KEY_TILDE = 60,
	KEY_MINUS = 61,
	KEY_EQUALS = 62,
	KEY_BACKSPACE = 63,
	KEY_TAB = 64,
	KEY_OPENBRACE = 65,
	KEY_CLOSEBRACE = 66,
	KEY_ENTER = 67,
	KEY_SEMICOLON = 68,
	KEY_QUOTE = 69,
	KEY_BACKSLASH = 70,
	KEY_BACKSLASH2 = 71,
	KEY_COMMA = 72,
	KEY_FULLSTOP = 73,
	KEY_SLASH = 74,
	KEY_SPACE = 75,
	KEY_INSERT = 76,
	KEY_DELETE = 77,
	KEY_HOME = 78,
	KEY_END = 79,
	KEY_PGUP = 80,
	KEY_PGDN = 81,
	KEY_LEFT = 82,
	KEY_RIGHT = 83,
	KEY_UP = 84,
	KEY_DOWN = 85,
	KEY_PAD_SLASH = 86,
	KEY_PAD_ASTERISK = 87,
	KEY_PAD_MINUS = 88,
	KEY_PAD_PLUS = 89,
	KEY_PAD_DELETE = 90,
	KEY_PAD_ENTER = 91,
	KEY_PRINTSCREEN = 92,
	KEY_PAUSE = 93,
	KEY_ABNT_C1 = 94,
	KEY_YEN = 95,
	KEY_KANA = 96,
	KEY_CONVERT = 97,
	KEY_NOCONVERT = 98,
	KEY_AT = 99,
	KEY_CIRCUMFLEX = 100,
	KEY_COLON2 = 101,
	KEY_KANJI = 102,
	KEY_PAD_EQUALS = 103,
	KEY_BACKQUOTE = 104,
	KEY_SEMICOLON2 = 105,
	KEY_COMMAND = 106,
	KEY_UNKNOWN = 107,
	KEY_MODIFIERS = 215,
	KEY_LSHIFT = 215,
	KEY_RSHIFT = 216,
	KEY_LCTRL = 217,
	KEY_RCTRL = 218,
	KEY_LALT = 219,
	KEY_RALT = 220,
	KEY_LWIN = 221,
	KEY_RWIN = 222,
	KEY_MENU = 223,
	KEY_SCROLLLOCK = 224,
	KEY_NUMLOCK = 225,
	KEY_CAPSLOCK = 226,
	KEYBOARD_MAX
}t_KEYBOARD_MAP;

#endif /* KEYBOARD_OF_H */