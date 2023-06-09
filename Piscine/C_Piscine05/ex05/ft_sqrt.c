/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:48:33 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/22 22:26:10 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int			current;
	long int	square;

	current = 1;
	while (current++)
	{
		square = current * current;
		if (square < __INT_MAX__ && square == nb)
			return (current);
	}
	return (0);
}
