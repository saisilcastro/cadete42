/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:18:09 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 15:13:49 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	multiply;
	char	number;

	multiply = 1;
	if (n > -10 && n < 0)
		write(1, "-", 1);
	while (n <= -10 || n >= 10)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	if (n < 0)
		multiply = -1;
	number = (n * multiply) + 48;
	write(1, &number, 1);
}
