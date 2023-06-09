/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:33:51 by marvin            #+#    #+#             */
/*   Updated: 2023/03/19 21:17:57 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long int	number;
	char		array[11];
	int		pos;

	number = nb;
	if (nb < 0)
	{
		number = number * -1;
		write(1, "-", 1);
	}
	pos = 0;
	while (number > 0)
	{
		array[pos] = (number % 10) + 48;
		number /= 10;
		pos++;
	}
	while (--pos >= 0)
		write(1, &array[pos], 1);
}
