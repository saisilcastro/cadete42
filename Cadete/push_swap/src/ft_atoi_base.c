/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 02:25:24 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/23 02:45:12 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_atoi_base.h>
#include <ft_printf.h>

static int	base_get(int base)
{
	if (base == 10)
		return (48);
	return (0);
}

static int	valid_char(char c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

static int	has_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' 
		|| c == 'v' || c == '\f' || c == '\0')
		return (1);
	return (0);
}

int	ft_atoi_base(char *str, int base)
{
	int	number;
	int	mul;

	mul = 1;
	if (!str)
		return (0);
	while (has_space(*str))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			mul = -1;
		str++;
	}
	number = 0;
	while (*str && valid_char(*str))
	{
		number *= base;
		number += (*str - base_get(base));
		str++;
	}
	return (number * mul);
}
