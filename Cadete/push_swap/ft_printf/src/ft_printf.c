/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:15:34 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/22 15:25:48 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <ft_string.h>
#include <ft_itoa_base.h>

static int	print_special(va_list l, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(l, int)));
	if (c == 's')
		return (ft_putstr(va_arg(l, char *)));
	if (c == 'i' || c == 'd')
		return (ft_itoa_base(va_arg(l, int), 10));
	if (c == 'u')
		return (ft_itoa_base_unsigned(va_arg(l, unsigned), 10, c));
	if (c == 'x' || c == 'X')
		return (ft_itoa_base_unsigned(va_arg(l, unsigned int), 16, c));
	if (c == 'p')
		return (ft_itoa_base_ulong(va_arg(l, unsigned long int), 16));
	if (c == 'b')
		return (ft_itoa_base_ulong(va_arg(l, unsigned long int), 2));
	return (ft_putchar('%'));
}

int	ft_printf(char *str, ...)
{
	va_list	l;
	int		len;

	if (!str)
		return (0);
	len = 0;
	va_start(l, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += print_special(l, *str);
			str++;
			if (!*str)
				return (len);
		}
		ft_putchar(*str++);
		len++;
	}
	va_end(l);
	return (len);
}
