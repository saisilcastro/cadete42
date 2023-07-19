#include <math-of.h>
#include <stdio.h>

int main(void)
{
	t_vf3d			c[4],p;
	t_determinant	d;
	c[0] = vf3d_start(30, 4, -8);
	c[1] = vf3d_start(45, -10, -3);
	c[2] = vf3d_start(3, 2, 4);
	c[3] = vf3d_start(422, 630, 71);
	determinant_get(&d, c, &p);
	printf("%f %f %f\n", p.x, p.y, p.z);
	return (0);
}