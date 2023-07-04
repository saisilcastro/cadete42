
#include <mlx.h>
#include <stdlib.h>

typedef struct s_mlx_plugin t_mlx_plugin;
struct s_mlx_plugin{
	void    *lead;
	void    *window;
};
int main(void)
{
	t_mlx_plugin mlx;
	mlx.lead = mlx_init();
	if (!mlx.lead)
		return (-1);
	mlx.window = mlx_new_window(mlx.lead, 640, 480, "machine");
	if (!mlx.window)
		return (-2);
	mlx_destroy_window(mlx.lead, mlx.window);
	return (0);
}