/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate-of.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:28:06 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/24 20:36:11 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rotate_of.h>
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
			ft_printf("****%d %d\n", size, set[size - 1]);
		else
			ft_printf("####%i %i\n", i - 1, set[i - 1]);
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
