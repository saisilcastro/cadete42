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

	if (!set)
		return ;
	i = -1;
	while (++i < size)
	{
		if (i == 0)
			swap(&set[0], &set[size - 1]);
		else
			swap(&set[i], &set[i - 1]);
	}
	i = -1;
	while (++i < size)
	{
		ft_printf("%i", set[i]);
	}
}

void	reverse_rotate_int(int *set, int size)
{
	int	i;

	if (!set)
		return ;
	i = size;
	while (--i >= 0)
	{
		if (i == size - 1)
			ft_printf("*%d %d\n", 0, set[size - 1]);
		else
			ft_printf("#%i %i\n", size - i - 1, set[size - i - 2]);
	}	
}
