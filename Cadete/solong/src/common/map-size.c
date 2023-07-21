/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:46:46 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/20 09:24:26 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>
#include <unistd.h>

static char	**matrix_allocate(int size)
{
	char	**matrix;

	matrix = (char **)malloc((size + 1) * sizeof(char *));
	return (matrix);
}

static void	word_allocate(char **word, int len)
{
	int	i;

	*word = (char *)malloc((len + 1) * sizeof(char));
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

t_status	valid_width(t_map *map, char *buffer)
{
	int	i;

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

t_status	map_size(t_map *map, char *buffer, int fd)
{
	int		size;

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
