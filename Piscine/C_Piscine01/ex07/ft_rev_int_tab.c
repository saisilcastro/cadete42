/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:51:46 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/08 17:01:58 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	array[64];
	int	pos;

	pos = size - 1;
	while (pos >= 0)
	{
		array[size - pos - 1] = tab[pos];
		pos--;
	}
	pos = 0;
	while (pos < size)
	{
		tab[pos] = array[pos];
		pos++;
	}
}
