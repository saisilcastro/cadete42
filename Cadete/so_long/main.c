#include <machine.h>

void	local_init(t_machine *set)
{
	B32 id;
	B32 x;
	B32 y;

	if (!set)
		return ;
	set->map_create(set, set->w, set->h);
	id = 0;
	while (id < 10)
	{
		x = rand() % set->w;
		y = rand() % set->h;
		set->object_create(set, id, vi2d_start(16, 16), vi2d_start(x, y));
		id++;
	}
}

int		local_update(t_machine *set)
{
	static int	selected;
	t_chained	*chained;
	t_object	*object;
	t_pixel color = {0, 255, 0, 255};

	if (!set)
		return (0);
	machine_bg_update(set, 1);
	set->draw(set);
	set->mouse_pos(set);
	if (set->key_get(set, KEY_Q))
		machine_destroy_window(set);
	if (set->mouse_press(set, MACHINE_MOUSE_LEFT))
		set->put_pixel(set, set->mouse->x, set->mouse->y, color);
	if (set->mouse_press(set, MACHINE_MOUSE_RIGHT))
		printf("clica a mae\n");
	if (set->mouse->x > 0 && set->mouse->x < 50
		&& set->mouse->y > 0 && set->mouse->y < 50)
		printf("ai carai\n");
	if (set->key_get(set, KEY_N))
	{
		selected++;
		if (selected > 9)
			selected = 0;
	}
	chained = set->object;
	while (chained)
	{
		object = chained->content;
		if (object->id == selected)
		{
			if (set->key_get(set, KEY_LEFT))
				object->pos->x--;
			if (set->key_get(set, KEY_RIGHT))
				object->pos->x++;
			if (set->key_get(set, KEY_UP))
				object->pos->y--;
			if (set->key_get(set, KEY_DOWN))
				object->pos->y++;
		}
		else
		{
			if (set->object_route(object))
			{
				object->route->x = (rand() % set->w);
				object->route->y = (rand() % set->h);
			}
		}
		chained = chained->next;
	}
	return (0);
}

int	main(void)
{
	t_machine	where;

	machine_start(&where);
	where.init = local_init;
	where.update = local_update;
	machine_run(&where);
	return (0);
}
