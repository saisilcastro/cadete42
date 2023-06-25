/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:16:02 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/24 14:21:07 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <machine.h>

static void	machine_function(t_machine *set);

void	machine_start(t_machine *set)
{
	short	i;
	t_image	*image;

	if (!set)
		return ;
	set->title = "so long";
	set->w = 800;
	set->h = 600;
	set->x = 320;
	set->y = 240;
	set->plugin = mlx_init();
	set->window = mlx_new_window(set->plugin, set->w, set->h, set->title);
	image = image_of_set(set->plugin, 0, vi2d_start(set->w, set->h));
	set->bg[0] = object_start(0, "background", image);
	set->image = NULL;
	set->object = NULL;
	BIT_ON(set->status, MACHINE_RUNNING);
	mouse_of_set(set->mouse, 0, 0, 0, 0);
	i = 0;
	while (i < 256)
		set->key[i++] = Off;
	machine_function(set);
}

static void	machine_map_create(t_machine *set, B32 w, B32 h)
{
	t_image	*image;

	if (!set)
		return ;
	image = image_of_set(set->plugin, 0, vi2d_start(w, h));
	set->bg[0] = object_start(0, "background", image);
	set->bg->image->buffer = mlx_new_image(set->plugin, set->bg->image->size->x,
			set->bg->image->size->y);
	set->bg->image->addr = mlx_get_data_addr(set->bg->image->buffer,
			&set->bg->image->bpp, &set->bg->image->length,
			&set->bg->image->endian);
}

void	machine_bg_draw(t_machine *set)
{
	if (!set || !set->bg->image->buffer)
		return ;
	mlx_put_image_to_window(set->plugin, set->window,
		set->bg->image->buffer, -set->bg->pos->x, -set->bg->pos->y);
}

void	machine_image_draw(t_image *image, t_pixel color)
{
	int		i;
	int		j;
	int		pixel;
	char	*dst;

	pixel = (color.a << 24 | color.r << 16 | color.g << 8 | color.b);
	j = 0;
	while (j < image->size->y)
	{
		i = 0;
		while (i < image->size->x)
		{
			dst = image->addr + (j * image->length + i * (image->bpp / 8));
			*(unsigned int *)dst = pixel;
			i++;
		}
		j++;
	}
}

void	machine_image_pixel(t_image *image, B32 x, B32 y)
{
	char	*dest;
	int		pixel;

	if (!image || !image->addr)
		return ;
	pixel = (image->color.a << 24 | image->color.r << 16
			| image->color.g << 8 | image->color.b);
	dest = image->addr + (y * image->length + x * (image->bpp / 8));
	*(unsigned int *)dest = pixel;
}	

void machine_bg_update(t_machine *set, unsigned char style)
{
	int	x;
	int	y;

	if (!set)
		return ;
	for (y = set->bg->pos->y; y < set->bg->image->size->y; y++)
		for (x = set->bg->pos->x; x < set->bg->image->size->x; x++)
		{
			if (style == 1)
			{
				set->bg->image->color.r = (rand() % 255);
				set->bg->image->color.g = (rand() % 255);
				set->bg->image->color.b = (rand() % 255);	
			}
			machine_image_pixel(set->bg->image, x, y);
		}
}

t_object	*machine_object_search(t_chained *chained, B32 id)
{
	t_chained	*update;
	t_object	*object;

	object = NULL;
	update = chained;
	while (update)
	{
		object = update->content;
		if (object->id == id)
			break ;
		update = update->next;
	}
	return (object);
}

static void	machine_object_remove(t_chained **set, B32 id)
{
	t_chained	*update;
	t_chained	*prev;
	t_chained	*next;
	t_object	*object;
	
	update = *set;
	while (update)
	{
		prev = update->preview;
		next = update->next;
		object = update->content;
		if (object->id == id)
		{
			free(update);
			if (prev)
			{
				update = prev;
				if (next)
					next->preview = update;
				update->next = next;
				*set = update;
			}
			else
			{
				next->preview = prev;
				*set = next;
			}
			break ;
		}
		update = next;
	}
}

static void	machine_object_create(t_machine *set, B32 id, t_vi2d pos, t_image *image)
{
	t_object	*object;
	t_image		*buffer;

	if (!set)
		return ;
	if (!image)
		buffer = image_of_set(set->plugin, 0, vi2d_start(16, 16));
	else
		buffer = image;
	object = object_set(id, "object", buffer);
	if (object)
	{
		object->pos->x = pos.x;
		object->pos->y = pos.y;
	}
	chained_next_first(&set->object, chained_new(object));
}

static void machine_image_load(t_machine *set, char *path, B32 id)
{
	void		*buffer;
	t_chained	*chained;
	B32			w;
	B32			h;

	if (!set || id < 0)
		return ;
	buffer = mlx_xpm_file_to_image(set->plugin, path, &w, &h);
	if (buffer)
	{
		chained = chained_new(image_of_buffer(buffer, id, vi2d_start(w, h)));
		chained_next_first(&set->image, chained);
	}
}

