/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_of.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:38:36 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/30 19:23:47 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_OF_H
# define SYSTEM_OF_H

typedef enum e_STATUS{
	Off,
	On
}t_STATUS;

# define BO void
# define B8 char
# define B8U unsigned char
# define B16 short
# define B16U unsigned short
# define B32 int
# define B32U unsigned int
# define B64 long long
# define B64U unsigned long long
# define BP32 float
# define BP64 double

typedef enum e_SYSTEM_MAIN{
	SYSTEM_CONSOLE,
	SYSTEM_MINILIBX
}t_SYSTEM_MAIN;

typedef enum e_SYSTEM_GRAPHIC{
	GRAPHIC_CONSOLE,
	GRAPHIC_PRIMARY,
	GRAPHIC_OPENGL,
	GRAPHIC_DIRECTX
}t_SYSTEM_GRAPHIC;

typedef enum e_SYSTEM_AUDIO{
	SYSTEM_AUDIO_NONE,
	SYSTEM_AUDIO_PRIMARY
}t_SYSTEM_AUDIO;

typedef enum e_SYSTEM_NETWORK{
	SYSTEM_NETWORK_NONE,
	SYSTEM_NETWORK_PRIMARY
}t_SYSTEM_NETWORK;

typedef struct s_SystemSet{
	t_SYSTEM_MAIN		system;
	t_SYSTEM_GRAPHIC	driver;
	t_SYSTEM_AUDIO		audio;
	t_SYSTEM_NETWORK	lan;
}t_SystemSet;

typedef enum s_MACHINE_EVENT{
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
}t_MACHINE_EVENT;

typedef enum s_WINDOW_STANDARD{
	WINDOW_LEFT_CENTER = 0x7ffd,
	WINDOW_TOP_CENTER = 0x7ffe,
	WINDOW_WIDTH = 640,
	WINDOW_HEIGHT = 480
}t_WINDOW_STANDARD;

typedef enum s_MOUSE_BUTTON{
	MACHINE_MOUSE_LEFT = 0,
	MACHINE_MOUSE_MIDDLE = 1,
	MACHINE_MOUSE_RIGHT = 2,
	MACHINE_MOUSE_MAX
}t_MOUSE_BUTTON;

typedef enum s_MOUSE_WHEEL{
	MOUSE_WHEEL_UP = 0,
	MOUSE_WHEEL_DOWN = 1,
	MOUSE_WHEEL_MAX
}t_MOUSE_WHEEL;

typedef enum s_MACHINE_TOUCH{
	MACHINE_FINGER_PRESS
}t_MACHINE_TOUCH;

typedef enum s_MACHINE_JOYSTICK{
	MACHINE_JOY_LEFT = 0,
	MACHINE_JOY_UP = 1,
	MACHINE_JOY_RIGHT = 2,
	MACHINE_JOY_DOWN = 3
}t_MACHINE_JOYSTICK;

#endif // SYSTEM_OF_H