/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:42:59 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/28 21:18:39 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <stdio.h>

void	philo_set(t_philo *set)
{
	if (!set)
		return ;
	set->hand = 0x3;
}

int	philo_hand(t_philo *set, t_hand hand)
{
	if (!set || !set->hand)
		return (0);
	if (set->hand & (1 << hand))
		return (1);
	return (0);
}

void	philo_status(t_philo *set)
{
	if (!set)
		return ;
	printf("Left hand: %i\n"
		"Right hand: %i\n", philo_hand(set, LEFT_HAND),
		philo_hand(set, RIGHT_HAND));
}