static t_image *machine_image_search(t_machine *set, B32 id)
{
	t_chained	*chained;
	t_image		*image;

	chained = set->image;
	while (chained)
	{
		image = chained->content;
		if (image->id == id)
			return (image);
		chained = chained->next;
	}
	return (NULL);
}

static STATUS	machine_object_move(t_object *object)
{
	STATUS		x_done;
	STATUS		y_done;

	if (!object)
		return (Off);
	x_done = Off;
	y_done = Off;
	if (object->pos->x == object->route->x)
	{
		if (object->pos->y > object->route->y)
		{
			object->pos->y -= object->vel->y;
			object->where = NORTH;
			if (object->pos->y < object->route->y)
			{
				object->pos->y = object->route->y;
				y_done = On;
			}
		}
		if (object->pos->y < object->route->y)
		{
			object->pos->y += object->vel->y;
			object->where = SOUTH;
			if (object->pos->y > object->route->y)
			{
				object->pos->y = object->route->y;
				y_done = On;
			}
		}
		x_done = On;
	}
	if (object->pos->y == object->route->y)
	{
		if (object->pos->x > object->route->x)
		{
			object->pos->x -= object->vel->x;
			object->where = WEST;
			if (object->pos->x < object->route->x)
			{
				object->pos->x = object->route->x;
				x_done = On;
			}
		}
		if (object->pos->x < object->route->x)
		{
			object->pos->x += object->vel->x;
			object->where = EAST;
			if (object->pos->x > object->route->x)
			{
				object->pos->x = object->route->x;
				x_done = On;
			}
		}
		y_done = On;
	}
	if (object->pos->x > object->route->x)
	{ // WEST
		object->pos->x -= object->vel->x;
		if (object->pos->x < object->route->x)
		{
			object->pos->x = object->route->x;
			x_done = On;
		}
		if (object->pos->y > object->route->y)
		{
			object->pos->y -= object->vel->y;
			object->where = NORTHWEST;
			if (object->pos->y < object->route->y)
			{
				object->pos->y = object->route->y;
				y_done = On;
			}
		}
		if (object->pos->y < object->route->y)
		{
			object->pos->y += object->vel->y;
			object->where = SOUTHWEST;
			if (object->pos->y > object->route->y)
			{
				object->pos->y = object->route->y;
				y_done = On;
			}
		}
	}
	if (object->pos->x < object->route->x)
	{  // EAST
		object->pos->x += object->vel->x;
		if (object->pos->x > object->route->x)
		{
			object->pos->x = object->route->x;
			x_done = On;
		}
		if (object->pos->y > object->route->y)
		{
			object->pos->y -= object->vel->y;
			object->where = NORTHEAST;
			if (object->pos->y < object->route->y)
			{
				object->pos->y = object->route->y;
				y_done = On;
			}
		}
		if (object->pos->y < object->route->y)
		{
			object->pos->y += object->vel->y;
			object->where = SOUTHEAST;
			if (object->pos->y > object->route->y)
			{
				object->pos->y = object->route->y;
				y_done = On;
			}
		}
	}
	if (x_done && y_done)
	{
		object->where = NOWHERE;
		return (On);
	}
	return (Off);
}

static void	machine_route_set(t_object *object, B32 x, B32 y)
{	
	if (!object)
		return ;
	object->route->x = x;
	object->route->y = y;
}

static STATUS	machine_object_route(t_object *object)
{	
	if (!object)
		return (Off);
	if (object->pos->x == object->route->x && object->pos->y == object->route->y)
		return (On);
	return (machine_object_move(object));
}

static int	mlx_key_down(int keycode, t_machine *set)
{
	set->key[linux_key_get(keycode)] = On;
	return (0);
}

static int	mlx_key_up(int keycode, t_machine *set)
{
	set->key[linux_key_get(keycode)] = Off;
	return (0);
}

static void machine_mouse_pos(t_machine *set)
{
	if (!set)
		return ;
	mlx_mouse_get_pos(set->plugin, set->window, &set->mouse->x, &set->mouse->y);
}

static int mlx_mouse_update(int button, int x, int y, t_machine *set)
{
	if (!set)
		return (0);
	set->mouse->x = x;
	set->mouse->y = y;
	if (button == 1)
		BIT_ON(set->mouse->button, MACHINE_MOUSE_LEFT);
	if (button == 2)
		BIT_ON(set->mouse->button, MACHINE_MOUSE_MIDDLE);
	if (button == 3)
		BIT_ON(set->mouse->button, MACHINE_MOUSE_RIGHT);
	if (button == 4)
		BIT_ON(set->mouse->wheel, MACHINE_WHEEL_UP);
	if (button == 5)
		BIT_ON(set->mouse->wheel, MACHINE_WHEEL_DOWN);
	return (0);
}

