/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:32:48 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/29 00:48:49 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <life.h>
#include <stdio.h>

void	life_set(t_life *set)
{
	if (!set)
		return ;
	set->man = NULL;
	timer_start(set->timer, 1000);
}

void	life_update(t_life *set)
{
	t_chained	*upd;

	if (!set)
		return ;
	upd = set->man;
	while (upd)
	{
		printf("%i\n", upd->data);
		upd = upd->next;
	}
}

void	life_pop(t_life *set)
{
	if (!set)
		return ;
	chained_pop(&set->man);
}
