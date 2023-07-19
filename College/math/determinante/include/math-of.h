#ifndef MATH_OF_H
#define MATH_OF_H

typedef struct s_vf3d	t_vf3d;
struct s_vf3d{
	float	x;
	float	y;
	float	z;
};

extern t_vf3d	vf3d_start(float x, float y, float z);

typedef struct s_determinante	t_determinant;
struct s_determinante{
	float	d;
	float	x;
	float	y;
	float	z;
};

typedef enum{
	DETERMINANT_X,
	DETERMINANT_Y,
	DETERMINANT_Z,
	DETERMINANT
}determinat_show;

extern t_determinant	determinant_start(float d, float x, float y, float z);
extern void				show(t_vf3d *c, determinat_show show);
extern void				determinant_get(t_determinant *d, t_vf3d *c, t_vf3d *p);

#endif // MATH_OF_H