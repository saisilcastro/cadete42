/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:37:47 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/20 09:14:02 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACHINE_H
# define MACHINE_H

# include <stdlib.h>
# include <system_of.h>
# include <keyboard_of.h>
# include <mouse_of.h>
# include <object_of.h>
# include <chained_of.h>
# include <math_of.h>

typedef struct s_machine{
	t_SystemSet		up[1];
	char			*title;
	t_vi2d			size[1];
	t_vi2d			pos[1];
	void			*plugin;
	t_object		bg[1];
	t_chained		*image;
	t_chained		*object;
	t_status		key[255];
	t_mouse			mouse[1];
	unsigned		event:MAX_EVENT;
}t_machine;

extern void		machine_set(t_machine *set,
					t_SystemSet up, char *title, t_vi2d size);
extern t_status	machine_start(t_machine *set);
extern void		machine_draw(t_machine *set, t_object *obj);
extern void		machine_pop(t_machine *set);

#endif //MACHINE_H