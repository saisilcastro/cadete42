/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:30:52 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/19 20:00:14 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>
#include <unistd.h>

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

static t_map_error	border_validator(t_map *map)
{
	t_map_error	error;
	char		*message;

	error = map_border_validator(map);
	if (error != MAP_NO_ERROR)
	{
		message = map_message_error(error);
		write(1, message, ft_strlen(message));
		return (error);
	}
	return (error);
}

t_map_error	map_validate(t_map *map)
{
	t_map_error	error;
	char		*message;

	error = MAP_NO_ERROR;
	if (!map)
		return (MAP_NOT_CREATED);
	if (border_validator(map) != MAP_NO_ERROR)
		return (border_validator(map));
	error = map_count_char_error(map);
	if (error != MAP_NO_ERROR)
	{
		message = map_message_error(error);
		write(1, message, ft_strlen(message));
		return (error);
	}
	if (map->size->x < 5 || map->size->y < 3)
		return (MAP_EMPTY);
	error = map_flood_fill(map);
	if (error != MAP_NO_ERROR)
	{
		message = map_message_error(error);
		write(1, message, ft_strlen(message));
		return (error);
	}
	return (error);
}
