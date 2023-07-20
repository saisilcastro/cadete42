/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-of.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:50:18 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/19 18:33:26 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>
#include <unistd.h>
#include <fcntl.h>

static void	word_write(t_map *map, char *buffer)
{
	B32	wd;

	if (!map || !buffer)
		return ;
	wd = 0;
	while (*buffer)
	{
		if (*buffer == 'P')
			map->begin[0] = vi2d_start(map->pos->x, wd);
		if (*buffer == 'C')
			map->collectable++;
		if (*buffer == '\n')
		{
			buffer++;
			*(*(map->data + wd) + map->pos->x) = '\0';
			if (!*buffer)
				break ;
			map->pos->x = 0;
			wd++;
		}
		*(*(map->data + wd) + map->pos->x) = *buffer;
		buffer++;
		map->pos->x++;
	}
}

static void	collectable_write(t_map *map)
{
	B32	i;

	if (!map)
		return ;
	i = -1;
	while (++i < map->size->x * map->size->y)
	{
		*(*(map->validator + (i / map->size->x)) + (i % map->size->x))
		= *(*(map->data + (i / map->size->x)) + (i % map->size->x));
	}
	*(map->validator + map->size->y) = NULL;
}

t_map_error	map_load(t_map *map, char *path)
{
	int			fd;
	char		buffer[65535];

	if (!map || !path)
		return (MAP_NOT_CREATED);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (MAP_INVALID_FILE);
	map_size(map, buffer, fd);
	word_write(map, buffer);
	collectable_write(map);
	close(fd);
	return (MAP_NO_ERROR);
}
