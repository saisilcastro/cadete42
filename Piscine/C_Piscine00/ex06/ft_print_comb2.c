/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:06:47 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/19 15:39:24 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_int_to_char(int first, int second);

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			ft_int_to_char(first, second);
			second++;
		}
		first++;
	}
}

void	ft_int_to_char(int first, int second)
{
	int	unit;
	int	ten;

	unit = (first % 10) + 48;
	ten = (first / 10) + 48;
	write(1, &ten, 1);
	write(1, &unit, 1);
	write(1, " ", 1);
	unit = (second % 10) + 48;
	ten = (second / 10) + 48;
	write(1, &ten, 1);
	write(1, &unit, 1);
	if (first < 98)
		write(1, ", ", 2);
}
