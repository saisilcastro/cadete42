/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:27:37 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/04 05:35:33 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place.h>

void	place_start(t_place *set)
{
	if (!set)
		return ;
	machine_start(set->gear);
}
