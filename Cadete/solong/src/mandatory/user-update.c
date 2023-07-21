/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:03:07 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/20 01:19:34 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

static void	ft_putnbr_fd(int n, int fd)
{
	char	multiply;
	char	number;

	multiply = 1;
	if (n > -10 && n < 0)
		write(fd, "-", 1);
	while (n <= -10 || n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n %= 10;
	}
	if (n < 0)
		multiply = -1;
	number = (n * multiply) + 48;
	write(fd, &number, 1);
}

static void	show_step(t_place *set, t_object *hero)
{
	if (hero->status & (1 << OBJECT_VISIBLE))
	{
		write(1, "moves ", 6);
		ft_putnbr_fd(set->step++, 1);
		write(1, "\n", 1);
	}
}

static void	hero_control(t_place *set, t_object *hero)
{
	place_camera_object(set, hero);
	if (set->key_down(set, KEY_LEFT) || set->key_down(set, KEY_A))
	{
		show_step(set, hero);
		hero->dest->x -= hero->vel->x;
	}
	if (set->key_down(set, KEY_RIGHT) || set->key_down(set, KEY_D))
	{
		show_step(set, hero);
		hero->dest->x += hero->vel->x;
	}
	if (set->key_down(set, KEY_UP) || set->key_down(set, KEY_W))
	{
		show_step(set, hero);
		hero->dest->y -= hero->vel->y;
	}
	if (set->key_down(set, KEY_DOWN) || set->key_down(set, KEY_S))
	{
		show_step(set, hero);
		hero->dest->y += hero->vel->y;
	}
}

void	hero_update(t_place *set, t_object *object)
{
	t_object	*collider;

	if (object->id == set->hero_id)
	{
		if (place_block_move(set, object))
			return ;
		hero_control(set, object);
		object_route(object);
		collider = place_object_collision(set, object);
		if (object_name_is(collider, "collect"))
		{
			collider->status &= ~(1 << OBJECT_VISIBLE);
			set->collect->current++;
		}
		else if (object_name_is(collider, "exit"))
			object->status &= ~(1 << OBJECT_VISIBLE);
	}
}

int	user_update(t_place *set)
{
	t_chained	*update;
	t_object	*object;

	if (!set)
		return (0);
	if (set->key_down(set, KEY_ESC))
		set->stop(set);
	update = set->gear->object;
	while (update)
	{
		object = update->data;
		hero_update(set, object);
		if (object_name_is(object, "exit"))
		{
			if (set->collect->current == set->collect->max)
				object->status |= (1 << OBJECT_VISIBLE);
		}
		update = update->next;
	}
	set->draw_bg(set);
	return (!set->destroy(set));
}
