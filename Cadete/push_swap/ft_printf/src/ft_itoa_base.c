/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:53:53 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/23 02:58:46 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_itoa_base.h>
#include <ft_string.h>

int	ft_itoa_base(int nb, int base)
{
	static int	len;
	int			mul;

	mul = 1;
	len = 1;
	if (base > 10)
		return (0);
	if (nb > -base && nb < 0)
		len = ft_putchar('-');
	while (nb <= -base || nb >= base)
	{
		ft_itoa_base(nb / base, base);
		nb %= base;
		len++;
	}
	if (nb < 0)
		mul = -1;
	ft_putchar((nb * mul) + 48);
	return (len);
}

int	ft_itoa_base_unsigned(unsigned int nb, int base, int upper)
{
	static int	len;

	len = 1;
	while (nb >= (unsigned int)base)
	{
		ft_itoa_base_unsigned(nb / base, base, upper);
		nb %= base;
		len++;
	}
	if (base <= 10 || nb < 10)
		ft_putchar(nb + 48);
	else
	{
		if (upper == 'X')
			ft_putchar(nb + 55);
		else
			ft_putchar(nb + 87);
	}
	return (len);
}

int	ft_itoa_base_ulong(unsigned long int nb, int base)
{
	static int	len;

	len = 1;
	if (nb == 0)
		return (ft_putstr("(nil)"));
	if (base == 16 && nb <= (unsigned long)base)
		len = ft_putstr("0x") + 1;
	while (nb >= (unsigned long)base)
	{
		ft_itoa_base_ulong(nb / base, base);
		nb %= base;
		len++;
	}
	if (base <= 10 || nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putchar(nb + 87);
	}
	return (len);
}
