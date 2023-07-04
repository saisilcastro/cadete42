/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:36:38 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/03 15:39:02 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

void	place_stop(t_place *set)
{
	if (!set)
		return ;
	set->gear->event &= ~(1 << MACHINE_RUNNING);
}