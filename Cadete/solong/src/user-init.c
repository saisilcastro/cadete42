/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user-init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:38:43 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/03 17:52:17 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	user_init(t_place *place, void *data)
{
	if (!place || data)
		return ;
	place->image_load_last(place, "image", 0);
	place->map_set(place, 0);
}
