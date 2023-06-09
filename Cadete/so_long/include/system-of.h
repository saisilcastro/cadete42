/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system-of.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:30:42 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/22 09:28:19 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_OF_H
#define SYSTEM_OF_H

#include <stdlib.h>
#include <string.h>

#if defined WIN32 || defined WIN64 || defined WINDOWS_XP

#include <winsock2.h>
#include <windows.h>

#define MAX_FILE_NAME (_MAX_PATH + _MAX_FNAME)

#include <unistd.h>
#include <conio.h>
#define _getch getch
#define _kbhit kbhit

#elif __linux__

#include <linux/limits.h>

#define MAX_FILE_NAME (PATH_MAX + NAME_MAX)

#include <unistd.h>

#endif

#define ARRAY_SIZE(a)(sizeof(a) / sizeof(a[0]))

#if defined(UNICODE) || defined(_UNICODE)
#define STR(s) L##s
#else
#define STR(s) s
#endif

#define NEXT(a)(a = a->next)

#define get_dir getcwd

typedef void BO;
typedef char B8;
typedef unsigned char B8U;
typedef short B16;
typedef unsigned short B16U;
typedef int B32;
typedef unsigned int B32U;
typedef long long int B64;
typedef long long int unsigned B64U;
typedef float BP32;
typedef double BP64;

#define B8C(a)((B8*)a)
#define B8UC(a)((B8U*)a)

typedef enum {
    SYSTEM_MAIN_NONE,
    SYSTEM_CONSOLE,
    SYSTEM_PRIMARY,
    SYSTEM_SDL,
    SYSTEM_ALLEGRO,
    SYSTEM_MINILIBX
} SYSTEM_MAIN;

typedef enum {
    GRAPHIC_CONSOLE,
    GRAPHIC_PRIMARY,
    GRAPHIC_OPENGL,
    GRAPHIC_DIRECTX
} SYSTEM_GRAPHIC;

typedef enum {
    SYSTEM_AUDIO_NONE,
    SYSTEM_AUDIO_PRIMARY,
    SYSTEM_AUDIO_ALLEGRO,
    SYSTEM_AUDIO_SDL
} SYSTEM_AUDIO;

typedef enum {
    SYSTEM_NETWORK_NONE,
    SYSTEM_NETWORK_PRIMARY,
    SYSTEM_NETWORK_SDL
} SYSTEM_NETWORK;

typedef struct {
    SYSTEM_MAIN system;
    SYSTEM_GRAPHIC driver;
    SYSTEM_AUDIO audio;
    SYSTEM_NETWORK network;
} SystemSet;

typedef enum {
    Off,
    On
} STATUS;

#define BIT_ON(var, bit)(var |= (1 << bit))
#define BIT_OFF(var, bit)(var &= ~(1 << bit))
#define BIT_IS_ON(var, bit)(var & (1 << bit) ? 1 : 0)
#define BIT_TOGGLE(var, bit)(var ^= (1 << bit))

typedef enum {
    WINDOW_LEFT_CENTER = 0x7ffd,
    WINDOW_TOP_CENTER = 0x7ffe,
    WINDOW_WIDTH = 640,
    WINDOW_HEIGHT = 480
} WINDOW_STANDARD;

typedef enum {
    MACHINE_RUNNING = 0,
    MACHINE_FULLSCREEN = 1,
	MACHINE_MOUSE_MOVE = 2,
    MACHINE_FOCUS_ON = 3,
    MACHINE_MOUSE_IN = 4,
    MACHINE_KEY_PRESSED = 5,
    MACHINE_CAMERA_MOUSE = 6,
    MACHINE_CAMERA_OBJECT = 7,
    MACHINE_VIDEO_PLAYING = 8,
    MACHINE_VSYNC = 9,
    MACHINE_DRAW = 10,
    MAX_EVENT
} MACHINE_EVENT;

typedef enum {
    MACHINE_MOUSE_LEFT = 0,
    MACHINE_MOUSE_MIDDLE = 1,
    MACHINE_MOUSE_RIGHT = 2,
    MACHINE_MOUSE_MAX
} MACHINE_MOUSE_BUTTON;

typedef enum {
    MACHINE_WHEEL_UP = 0,
    MACHINE_WHEEL_DOWN = 1,
    MACHINE_WHEEL_MAX
} MACHINE_MOUSE_WHEEL;

typedef enum {
    MACHINE_FINGER_PRESS = 0
} MACHINE_TOUCH;

typedef enum {
    MACHINE_JOY_LEFT = 0,
    MACHINE_JOY_UP = 1,
    MACHINE_JOY_RIGHT = 2,
    MACHINE_JOY_DOWN = 3
} MACHINE_JOYSTICK;

#define HALF(x)((x) >> 1)
#define DOUBLE(x)((x) << 1)

#endif