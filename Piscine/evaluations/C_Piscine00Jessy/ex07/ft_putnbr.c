/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:02:46 by jkasmirs          #+#    #+#             */
/*   Updated: 2023/03/10 14:54:22 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

int	main(void)
{
	ft_putnbr(-569);
	return (0);
}

void	ft_putnbr(int nb)
{
	int	update;
	int	pos;
	int	number[16];

	update = nb;
	pos = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		update = -nb;
	}		
	while (update > 0)
	{
		number[pos] = (update % 10);
		update /= 10;
		pos++;
	}
	while (--pos >= 0)
	{
		update = number[pos] + '0';
		write(1, &update, 1);
	}
}
