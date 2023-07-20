#include <math-of.h>
#include <stdio.h>

int main(void)
{
	t_vf3d			c[4],p;
	t_determinant	d;
	c[0] = vf3d_start(2, -3, 7);
	c[1] = vf3d_start(4, 2, -3);
	c[2] = vf3d_start(20, -8, 5);
	c[3] = vf3d_start(17, 6, 20);
	determinant_get(&d, c, &p);
	printf("%f %f %f\n", p.x, p.y, p.z);
	return (0);
}