#include <object-of.h>

t_object	object_start(B32 id, B8 *name, t_image image)
{
	t_object	set;

	set.id = id;
	set.name = name;
	set.pos[0] = vi2d_start(0, 0);
	set.vel[0] = vi2d_start(1, 1);
	set.route[0] = vi2d_start(0, 0);
	set.axis[0] = vi2d_start(0, 0);
	set.zoom[0] = vf2d_start(1, 1);
	set.image[0] = image;
	set.angle = 0;
	return (set);
}

t_object	*object_set(B32 id, B8 *name, t_image image)
{
	t_object	*set = (t_object *)malloc(sizeof(t_object));
	set->id = id;
	set->name = name;
	set->pos[0] = vi2d_start(0, 0);
	set->vel[0] = vi2d_start(1, 1);
	set->route[0] = vi2d_start(0, 0);
	set->axis[0] = vi2d_start(0, 0);
	set->zoom[0] = vf2d_start(1, 1);
	set->image[0] = image;
	set->angle = 0;
	return (set);
}