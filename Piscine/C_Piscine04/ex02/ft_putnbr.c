/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:17:46 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/23 13:18:24 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	char		multiply;

	multiply = 1;
	if (nb > -10 && nb < 0)
		write(1, "-", 1);
	if (nb <= -10 || nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb %= 10;
	}
	if (nb < 10 && nb > -10)
	{
		if (nb < 0)
			multiply = -1;
		ft_putchar((nb * multiply) + 48);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
