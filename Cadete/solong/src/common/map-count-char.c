/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-count-char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:26:25 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/20 09:23:10 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>
#include <stdio.h>

static t_map_error	no_char(char letter)
{
	if (letter == 'P'
		|| letter == 'E'
		|| letter == 'F'
		|| letter == 'C'
		|| letter == '0'
		|| letter == '1')
		return (MAP_NO_ERROR);
	return (MAP_INVALID_CHAR);
}

static void	increase_char(t_vi2d *p, char letter)
{
	if (letter == 'P')
		p->x++;
	if (letter == 'E')
		p->y++;
}

t_map_error	verification(t_vi2d *p, int collectable)
{
	if (!collectable)
		return (MAP_NO_COLLECTABLE);
	if (p->y > 1)
		return (MAP_MULTIPLE_EXIT);
	if (p->x > 1)
		return (MAP_MULTIPLE_START_POINT);
	if (!p->y)
		return (MAP_NO_EXIT);
	if (!p->x)
		return (MAP_NO_START_POINT);
	return (MAP_NO_ERROR);
}

t_map_error	map_count_char_error(t_map *map)
{
	t_vi2d	p;
	t_vi2d	q;
	int		c;

	if (!map)
		return (MAP_NOT_CREATED);
	p = vi2d_start(0, 0);
	q = vi2d_start(-1, 0);
	c = 0;
	while (++q.x < map->size->x * map->size->y)
	{
		q.y = *(*(map->data + (q.x / map->size->x)) + (q.x % map->size->x));
		increase_char(&p, q.y);
		if (q.y == 'C')
			c++;
		if (no_char(q.y) != MAP_NO_ERROR)
			return (MAP_INVALID_CHAR);
	}
	return (verification(&p, c));
}
