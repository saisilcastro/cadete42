/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer-of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:07:09 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/29 00:09:06 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <timer_of.h>
#include <stdlib.h>
#include <stdio.h>

void	timer_start(t_timer *set, double interval)
{
	if (!set)
		return ;
	set->interval = (double)interval / 1000.0;
	gettimeofday(&set->last, NULL);
}

int	timer_get(t_timer *set)
{
	struct timeval	now;
	double			elapsed;
	double			begin;

	if (!set)
		return (0);
	gettimeofday(&now, NULL);
	begin = (now.tv_sec - set->last.tv_sec);
	elapsed = begin + ((now.tv_usec - set->last.tv_usec) * 1e-6);
	if (elapsed < set->interval)
		return (0);
	timer_set(set);
	return (1);
}

void	timer_set(t_timer *set)
{
	if (!set)
		return ;
	gettimeofday(&set->last, NULL);
}
