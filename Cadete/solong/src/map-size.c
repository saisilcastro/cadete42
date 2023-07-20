/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:46:46 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/19 23:33:54 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>
#include <unistd.h>

static B8	**matrix_allocate(B32 size)
{
	B8	**matrix;

	matrix = (B8 **)malloc((size + 1) * sizeof(B8 *));
	return (matrix);
}

static void	word_allocate(B8 **word, B32 len)
{
	B32	i;

	*word = (B8 *)malloc((len + 1) * sizeof(B8));
	if (*word)
		return ;
	i = -1;
	while (++i < len)
		*(*word + i) = '\0';
}

static void	malloc_length(t_map *map)
{
	int	word;

	if (!map)
		return ;
	map->data = matrix_allocate(map->size->y);
	map->validator = matrix_allocate(map->size->y);
	word = -1;
	while (++word < map->size->y)
	{
		word_allocate(&*(map->data + word), map->size->x);
		word_allocate(&*(map->validator + word), map->size->x);
	}
	*(map->data + map->size->y) = NULL;
	*(map->validator + map->size->y) = NULL;
}

t_status	valid_width(t_map *map, B8 *buffer)
{
	B32	i;

	(void)map;
	i = 0;
	while (*buffer)
	{
		if (*buffer == '\n')
		{
			buffer++;
			if (i != map->size->x || *buffer == '\n')
				return (Off);
			i = 0;
		}
		buffer++;
		i++;
	}
	return (On);
}

t_status	map_size(t_map *map, B8 *buffer, B32 fd)
{
	B32		size;

	if (!map || !buffer)
		return (Off);
	size = read(fd, buffer, 65535);
	if (size <= 0)
		return (Off);
	map->size->x = 0;
	while (*(buffer + map->size->x) && *(buffer + map->size->x) != '\n')
			map->size->x++;
	map->size->y = size / map->size->x;
	*(buffer + size) = '\0';
	malloc_length(map);
	return (valid_width(map, buffer));
}
