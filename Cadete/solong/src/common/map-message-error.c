/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-message-error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:54:17 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/19 21:57:12 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>

char	*map_message_error(t_map_error error)
{
	if (error == MAP_NOT_CREATED)
		return ("Error\nmap not created\n");
	else if (error == MAP_INVALID_TOP_BOTTOM)
		return ("Error\nmap invalid top | bottom\n");
	else if (error == MAP_MULTIPLE_START_POINT)
		return ("Error\nmap multiple start point\n");
	else if (error == MAP_NO_EXIT)
		return ("Error\nmap no exit\n");
	else if (error == MAP_NO_START_POINT)
		return ("Error\nmap no start point\n");
	else if (error == MAP_MULTIPLE_EXIT)
		return ("Error\nmap multiple exit\n");
	else if (error == MAP_INVALID_CHAR)
		return ("Error\nmap invalid char\n");
	else if (error == MAP_NO_COLLECTABLE)
		return ("Error\nmap no collectable item\n");
	else if (error == MAP_INVALID_MID_BORDER)
		return ("Error\nmap invalid mid border\n");
	else if (error == MAP_COLLECTABLE_INACCESSIBLE)
		return ("Error\ncollectable inaccessible in the map");
	else if (error == MAP_EXIT_INACCESSIBLE)
		return ("Error\nexit inaccessible in the map");
	return ("map ok");
}
