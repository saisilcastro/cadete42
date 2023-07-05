/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:38:43 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/05 16:29:04 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	user_init(t_place *place, void *data)
{
	if (!place || data)
		return ;
	place->image_load_last(place, "img/background/rock.xpm", 0);
	place->map_set(place, 0);
}
