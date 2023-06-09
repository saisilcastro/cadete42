/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:43:27 by clsilva           #+#    #+#             */
/*   Updated: 2023/03/22 16:08:22 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int d1, int d2, int d3)
{
	write (1, &d1, 1);
	write (1, &d2, 1);
	write (1, &d3, 1);
	if (d1 != 55 || d2 != 56 || d3 != 57)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	a1;
	int	b2;
	int	c3;

	a1 = 48;
	while (a1 <= 57)
	{
	b2 = a1 + 1;
		while (b2 <= 57)
		{
			c3 = b2 + 1;
			while (c3 <= 57)
			{
				ft_print(a1, b2, c3);
		c3++;
			}
	c3 = 48;
	b2++;
		}
	b2 = 48;
	a1++;
	}
}

/*int	main(void)

{
	ft_print_comb();
	return (0);
}*/
