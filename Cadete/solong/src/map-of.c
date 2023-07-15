/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-of.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:50:18 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/14 20:30:17 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>
#include <unistd.h>
#include <fcntl.h>

static void	malloc_length(t_map *map)
{
	int	word;

	map->data = (char **)malloc((map->size->y + 1) * sizeof(char *));
	map->validator = (char **)malloc((map->size->y + 1) * sizeof(char *));
	if (!map->data || !map->validator)
		return ;
	word = 0;
	while (word < map->size->y)
	{
		*(map->data + word)
			= (char *)malloc((map->size->x + 1) * sizeof(char));
		*(map->validator + word)
			= (char *)malloc((map->size->x + 1) * sizeof(char));
		if (*(map->data + word))
			*(*(map->data + word) + map->size->x) = '\0';
		if (*(map->validator + word))
			*(*(map->validator + word) + map->size->x) = '\0';
		word++;
	}
	if (*(map->data + word))
		*(*(map->data + word) + map->size->x) = '\0';
	if (*(map->validator + word))
		*(*(map->validator + word) + map->size->x) = '\0';
	map->pos->y = 0;
}

static void	map_size(t_map *map, char *buffer, int fd)
{
	int	size;

	if (!map || !buffer)
		return ;
	size = read(fd, buffer, 65535);
	map->size->x = 0;
	while (map->size->x < size)
	{
		if (*(buffer + map->size->x) == '\n')
			break ;
		map->size->x++;
	}
	map->size->y = size / map->size->x;
	malloc_length(map);
}

void	word_write(t_map *map, char *buffer, B32 i, B32 word)
{
	if (!map || !buffer)
		return ;
	while (*(buffer + ++i))
	{
		if (*(buffer + i) == 'P')
			map->begin[0] = vi2d_start(map->pos->x, word);
		if (*(buffer + i) == 'C')
			map->collectable += 1;
		if (*(buffer + i) == '\n')
		{
			i++;
			*(*(map->data + word) + map->pos->x) = '\0';
			if (!*(buffer + i))
			{
				*(*(map->data + word) + map->pos->x) = '\0';
				break ;
			}
			map->pos->x = 0;
			word++;
		}
		*(*(map->data + word) + map->pos->x)
			= *(buffer + i);
		map->pos->x++;
	}
	*(map->data + map->size->y) = NULL;
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

void	map_load(t_map *map, char *path)
{
	B32		i;
	B32		word;
	int		fd;
	char	buffer[65535];

	if (!map || !path)
		return ;
	fd = open(path, O_RDONLY);
	map_size(map, buffer, fd);
	i = -1;
	word = 0;
	word_write(map, buffer, i, word);
	collectable_write(map);
	close(fd);
}
