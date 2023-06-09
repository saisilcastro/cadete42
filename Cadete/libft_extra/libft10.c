/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:36:57 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 12:20:34 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_itoa_base(int nb, unsigned char base, unsigned char upper)
{
	char		multiply;
	static int	len;

	multiply = 1;
	if (nb > -base && nb < 0)
		ft_putchar('-');
	len = 1;
	while (nb <= -base || nb >= base)
	{
		ft_itoa_base(nb / base, base);
		nb %= base;
		len++;
	}
	if (nb < 0)
		multiply = -1;
	if (nb * multiply < 10)
		ft_putchar((nb * multiply) + 48);
	else
	{
		if (!upper)
			ft_putchar((nb * multiply) + 87);
		else
			ft_putchar((nb * multiply) + 55);
	}
	return (len);
}

void	ft_print_special(const char *buffer, va_list list, int *len, int pos)
{
	if (*(buffer + pos) == 'b')
		*len += ft_itoa_base(va_arg(list, int), 2, 0) - 1;
	if (*(buffer + pos) == 'o')
		*len += ft_itoa_base(va_arg(list, int), 8, 0) - 1;
	if (*(buffer + pos) == 'd' || *(buffer + pos) == 'i'
		|| *(buffer + pos) == 'u')
		*len += ft_itoa_base(va_arg(list, int), 10, 0) - 1;
	if (*(buffer + pos) == 'x')
		*len += ft_itoa_base(va_arg(list, int), 16, 0) - 1;
	if (*(buffer + pos) == 'X')
		*len += ft_itoa_base(va_arg(list, int), 16, 1) - 1;
}

int	ft_printf(const char *buffer, ...)
{
	int		pos;
	int		len;
	va_list	list;

	va_start(list, buffer);
	pos = -1;
	len = 0;
	while (*(buffer + pos++))
	{
		if (*(buffer + pos) == '%')
		{
			pos++;
			len--;
			ft_print_special(buffer, list, &len, pos);
		}
		else
			ft_putchar(*(buffer + pos));
	}
	va_end(list);
	return (pos + len);
}
