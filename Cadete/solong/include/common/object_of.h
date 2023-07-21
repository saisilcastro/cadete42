/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_of.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:20:40 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/20 09:16:42 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_OF_H
# define OBJECT_OF_H

# include "system_of.h"
# include "math_of.h"
# include "image_of.h"

typedef enum e_object_status{
	OBJECT_VISIBLE = 0,
	OBJECT_MOVING = 1
}t_object_status;

typedef enum e_object_direction{
	NORTH,
	NORTHEAST,
	NORTHWEST,
	SOUTH,
	SOUTHEAST,
	SOUTHWEST,
	WEST,
	EAST,
}t_object_direction;

typedef struct s_object	t_object;
struct s_object{
	int					id;
	char				*name;
	t_vi2d				pos[1];
	t_vi2d				vel[1];
	t_vi2d				dest[1];
	t_vi2d				axis[1];
	t_vf2d				zoom[1];
	t_image				*image;
	float				angle;
	t_object_direction	where;
	unsigned			status:1;
};

extern t_object	object_start(int id, char *name, t_image *image);
extern t_object	*object_set(int id, char *name, t_vi2d pos, t_image *image);
extern void		object_clone(t_object *src, t_object *dest);
extern t_status	object_name_is(t_object *obj, char *name);
extern t_status	up_dir(t_object *obj);
extern t_status	mid_dir(t_object *obj);
extern t_status	down_dir(t_object *obj);
extern t_status	object_route(t_object *obj);
extern t_status	object_collision(t_object *ob1, t_object *ob2);
extern t_status	object_block(t_object *ob1);
extern void		object_pop(t_object *set);

#endif // OBJECT_OF_H