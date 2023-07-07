/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_of.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:20:40 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/06 14:54:15 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_OF_H
# define OBJECT_OF_H

# include "system_of.h"
# include "math_of.h"
# include "image_of.h"

typedef enum e_OBJECT_DIRECTION{
	NOWHERE,
	NORTH,
	NORTHEAST,
	NORTHWEST,
	SOUTH,
	SOUTHEAST,
	SOUTHWEST,
	WEST,
	EAST,
}t_OBJECT_DIRECTION;

typedef struct s_object	t_object;
struct s_object{
	B32					id;
	B8					*name;
	t_vi2d				pos[1];
	t_vi2d				vel[1];
	t_vi2d				route[1];
	t_vi2d				axis[1];
	t_vf2d				zoom[1];
	t_image				*image;
	BP32				angle;
	t_OBJECT_DIRECTION	where;
};

extern t_object	object_start(B32 id, B8 *name, t_image *image);
extern t_object	*object_set(B32 id, B8 *name, t_vi2d pos, t_image *image);
extern void		object_pop(t_object *set);

#endif // OBJECT_OF_H