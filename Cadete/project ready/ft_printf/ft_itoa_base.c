/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:31:32 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/13 13:44:09 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_itoa_base.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_itoa_base(int nb, unsigned char base, unsigned char upper)
{
	char		multiply;
	static int	len;

	multiply = 1;
	len = 1;
	if (nb > -base && nb < 0)
		len += ft_putchar_fd('-', 1);
	while (nb <= -base || nb >= base)
	{
		ft_itoa_base((nb / base), base, upper);
		nb %= base;
		len++;
	}
	if (nb < 0)
		multiply = -1;
	if (nb * multiply < 10)
		ft_putchar_fd((nb * multiply) + 48, 1);
	else
	{
		if (!upper)
			ft_putchar_fd((nb * multiply) + 87, 1);
		else
			ft_putchar_fd((nb * multiply) + 55, 1);
	}
	return (len);
}

int	ft_itoa_base_unsigned(unsigned int nb, unsigned char base,
	unsigned char upper)
{
	char		multiply;
	static int	len;

	multiply = 1;
	len = 1;
	while ((int)nb <= -base || nb >= base)
	{
		ft_itoa_base_unsigned((nb / base), base, upper);
		nb %= base;
		len++;
	}
	if ((int)nb < 0)
		multiply = -1;
	if (nb * multiply < 10)
		ft_putchar_fd((nb * multiply) + 48, 1);
	else
	{
		if (!upper)
			ft_putchar_fd((nb * multiply) + 87, 1);
		else
			ft_putchar_fd((nb * multiply) + 55, 1);
	}
	return (len);
}

int	ft_itoa_base_long(unsigned long nb, unsigned char base, unsigned char upper)
{
	char		multiply;
	static int	len;

	multiply = 1;
	len = 1;
	while ((long)nb <= -base || nb >= base)
	{
		ft_itoa_base_long(nb / base, base, upper);
		nb %= base;
		len++;
	}
	if ((long)nb < 0)
		multiply = -1;
	if (nb * multiply < 10)
		ft_putchar_fd((nb * multiply) + 48, 1);
	else
	{
		if (!upper)
			ft_putchar_fd((nb * multiply) + 87, 1);
		else
			ft_putchar_fd((nb * multiply) + 55, 1);
	}
	return (len);
}
