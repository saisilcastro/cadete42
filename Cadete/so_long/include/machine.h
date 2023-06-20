/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:05:09 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/19 15:18:28 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHINE_H
# define MACHINE_H

#include <system-of.h>
#include <math-of.h>
#include <chained-of.h>
#include <linux-of.h>
#include <mouse-of.h>
#include <pixel-of.h>
#include <object-of.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>

typedef struct s_machine	t_machine;
struct s_machine{
	void		*plugin;
	void		*window;
	B8			*title;
	B32			w;
	B32			h;
	B32			x;
	B32			y;
	STATUS		key[255];
	t_mouse		mouse[1];
	t_object	bg[1];
	t_chained	*image;
	t_chained	*object;
	unsigned	status:MAX_EVENT;
	void		(*init)(t_machine *set);
	void		(*map_load)(t_machine *set, B32 id);
	void		(*map_create)(t_machine *set, B32 w, B32 h);
	void		(*image_load)(t_machine *set, char *path, B32 id);
	t_image		*(*image_search)(t_machine *set, B32 id);
	void		(*object_create)(t_machine *set, B32 id,
			t_vi2d pos, t_image *image);
	t_object	*(*object_search)(t_chained *set, B32 id);
	void		(*route_set)(t_object *set, B32 x, B32 y);
	STATUS		(*object_route)(t_object * object);
	void		(*bg_draw)(t_machine *set);
	void		(*draw)(t_machine *set);
	STATUS		(*key_get)(t_machine *set, KEYBOARD_MAP keycode);
	STATUS		(*mouse_press)(t_machine *set, MACHINE_MOUSE_BUTTON button);
	STATUS		(*mouse_release)(t_machine *set, MACHINE_MOUSE_BUTTON button);
	void		(*mouse_pos)(t_machine *set);
	STATUS		(*running)(t_machine * set);
	int			(*update)(t_machine *set);
	void		(*put_pixel)(t_machine *set, B32 x, B32 y, t_pixel color);
	void		(*print)(t_machine *set, B32 x, B32 y,
			t_pixel color, char *str);
};

extern void	machine_start(t_machine *set);
extern void	machine_bg_update(t_machine *set, unsigned char style);
extern void	machine_run(t_machine *set);
extern void	machine_destroy_window(t_machine *set);

#endif // MACHINE_H