#include <stdio.h>

float normalise(float piece, float whole, float to_be_normal)
{
	return ((piece / whole) * to_be_normal);
}

int	main(void)
{
	float	w = 800;
	float	piece = 300;

	printf("%f\n", normalise(piece, w, 1));
	return (0);
}
