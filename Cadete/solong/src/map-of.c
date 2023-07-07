/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-of.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:50:18 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/07 19:06:25 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

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
}

void	map_load(char *path)
{
	t_map	map;
	int		fd;
	int		i;
	char	buffer[65535];

	if (!path)
		return ;
	fd = open(path, O_RDONLY);
	map_size(&map, buffer, fd);
	i = 0;
	while (*(buffer + i))
	{
		printf("%c", *(buffer + i));
		i++;
	}
	close(fd);
}
