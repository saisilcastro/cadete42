/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:30:52 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/14 20:58:15 by lde-cast         ###   ########.fr       */
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

static void	map_error_msg(t_map_error error)
{
	char	*message;

	message = "map ok\n";
	if (error == MAP_NOT_CREATED)
		message = "map not created\n";
	else if (error == MAP_INVALID_TOP_BOTTOM)
		message = "map invalid top | bottom\n";
	else if (error == MAP_INVALID_MID_BORDER)
		message = "map invalid mid border\n";
	write(1, message, ft_strlen(message));
}

t_map_error	map_validate(t_map *map)
{
	t_map_error	error;

	error = MAP_NO_ERROR;
	if (!map)
		return (MAP_NOT_CREATED);
	error = map_border_validator(map);
	if (error != MAP_NO_ERROR)
	{
		map_error_msg(error);
		return (error);
	}
	error = map_flood_fill(map);
	return (error);
}
