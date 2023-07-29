/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate-of.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:28:06 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/26 10:47:34 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rotate_of.h>
#include <swap_of.h>
#include <ft_printf.h>

void	rotate_int(int *set, int size)
{
	int	i;

	if (!set || size < 2)
		return ;
	i = size;
	while (--i > 0)
	{
		if (i == 0)
		 	swap(&set[0], &set[size - 1]);
		else
		 	swap(&set[i - 1], &set[i]);
	}
}

void	reverse_rotate_int(int *set, int size)
{
	int	i;

	if (!set)
		return ;
	i = -1;
	while (++i < size - 1)
	{
		swap(&set[i], &set[i + 1]);
	}
	i = -1;
	while (++i < size)
		ft_printf("%i\n", set[i]);
}
