/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-error-message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:54:17 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/19 19:58:30 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>

char	*map_message_error(t_map_error error)
{
	if (error == MAP_NOT_CREATED)
		return ("map not created\n");
	else if (error == MAP_INVALID_TOP_BOTTOM)
		return ("map invalid top | bottom\n");
	else if (error == MAP_MULTIPLE_START_POINT)
		return ("map multiple start point\n");
	else if (error == MAP_NO_EXIT)
		return ("map no exit\n");
	else if (error == MAP_NO_START_POINT)
		return ("map no start point\n");
	else if (error == MAP_MULTIPLE_EXIT)
		return ("map multiple exit\n");
	else if (error == MAP_INVALID_CHAR)
		return ("map invalid char\n");
	else if (error == MAP_NO_COLLECTABLE)
		return ("map no collectable item\n");
	else if (error == MAP_INVALID_MID_BORDER)
		return ("map invalid mid border\n");
	else if (error == MAP_COLLECTABLE_INACCESSIBLE)
		return ("collectable inaccessible in the map");
	else if (error == MAP_EXIT_INACCESSIBLE)
		return ("exit inaccessible in the map");
	return ("map ok");
}
