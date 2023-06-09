/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesuesle <hesuesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:10:05 by hesuesle          #+#    #+#             */
/*   Updated: 2023/03/18 18:01:47 by hesuesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int d1, int d2, int d3)
{
	write(1, &d1, 1);
	write(1, &d2, 1);
	write(1, &d3, 1);
	if (d1 != 55 || d2 != 56 || d3 != 57)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = 48;
	while (a1 <= 57)
	{
		a2 = a1 +1;
		while (a2 <= 57)
		{
			a3 = a2 +1;
			while (a3 <= 57)
			{
				ft_putchar(a1, a2, a3);
						a3++;
			}
			a2++;
		}
	a1++;
	}
}
