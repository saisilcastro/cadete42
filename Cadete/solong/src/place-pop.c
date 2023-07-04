/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:24:16 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/03 15:26:51 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

void	place_pop(t_place *set)
{
	if (!set)
		return ;
	machine_pop(set->gear);
}
