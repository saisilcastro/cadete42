/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stritoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:14:48 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 15:13:00 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	multiply;

	multiply = 1;
	if (n > -10 && n < 0)
		ft_putchar('-');
	while (n <= -10 || n >= 10)
	{
		ft_itoa(n / 10);
		n %= 10;
	}
	if (n < 0)
		multiply = -1;
	return (NULL);
}
