/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux-keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:15:36 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/04 05:22:23 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux_keyboard_of.h>

t_KEYBOARD_MAP	linux_key_get(int keycode)
{
	if (keycode == 0x0030)
		return (KEY_0);
	if (keycode == 0x0031)
		return (KEY_1);
	if (keycode == 0x0032)
		return (KEY_2);
	if (keycode == 0x0033)
		return (KEY_3);
	if (keycode == 0x0034)
		return (KEY_4);
	if (keycode == 0x0035)
		return (KEY_5);
	if (keycode == 0x0036)
		return (KEY_6);
	if (keycode == 0x0037)
		return (KEY_7);
	if (keycode == 0x0038)
		return (KEY_8);
	if (keycode == 0x0039)
		return (KEY_9);
	if (keycode == 0x0061)
		return (KEY_A);
	if (keycode == 0x0062)
		return (KEY_B);
	if (keycode == 0x0063)
		return (KEY_C);
	if (keycode == 0x0064)
		return (KEY_D);
	if (keycode == 0x0065)
		return (KEY_E);
	if (keycode == 0x0066)
		return (KEY_F);
	if (keycode == 0x0067)
		return (KEY_G);
	if (keycode == 0x0068)
		return (KEY_H);
	if (keycode == 0x0069)
		return (KEY_I);
	if (keycode == 0x006A)
		return (KEY_J);
	if (keycode == 0x006B)
		return (KEY_K);
	if (keycode == 0x006C)
		return (KEY_L);
	if (keycode == 0x006D)
		return (KEY_M);
	if (keycode == 0x006E)
		return (KEY_N);
	if (keycode == 0x006F)
		return (KEY_O);
	if (keycode == 0x0070)
		return (KEY_P);
	if (keycode == 0x0071)
		return (KEY_Q);
	if (keycode == 0x0072)
		return (KEY_R);
	if (keycode == 0x0073)
		return (KEY_S);
	if (keycode == 0x0074)
		return (KEY_T);
	if (keycode == 0x0075)
		return (KEY_U);
	if (keycode == 0x0076)
		return (KEY_V);
	if (keycode == 0x0077)
		return (KEY_W);
	if (keycode == 0x0078)
		return (KEY_X);
	if (keycode == 0x0079)
		return (KEY_Y);
	if (keycode == 0x007A)
		return (KEY_Z);
	if (keycode == 0x0020)
		return (KEY_SPACE);
	if (keycode == 0x002C)
		return (KEY_COMMA);
	if (keycode == 0x002D)
		return (KEY_MINUS);
	if (keycode == 0x003D)
		return (KEY_EQUALS);
	if (keycode == 0x005B)
		return (KEY_OPENBRACE);
	if (keycode == 0x005D)
		return (KEY_CLOSEBRACE);
	if (keycode == 0xFF08)
		return (KEY_BACKSPACE);
	if (keycode == 0xFF09)
		return (KEY_TAB);
	if (keycode == 0xFF13)
		return (KEY_FULLSTOP);
	if (keycode == 0xFF0D)
		return (KEY_ENTER);
	if (keycode == 0xFE53)
		return (KEY_TILDE);
	if (keycode == 0xFF1B)
		return (KEY_ESC);
	if (keycode == 0xFF51)
		return (KEY_LEFT);
	if (keycode == 0xFF52)
		return (KEY_UP);
	if (keycode == 0xFF54)
		return (KEY_DOWN);
	if (keycode == 0xFF53)
		return (KEY_RIGHT);
	if (keycode == 0xFF63)
		return (KEY_INSERT);
	if (keycode == 0xFFFF)
		return (KEY_DELETE);
	if (keycode == 0xFF50)
		return (KEY_HOME);
	if (keycode == 0xFF57)
		return (KEY_END);
	if (keycode == 0xFF55)
		return (KEY_PGUP);
	if (keycode == 0xFF56)
		return (KEY_PGDN);
	if (keycode == 0xFF51)
		return (KEY_LEFT);
	if (keycode == 0xFF52)
		return (KEY_UP);
	if (keycode == 0xFF53)
		return (KEY_RIGHT);
	if (keycode == 0xFF54)
		return (KEY_DOWN);
	if (keycode == 0xFF9E)
		return (KEY_PAD_0);
	if (keycode == 0xFF9C)
		return (KEY_PAD_1);
	if (keycode == 0xFF99)
		return (KEY_PAD_2);
	if (keycode == 0xFF9B)
		return (KEY_PAD_3);
	if (keycode == 0xFF96)
		return (KEY_PAD_4);
	if (keycode == 0xFF9D)
		return (KEY_PAD_5);
	if (keycode == 0xFF98)
		return (KEY_PAD_6);
	if (keycode == 0xFF95)
		return (KEY_PAD_7);
	if (keycode == 0xFF97)
		return (KEY_PAD_8);
	if (keycode == 0xFF9A)
		return (KEY_PAD_9);
	if (keycode == 0xFFBE)
		return (KEY_F1);
	if (keycode == 0xFFBF)
		return (KEY_F2);
	if (keycode == 0xFFC0)
		return (KEY_F3);
	if (keycode == 0xFFC1)
		return (KEY_F4);
	if (keycode == 0xFFC2)
		return (KEY_F5);
	if (keycode == 0xFFC3)
		return (KEY_F6);
	if (keycode == 0xFFC4)
		return (KEY_F7);
	if (keycode == 0xFFC5)
		return (KEY_F8);
	if (keycode == 0xFFC6)
		return (KEY_F9);
	if (keycode == 0xFFC7)
		return (KEY_F10);
	if (keycode == 0xFFC8)
		return (KEY_F11);
	if (keycode == 0xFFC9)
		return (KEY_F12);
	return (KEY_NONE);
}

