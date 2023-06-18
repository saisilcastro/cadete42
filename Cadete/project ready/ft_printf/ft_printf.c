/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:30:48 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/13 13:38:08 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

static void	ft_char(va_list list, int *len)
{
	int	letter;

	letter = va_arg(list, int);
	*len += write(1, &letter, 1) - 1;
}

static void	ft_string(va_list list, int *len)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(list, char *);
	if (!str)
		*len += write(1, "(null)", 6) - 1;
	else
	{
		while (*str)
		{
			write(1, str++, 1);
			i++;
		}
		*len += i - 1;
	}
}

static void	ft_pointer(va_list list, int *len)
{
	unsigned long	number;

	number = va_arg(list, unsigned long);
	if (!number)
		*len += write(1, "(nil)", 5) - 1;
	else
		*len += write(1, "0x", 2) + ft_itoa_base_long(number, 16, 0) - 1;
}

void	ft_print_special(const char *buffer, va_list list, int *len, int pos)
{
	if (*(buffer + pos) == 'c')
		ft_char(list, len);
	if (*(buffer + pos) == 's')
		ft_string(list, len);
	if (*(buffer + pos) == 'b')
		*len += ft_itoa_base(va_arg(list, int), 2, 0) - 1;
	if (*(buffer + pos) == 'o')
		*len += ft_itoa_base_unsigned(va_arg(list, int), 8, 0) - 1;
	if (*(buffer + pos) == 'd' || *(buffer + pos) == 'i')
		*len += ft_itoa_base(va_arg(list, int), 10, 1) - 1;
	if (*(buffer + pos) == 'u')
		*len += ft_itoa_base_unsigned(va_arg(list, unsigned int), 10, 0) - 1;
	if (*(buffer + pos) == 'x')
		*len += ft_itoa_base_unsigned(va_arg(list, unsigned int), 16, 0) - 1;
	if (*(buffer + pos) == 'X')
		*len += ft_itoa_base_unsigned(va_arg(list, int), 16, 1) - 1;
	if (*(buffer + pos) == 'p')
		ft_pointer(list, len);
	if (*(buffer + pos) == '%')
		*len += write(1, "%", 1) - 1;
}

int	ft_printf(const char *str, ...)
{
	int		pos;
	int		len;
	va_list	list;

	va_start(list, str);
	pos = -1;
	len = 0;
	while (*(str + ++pos))
	{
		if (*(str + pos) == '%')
		{
			pos++;
			len--;
			ft_print_special(str, list, &len, pos);
		}
		else
			ft_putchar_fd(*(str + pos), 1);
	}
	va_end(list);
	return (pos + len);
}
