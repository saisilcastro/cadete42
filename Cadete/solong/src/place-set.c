/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:22:54 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/01 17:17:03 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

static void	place_function(t_place *set);

void	place_set(t_place *set, t_SystemSet up, t_vi2d size)
{
	if (!set)
		return ;
	machine_set(set->gear, up, "machine", vi2d_start(size.x, size.y));
	place_function(set);
}

static void	place_function(t_place *set)
{
	if (!set)
		return ;
	set->init = NULL;
	set->run = place_run;
	set->update = NULL;
	set->pop = NULL;
}
