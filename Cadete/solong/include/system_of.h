/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_of.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:38:36 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/19 14:11:57 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_OF_H
# define SYSTEM_OF_H

typedef enum e_status	t_status;
enum e_status{
	Off,
	On
};

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
# define BP128 long double

typedef enum e_system_main{
	SYSTEM_CONSOLE,
	SYSTEM_MINILIBX
}t_system_main;

typedef enum e_system_graphic{
	GRAPHIC_CONSOLE,
	GRAPHIC_PRIMARY,
	GRAPHIC_OPENGL,
	GRAPHIC_DIRECTX
}t_system_graphic;

typedef enum e_system_audio{
	SYSTEM_AUDIO_NONE,
	SYSTEM_AUDIO_PRIMARY
}t_system_audio;

typedef enum e_system_network{
	SYSTEM_NETWORK_NONE,
	SYSTEM_NETWORK_PRIMARY
}t_system_network;

typedef struct s_SystemSet{
	t_system_main		system;
	t_system_graphic	driver;
	t_system_audio		audio;
	t_system_network	lan;
}t_SystemSet;

typedef enum s_machine_event{
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
}t_machine_event;

typedef enum s_window_standard{
	WINDOW_LEFT_CENTER = 0x7ffd,
	WINDOW_TOP_CENTER = 0x7ffe,
	WINDOW_WIDTH = 640,
	WINDOW_HEIGHT = 480
}t_window_standard;

typedef enum s_mouse_button{
	MACHINE_MOUSE_LEFT = 0,
	MACHINE_MOUSE_MIDDLE = 1,
	MACHINE_MOUSE_RIGHT = 2,
	MACHINE_MOUSE_MAX
}t_mouse_button;

typedef enum s_mouse_wheel{
	MOUSE_WHEEL_UP = 0,
	MOUSE_WHEEL_DOWN = 1,
	MOUSE_WHEEL_MAX
}t_mouse_wheel;

typedef enum s_machine_touch{
	MACHINE_FINGER_PRESS
}t_machine_touch;

typedef enum s_machine_joystick{
	MACHINE_JOY_LEFT = 0,
	MACHINE_JOY_UP = 1,
	MACHINE_JOY_RIGHT = 2,
	MACHINE_JOY_DOWN = 3
}t_machine_joystick;

#endif // SYSTEM_OF_H