/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:22:08 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/30 18:44:51 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

void	place_run(t_place *set)
{
	if (!set)
		return ;
	if (set->init)
		set->init(set);
	if (set->pop)
		set->pop(set);
	place_destroy(set);
}
