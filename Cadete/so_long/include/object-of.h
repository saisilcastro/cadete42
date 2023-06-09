#ifndef OBJECT_OF_H
#define OBJECT_OF_H

#include <system-of.h>
#include <math-of.h>
#include <image-of.h>

typedef struct s_object t_object;
struct s_object{
	B32		id;
	B8		*name;
	t_vi2d	pos[1];
	t_vi2d	vel[1];
	t_vi2d	route[1];
	t_vi2d	axis[1];
	t_vf2d	zoom[1];
	t_image	image[1];
	BP32	angle;
};

extern t_object	object_start(B32 id, B8 *name, t_image image);
extern t_object	*object_set(B32 id, B8 *name, t_image image);

#endif // OBJECT_OF_H