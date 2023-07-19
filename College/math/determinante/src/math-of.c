#include <math-of.h>
#include <stdio.h>

t_vf3d	vf3d_start(float x, float y, float z)
{
	t_vf3d set = {.x = x, .y = y,.z = z};
	return (set);
}

t_determinant	determinant_start(float d, float x, float y, float z)
{
	t_determinant	set = {.d = d, .x = x, .y = y,.z = z};
	return (set);
}

void	show(t_vf3d *c, determinat_show show)
{
	if (show == DETERMINANT_X)
	{
		printf("[3].x %f\t[0].y %f\t[0].z %f\t[3].x %f\t[0].y %f\n", c[3].x, c[0].y, c[0].z, c[3].x, c[0].y);
		printf("[3].y %f\t[1].y %f\t[1].z %f\t[3].y %f\t[1].y %f\n", c[3].y, c[1].y, c[1].z, c[3].y, c[1].y);
		printf("[3].z %f\t[2].y %f\t[2].z %f\t[3].z %f\t[2].y %f\n", c[3].z, c[2].y, c[2].z, c[3].z, c[2].y);
	}
	if (show == DETERMINANT_Y)
	{
		printf("[0].x %f\t[3].x %f\t[0].z %f\t[0].x %f\t[3].x %f\n", c[0].x, c[3].x, c[0].z, c[0].x, c[3].x);
		printf("[1].x %f\t[3].y %f\t[1].z %f\t[1].x %f\t[3].y %f\n", c[1].x, c[3].y, c[1].z, c[1].x, c[3].y);
		printf("[2].x %f\t[3].z %f\t[2].z %f\t[2].x %f\t[3].z %f\n", c[2].x, c[3].z, c[2].z, c[2].x, c[3].z);
	}
	if (show == DETERMINANT_Z)
	{
		printf("[0].x %f\t[0].y %f\t[3].x %f\t[0].x %f\t[0].y %f\n", c[0].x, c[0].y, c[3].x, c[0].x, c[0].y);
		printf("[1].x %f\t[1].y %f\t[3].y %f\t[1].x %f\t[1].y %f\n", c[1].x, c[1].y, c[3].y, c[1].x, c[1].y);
		printf("[2].x %f\t[2].y %f\t[3].z %f\t[2].x %f\t[2].y %f\n", c[2].x, c[2].y, c[3].z, c[2].x, c[2].y);
	}
	if (show == DETERMINANT)
	{
		printf("[0].x %f\t[0].y %f\t[0].z %f\t[0].x %f\t[0].y %f\n", c[0].x, c[0].y, c[0].z, c[0].x, c[0].y);
		printf("[1].x %f\t[1].y %f\t[1].z %f\t[1].x %f\t[1].y %f\n", c[1].x, c[1].y, c[1].z, c[1].x, c[1].y);
		printf("[2].x %f\t[2].y %f\t[2].z %f\t[2].x %f\t[2].y %f\n", c[2].x, c[2].y, c[2].z, c[2].x, c[2].y);
	}
}

void	determinant_x(t_determinant *d, t_vf3d *c)
{
	float	p;
	float	s;
	p = (c[3].x * c[1].y * c[2].z) + (c[0].y * c[1].z * c[3].z) + (c[0].z * c[3].y * c[2].y);
	s = (c[3].z * c[1].y * c[0].z) + (c[2].y * c[1].z * c[3].x) + (c[2].z *c[3].y * c[0].y);
	d->x = p - s;
}

void	determinant_y(t_determinant *d, t_vf3d *c)
{
	float	p;
	float	s;
	p = (c[0].x * c[3].y * c[2].z) + (c[3].x * c[1].z * c[2].x) + (c[0].z * c[1].x * c[3].z);
	s = (c[2].x * c[3].y * c[0].z) + (c[3].z * c[1].z * c[0].x) + (c[2].z *c[1].x * c[3].x);
	d->y = p - s;
}

void	determinant_z(t_determinant *d, t_vf3d *c)
{
	float	p;
	float	s;
	p = (c[0].x * c[1].y * c[3].z) + (c[0].y * c[3].y * c[2].x) + (c[3].x * c[1].x * c[2].y);
	s = (c[2].x * c[1].y * c[3].x) + (c[2].y * c[3].y * c[0].x) + (c[3].z *c[1].x * c[0].y);
	d->z = p - s;
}

void	determinant(t_determinant *d, t_vf3d *c)
{
	float	p;
	float	s;
	p = (c[0].x * c[1].y * c[2].z) + (c[0].y * c[1].z * c[2].x) + (c[0].z * c[1].x * c[2].y);
	s = (c[2].x * c[1].y * c[0].z) + (c[2].y * c[1].z * c[0].x) + (c[2].z *c[1].x * c[0].y);
	d->d = p - s;
}

void	determinant_get(t_determinant *d, t_vf3d *c, t_vf3d *p)
{
	determinant_x(d, c);
	determinant_y(d, c);
	determinant_z(d, c);
	determinant(d, c);
	p->x = d->x / d->d;
	p->y = d->y / d->d;
	p->z = d->z / d->d;
}