static int mlx_mouse_press(int button, int x, int y, t_machine *set)
{
	if (!set)
		return (0);
	set->mouse->x = x;
	set->mouse->y = y;
	if (button == 1)
		BIT_ON(set->mouse->button, MACHINE_MOUSE_LEFT);
	if (button == 2)
		BIT_ON(set->mouse->button, MACHINE_MOUSE_MIDDLE);
	if (button == 3)
		BIT_ON(set->mouse->button, MACHINE_MOUSE_RIGHT);
	return (0);
}

static int mlx_mouse_release(int button, int x, int y, t_machine *set)
{
	if (!set || !button)
		return (0);
	set->mouse->x = x;
	set->mouse->y = y;
	if (button == 1)
		BIT_OFF(set->mouse->button, MACHINE_MOUSE_LEFT);
	if (button == 2)
		BIT_OFF(set->mouse->button, MACHINE_MOUSE_MIDDLE);
	if (button == 3)
		BIT_OFF(set->mouse->button, MACHINE_MOUSE_RIGHT);
	return (0);
}

static STATUS machine_mouse_press(t_machine *set, MACHINE_MOUSE_BUTTON button)
{
	if (!set)
		return (Off);
	return (BIT_IS_ON(set->mouse->button, button));
}

STATUS machine_mouse_release(t_machine *set, MACHINE_MOUSE_BUTTON button)
{
	if (!set)
		return (Off);
	return (BIT_IS_ON(set->mouse->button, button));
}

static void	machine_draw(t_machine *set)
{
	t_chained	*chained;
	t_object	*object;

	if (!set)
		return ;
	set->bg_draw(set);
	chained = set->object;
	while (chained)
	{
		object = chained->content;
		mlx_put_image_to_window(set->plugin, set->window, object->image->buffer, object->pos->x, object->pos->y);
		chained = chained->next;
	}
}

void machine_destroy_window(t_machine *set)
{
	if (!set)
		return ;
	mlx_destroy_window(set->plugin, set->window);
}

STATUS machine_running(t_machine *set)
{
	if (!set)
		return (Off);
	return (BIT_IS_ON(set->status, MACHINE_RUNNING));
}

static void machine_print(t_machine *set, B32 x, B32 y, t_pixel color, char *str)
{
	int pixel = (color.a << 24 | color.r << 16 | color.g << 8 | color.b);
	mlx_string_put(set->plugin, set->window, x, y, pixel, str);
}

static void machine_put_pixel(t_machine *set, B32 x, B32 y, t_pixel color)
{
	int pixel = (color.a << 24 | color.r << 16 | color.g << 8 | color.b);
	set->bg->image->color = color;
	machine_image_pixel(set->bg->image, x, y);
	mlx_pixel_put(set->plugin, set->window, x, y, pixel);
}

static STATUS machine_key_get(t_machine *set, KEYBOARD_MAP keycode)
{
	if (!set)
		return (Off);
	return (set->key[keycode]);
}

static void machine_function(t_machine *set)
{
	set->map_create = machine_map_create;
	set->object_create = machine_object_create;
	set->image_load = machine_image_load;
	set->image_search = machine_image_search;
	set->object_search = machine_object_search;
	set->object_remove = machine_object_remove;
	set->route_set = machine_route_set;
	set->object_route = machine_object_route;
	set->init = NULL;
	set->draw = machine_draw;
	set->bg_draw = machine_bg_draw;
	set->key_get = machine_key_get;
	set->mouse_press = machine_mouse_press;
	set->mouse_release = machine_mouse_release;
	set->mouse_pos = machine_mouse_pos;
	set->running = machine_running;
	set->update = NULL;
	set->put_pixel = machine_put_pixel;
	set->print = machine_print;
}

static int mlx_expose(t_machine *set)
{
	if (!set)
		return (0);
	// printf("here we go\n");
	return (0);
}

void machine_run(t_machine *set)
{
	if (set->init)
		set->init(set);
	if (set->update)
		mlx_loop_hook(set->plugin, set->update, set);
	mlx_hook(set->window, ON_KEYUP, KEY_PRESS_MASK, mlx_key_up, set);
	mlx_hook(set->window, ON_KEYDOWN, KEY_RELEASE_MASK, mlx_key_down, set);
	mlx_expose_hook(set->window, mlx_expose, set);
	mlx_mouse_hook(set->window, mlx_mouse_update, set);
	mlx_hook(set->window, ON_MOUSEDOWN, MOUSE_PRESS_MASK, mlx_mouse_press, set);
	mlx_hook(set->window, ON_MOUSEUP, MOUSE_RELEASE_MASK, mlx_mouse_release, set);
	if (set->update)
		set->update(set);
	mlx_loop(set->plugin);
	if (set->bg->image)
		image_of_destroy(set->plugin, set->bg->image->buffer);
	mlx_destroy_display(set->plugin);
	if (set->object)
		set->object->destroy(set->object);
	free(set->plugin);
}
