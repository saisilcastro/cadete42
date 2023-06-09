/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:48:29 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/17 14:11:28 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	current;
	int	prime ;

	if (nb == 0 || nb == 1)
		return (0);
	prime = 1;
	current = 1;
	while (++current < nb)
	{
		if (nb % current == 0)
		{
			prime = 0;
			break ;
		}
	}
	return (prime);
}
